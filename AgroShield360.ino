#include <WiFi.h>
#include <WebServer.h>
#include "dashboard_html.h"
#include <Preferences.h>

#define BUZZER_PIN 26
#define SOIL_PIN 34
#define RAIN_PIN 35
#define TANK1_PIN 27
#define TANK2_PIN 14

#define RELAY_PIN 23
#define GREEN_LED 18
#define YELLOW_LED 19
#define RED_LED 21

#define DRY_RAW 2906
#define WET_RAW 2101
#define RAIN_THRESHOLD 2500

const char* ssid = "AgroShield_360";
const char* password = "agro360wifi";
WebServer server(80);
Preferences preferences;
int currentSoilRaw = 0;
int currentMoisture = 0;
int currentRainRaw = 0;
bool currentRainDetected = false;
String currentTankStatus = "UNKNOWN";
String currentDecision = "STARTING";
String currentAlert = "NONE";
bool currentMotorOn = false;
unsigned long lastSensorUpdate = 0;

int dryLimitPercent = 30;
int wetLimitPercent = 70;

int calibratedDryRaw = DRY_RAW;
int calibratedWetRaw = WET_RAW;

String currentMode = "AUTO";
String currentLanguage = "English";
bool voiceAlertsEnabled = true;
bool manualMotorCommand = false;
String activeBuzzerType = "OFF";
int buzzerPulsesRemaining = 0;

unsigned long buzzerOnDuration = 0;
unsigned long buzzerOffDuration = 0;
unsigned long buzzerLastChange = 0;

bool buzzerIsOn = false;
bool calibrationActive = false;
bool calibrationWetStage = false;

unsigned long calibrationStart = 0;
unsigned long calibrationLastSample = 0;

long calibrationTotal = 0;
int calibrationCount = 0;
int calibrationDryRaw = 0;

String calibrationStatus = "IDLE";
void loadSettings() {
  preferences.begin("agroshield", false);

  dryLimitPercent = preferences.getInt("dry", 30);
  wetLimitPercent = preferences.getInt("wet", 70);

  calibratedDryRaw = preferences.getInt("dryRaw", DRY_RAW);
  calibratedWetRaw = preferences.getInt("wetRaw", WET_RAW);

  currentMode = preferences.getString("mode", "AUTO");
  currentLanguage = preferences.getString("language", "English");
  voiceAlertsEnabled = preferences.getBool("voice", true);
}

void saveSettings() {
  preferences.putInt("dry", dryLimitPercent);
  preferences.putInt("wet", wetLimitPercent);

  preferences.putInt("dryRaw", calibratedDryRaw);
  preferences.putInt("wetRaw", calibratedWetRaw);

  preferences.putString("mode", currentMode);
  preferences.putString("language", currentLanguage);
  preferences.putBool("voice", voiceAlertsEnabled);
}

void buzzerAlert(String type) {

  if (type == "OFF") {
    activeBuzzerType = "OFF";
    buzzerPulsesRemaining = 0;
    buzzerIsOn = false;
    digitalWrite(BUZZER_PIN, LOW);
    return;
  }

  if (type != activeBuzzerType || buzzerPulsesRemaining == 0) {

    activeBuzzerType = type;
    buzzerIsOn = true;
    buzzerLastChange = millis();

    if (type == "EMPTY") {
      buzzerPulsesRemaining = 3;
      buzzerOnDuration = 200;
      buzzerOffDuration = 200;
    }
    else if (type == "FULL") {
      buzzerPulsesRemaining = 1;
      buzzerOnDuration = 1000;
      buzzerOffDuration = 0;
    }
    else if (type == "CRITICAL") {
      buzzerPulsesRemaining = 3;
      buzzerOnDuration = 700;
      buzzerOffDuration = 300;
    }

    digitalWrite(BUZZER_PIN, HIGH);
  }
}

void updateBuzzer() {

  if (activeBuzzerType == "OFF" ||
      buzzerPulsesRemaining <= 0) {
    return;
  }

  unsigned long duration =
      buzzerIsOn ? buzzerOnDuration : buzzerOffDuration;

  if (millis() - buzzerLastChange < duration) {
    return;
  }
  buzzerLastChange = millis();

  if (buzzerIsOn) {
    digitalWrite(BUZZER_PIN, LOW);
    buzzerIsOn = false;
    buzzerPulsesRemaining--;
  }
  else {
    digitalWrite(BUZZER_PIN, HIGH);
    buzzerIsOn = true;
  }
}

