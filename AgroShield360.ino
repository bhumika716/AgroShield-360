#include <WiFi.h>
#include <WebServer.h>

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
int currentSoilRaw = 0;
int currentMoisture = 0;
int currentRainRaw = 0;
bool currentRainDetected = false;
String currentTankStatus = "UNKNOWN";
String currentDecision = "STARTING";
String currentAlert = "NONE";

void buzzerAlert(String type) {
  if (type == "EMPTY") {
    for (int i = 0; i < 3; i++) {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(200);
      digitalWrite(BUZZER_PIN, LOW);
      delay(200);
    }
  }
  else if (type == "FULL") {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(1000);
    digitalWrite(BUZZER_PIN, LOW);
  }
  else if (type == "CRITICAL") {
    for (int i = 0; i < 3; i++) {
      digitalWrite(BUZZER_PIN, HIGH);
      delay(700);
      digitalWrite(BUZZER_PIN, LOW);
      delay(300);
    }
  }
  else {
    digitalWrite(BUZZER_PIN, LOW);
  }
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
  json += "\"motor\":\"OFF (TEST MODE)\"";
  json += "}";
  server.send(200, "application/json", json);
}

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  Serial.println("AgroShield WiFi Started");
  delay(2000);
  Serial.println(WiFi.softAPIP());
  delay(2000);
  Serial.println("HTTP Server Started");
  delay(2000);
  server.on("/", handleRoot);
  

  server.on("/api/status", handleStatus);
  server.begin();
  Serial.println("HTTP Server Started");

  pinMode(TANK1_PIN, INPUT_PULLUP);
  pinMode(TANK2_PIN, INPUT_PULLUP);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  // Relay remains disabled in TEST MODE
  pinMode(RELAY_PIN, INPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);

  Serial.println("===== AGROSHIELD 360 =====");
  Serial.println("TANK PROTECTION TEST MODE");
}

void loop() {
  int soilRaw = analogRead(SOIL_PIN);
  int rainRaw = analogRead(RAIN_PIN);

  int moisture = map(soilRaw, DRY_RAW, WET_RAW, 0, 100);
  moisture = constrain(moisture, 0, 100);

  bool rainDetected = (rainRaw < RAIN_THRESHOLD);

  int tank1 = digitalRead(TANK1_PIN);
  int tank2 = digitalRead(TANK2_PIN);

  bool tankEmpty = (tank1 == LOW && tank2 == HIGH);
  bool tankFull = (tank1 == HIGH && tank2 == LOW);

  bool irrigationDemand = (moisture < 30);
  bool waterloggingRisk = (rainDetected && moisture > 70);

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
currentAlert = alert;

  if (tankFull) {
    if (alert == "NONE") {
      alert = "TANK FULL - STOP FILLING";
    } else {
      alert += " | TANK FULL - STOP FILLING";
    }
  }
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

  Serial.println("Motor: OFF (TEST MODE)");
  delay(2000);

  server.handleClient();
}