void relayOn() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
}

void relayOff() {
  pinMode(RELAY_PIN, INPUT);
}

void handleRoot() {
  server.send(200, "text/plain", "AgroShield 360 ESP32 is Online!");
}

void handleStatus() {
  String json = "{";
  json += "\"status\":\"online\",";
  json += "\"soilRaw\":" + String(currentSoilRaw) + ",";
  json += "\"moisture\":" + String(currentMoisture) + ",";
  json += "\"rainRaw\":" + String(currentRainRaw) + ",";
  json += "\"rainDetected\":" + String(currentRainDetected ? "true" : "false") + ",";
  json += "\"tankStatus\":\"" + currentTankStatus + "\",";
  json += "\"decision\":\"" + currentDecision + "\",";
  json += "\"alert\":\"" + currentAlert + "\",";
  json += "\"motor\":\"" + String(currentMotorOn ? "ON" : "OFF") + "\",";
  json += "\"mode\":\"" + currentMode + "\",";
  json += "\"dryLimit\":" + String(dryLimitPercent) + ",";
  json += "\"wetLimit\":" + String(wetLimitPercent) + ",";
  json += "\"language\":\"" + currentLanguage + "\",";
  json += "\"voiceAlerts\":" + String(voiceAlertsEnabled ? "true" : "false");
  json += "}";
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", json);
}

String getJsonValue(String body, String key) {
  String searchKey = "\"" + key + "\"";

  int keyIndex = body.indexOf(searchKey);
  if (keyIndex == -1) return "";

  int colonIndex = body.indexOf(':', keyIndex);
  if (colonIndex == -1) return "";

  int start = colonIndex + 1;

  while (start < body.length() && body[start] == ' ') {
    start++;
  }

  int end;

  if (body[start] == '"') {
    start++;
    end = body.indexOf('"', start);
  } 
  else {
    end = body.indexOf(',', start);
    if (end == -1) {
      end = body.indexOf('}', start);
    }
  }

  if (end == -1) return "";

  String value = body.substring(start, end);
  value.trim();

  return value;
}

void handleSettings() {
  String body = server.arg("plain");

  String dry = getJsonValue(body, "dryLimit");
  String wet = getJsonValue(body, "wetLimit");
  String mode = getJsonValue(body, "mode");
  String language = getJsonValue(body, "language");
  String voice = getJsonValue(body, "voiceAlerts");

  int newDry = dry.toInt();
  int newWet = wet.toInt();

  if (dry == "" || wet == "" ||
      newDry < 0 || newDry > 100 ||
      newWet < 0 || newWet > 100 ||
      newWet - newDry < 10 ||
      (mode != "AUTO" && mode != "MANUAL")) {

    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(400, "application/json",
                "{\"success\":false,\"message\":\"Invalid settings\"}");
    return;
  }

  dryLimitPercent = newDry;
  wetLimitPercent = newWet;
  currentMode = mode;

  if (language == "Hindi" || language == "English") {
    currentLanguage = language;
  }

  voiceAlertsEnabled = (voice == "true");
  saveSettings();

  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json",
              "{\"success\":true,\"message\":\"Settings saved\"}");
}

void handleCalibration() {
  String body = server.arg("plain");

  String dry = getJsonValue(body, "dryRaw");
  String wet = getJsonValue(body, "wetRaw");

  if (dry == "" || wet == "") {
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(400, "application/json",
                "{\"success\":false,\"message\":\"Missing calibration values\"}");
    return;
  }

  int newDry = dry.toInt();
  int newWet = wet.toInt();

  if (newDry < 0 || newDry > 4095 ||
      newWet < 0 || newWet > 4095 ||
      newDry - newWet < 10) {

    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(400, "application/json",
                "{\"success\":false,\"message\":\"Invalid calibration values\"}");
    return;
  }

  calibratedDryRaw = newDry;
  calibratedWetRaw = newWet;
  saveSettings();

  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json",
              "{\"success\":true,\"message\":\"Calibration saved\"}");
}

void handleMotor() {
  String body = server.arg("plain");
  String motor = getJsonValue(body, "motor");

  if (motor != "true" && motor != "false") {
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(400, "application/json",
                "{\"success\":false,\"message\":\"Invalid motor command\"}");
    return;
  }

  if (currentMode != "MANUAL") {
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(400, "application/json",
                "{\"success\":false,\"message\":\"Switch to MANUAL mode first\"}");
    return;
  }

  if (motor == "true" &&
      (currentTankStatus == "EMPTY" ||
       currentTankStatus == "INVALID" ||
       currentRainDetected)) {

    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.send(409, "application/json",
                "{\"success\":false,\"message\":\"Safety condition: Motor cannot start\"}");
    return;
  }

  manualMotorCommand = (motor == "true");

  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json",
              "{\"success\":true,\"message\":\"Motor command received\"}");
}

void startCalibration(bool wet) {
  calibrationActive = true;
  calibrationWetStage = wet;
  calibrationStart = millis();
  calibrationLastSample = 0;
  calibrationTotal = 0;
  calibrationCount = 0;
  calibrationStatus = wet ? "WET_RUNNING" : "DRY_RUNNING";
}

void updateCalibration() {
  if (!calibrationActive) return;

  if (millis() - calibrationLastSample >= 500) {
    calibrationTotal += analogRead(SOIL_PIN);
    calibrationCount++;
    calibrationLastSample = millis();
  }

  if (millis() - calibrationStart >= 10000) {
    int averageRaw = calibrationTotal / calibrationCount;
    calibrationActive = false;

    if (!calibrationWetStage) {
      calibrationDryRaw = averageRaw;
      calibrationStatus = "DRY_DONE";
    } else {
      if (calibrationDryRaw - averageRaw >= 100) {
        calibratedDryRaw = calibrationDryRaw;
        calibratedWetRaw = averageRaw;
        saveSettings();
        calibrationStatus = "SUCCESS";
      } else {
        calibrationStatus = "FAILED";
      }
    }
  }
}

void setup() {
  Serial.begin(115200);
  loadSettings();
  WiFi.softAP(ssid, password);
  Serial.println("AgroShield WiFi Started");
  delay(2000);
  Serial.println(WiFi.softAPIP());
  delay(2000);
  Serial.println("HTTP Server Started");
  delay(2000);
  server.on("/", [](){
    server.send_P(200, "text/html", DASHBOARD_HTML);
  });
  

  server.on("/api/status", handleStatus);
  server.on("/api/settings", HTTP_POST, handleSettings);
  server.on("/api/calibrate", HTTP_POST, handleCalibration);
  server.on("/api/calibrate/start", HTTP_POST, []() {
    startCalibration(false);
    server.send(200, "application/json", "{\"status\":\"DRY_RUNNING\"}"); 
  });
  server.on("/api/calibrate/confirm", HTTP_POST, []() {
    startCalibration(true);
    server.send(200, "application/json", "{\"status\":\"WET_RUNNING\"}");
  });
  server.on("/api/calibrate/status", HTTP_GET, []() {
    String json = "{\"status\":\"" + calibrationStatus + "\"}";
    server.send(200, "application/json", json);
  });
  server.on("/api/motor", HTTP_POST, handleMotor);
  server.begin();
  Serial.println("HTTP Server Started");

  pinMode(TANK1_PIN, INPUT_PULLUP);
  pinMode(TANK2_PIN, INPUT_PULLUP);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  // Relay initially OFF
  relayOff();

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);

  Serial.println("===== AGROSHIELD 360 =====");
  Serial.println("AUTOMATIC IRRIGATION MODE");
}

void loop() {
  updateCalibration();
  server.handleClient();
  updateBuzzer();
  if (millis() - lastSensorUpdate < 2000) return;
  lastSensorUpdate = millis();

  int soilRaw = analogRead(SOIL_PIN);
  int rainRaw = analogRead(RAIN_PIN);

  int moisture = map(soilRaw, calibratedDryRaw, calibratedWetRaw, 0, 100);
  moisture = constrain(moisture, 0, 100);

  bool rainDetected = (rainRaw < RAIN_THRESHOLD);

  int tank1 = digitalRead(TANK1_PIN);
  int tank2 = digitalRead(TANK2_PIN);

  bool tankEmpty = (tank1 == LOW && tank2 == HIGH);
  bool tankFull = (tank1 == HIGH && tank2 == LOW);

  bool irrigationDemand = (moisture < dryLimitPercent);
  bool waterloggingRisk = (rainDetected && moisture > wetLimitPercent);

  String decision = "NO IRRIGATION";
  String alert = "NONE";

  if (tankEmpty) {
  decision = "MOTOR OFF";
  alert = "TANK EMPTY - DRY RUN RISK";
  }
  else if (waterloggingRisk) {
  decision = "MOTOR OFF";
  alert = "WATERLOGGING RISK";
  }
  else if (rainDetected) {
  decision = "MOTOR OFF";
  alert = "RAIN DETECTED";
  }
  else if (irrigationDemand) {
  decision = "IRRIGATION REQUIRED";
  alert = "SOIL DRY";
  }
  else {
  decision = "SOIL MOISTURE OK";
  alert = "NONE";
  }

  currentSoilRaw = soilRaw;
  currentMoisture = moisture;
  currentRainRaw = rainRaw;
  currentRainDetected = rainDetected;
  if (tankEmpty) {
    currentTankStatus = "EMPTY";
  }
  else if (tankFull) {
  currentTankStatus = "FULL";
  }
  else if (tank1 == HIGH && tank2 == HIGH) {
    currentTankStatus = "MIDDLE";
  }
  else {
    currentTankStatus = "INVALID";
  }
  currentDecision = decision;

  // AUTO / MANUAL MOTOR CONTROL
  if (currentMode == "MANUAL")
  {

    bool manualAllowed =
        currentTankStatus != "EMPTY" &&
        currentTankStatus != "INVALID" &&
        !currentRainDetected;

    if (manualMotorCommand && manualAllowed)
    {
      relayOn();
      currentMotorOn = true;
    }
    else
    {
      relayOff();
      currentMotorOn = false;
    }
  }
  else
  {

    manualMotorCommand = false;

    if (decision == "IRRIGATION REQUIRED")
    {
      relayOn();
      currentMotorOn = true;
    }
    else
    {
      relayOff();
      currentMotorOn = false;
    }
  }

  if (tankFull) {
    if (alert == "NONE") {
      alert = "TANK FULL - STOP FILLING";
    } else {
      alert += " | TANK FULL - STOP FILLING";
    }
  }

  currentAlert = alert;

  if (tankEmpty) {
    buzzerAlert("EMPTY");
  }
  else if (waterloggingRisk) {
    buzzerAlert("CRITICAL");
  }
  else if (tankFull) {
    buzzerAlert("FULL");
  }
  else {
    buzzerAlert("OFF");
  }

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);

  if (tankEmpty || tankFull || waterloggingRisk) {
    digitalWrite(RED_LED, HIGH);
  }
  else if (irrigationDemand && !rainDetected) {
    digitalWrite(YELLOW_LED, HIGH);
  }
  else {
    digitalWrite(GREEN_LED, HIGH);
  }

  Serial.println("----------------------------");

  Serial.print("Soil Raw: ");
  Serial.println(soilRaw);

  Serial.print("Moisture: ");
  Serial.print(moisture);
  Serial.println("%");

  Serial.print("Rain: ");
  Serial.println(rainDetected ? "DETECTED" : "DRY");

  Serial.print("Tank 1: ");
  Serial.println(tank1 == LOW ? "CLOSED" : "OPEN");

  Serial.print("Tank 2: ");
  Serial.println(tank2 == LOW ? "CLOSED" : "OPEN");

  Serial.print("Tank Status: ");
  if (tankEmpty) Serial.println("EMPTY");
  else if (tankFull) Serial.println("FULL");
  else if (tank1 == HIGH && tank2 == HIGH) Serial.println("MIDDLE");
  else Serial.println("INVALID / CHECK SWITCHES");

  Serial.print("Decision: ");
  Serial.println(decision);

  Serial.print("Alert: ");
  Serial.println(alert);

  Serial.print("Motor: ");
  Serial.println(currentMotorOn ? "ON" : "OFF");

}
