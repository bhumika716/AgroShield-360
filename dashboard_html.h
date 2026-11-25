// Auto-generated from dashboard/index.html - do not edit by hand
#pragma once
#include <pgmspace.h>
const char DASHBOARD_HTML[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>AgroShield 360</title>
<style>
:root{--g1:#1f6b35;--g2:#2e8b45;--g3:#e6f4e4;--ink:#17331f;--mut:#5d7565;--red:#c9372c;--redbg:#fde5e2;--blue:#1f6fb5;--bluebg:#e0eefb;--ambbg:#fff1c9;--card:#f6fbf4}
*{box-sizing:border-box;margin:0;-webkit-tap-highlight-color:transparent}
body{font-family:system-ui,-apple-system,"Segoe UI","Noto Sans Devanagari",Roboto,sans-serif;background:#cfe5cb;color:var(--ink);min-height:100vh;display:flex;justify-content:center}
#app{width:100%;max-width:460px;min-height:100vh;background:var(--g3);position:relative;padding-bottom:84px}
.hero{height:190px;position:relative;color:#fff;padding:14px 16px;background:
 radial-gradient(ellipse 60% 40% at 25% 100%,#4b9a4f 60%,transparent 61%),
 radial-gradient(ellipse 70% 45% at 80% 105%,#3b8643 60%,transparent 61%),
 linear-gradient(180deg,#8fd0f0 0%,#d4f0f7 45%,#7fc16b 46%,#4e9f45 100%)}
.hero::after{content:"";position:absolute;left:62%;top:78px;width:46px;height:30px;background:#c4452f;clip-path:polygon(0 40%,50% 0,100% 40%,100% 100%,0 100%)}
.top{display:flex;align-items:center;gap:10px;position:relative;z-index:2}
.logo{font-size:30px}
.top h1{font-size:21px;line-height:1.1;text-shadow:0 1px 3px #0006}
.top small{font-size:11px;text-shadow:0 1px 2px #0007}
.badge{margin-left:auto;font-size:12px;font-weight:600;padding:5px 10px;border-radius:99px;background:var(--g1);color:#fff}
.badge.off{background:#f5d142;color:#4a3a00}
.gear{background:none;border:0;font-size:22px;cursor:pointer;filter:drop-shadow(0 1px 2px #0006)}
.greet{position:absolute;left:16px;bottom:14px;z-index:2;text-shadow:0 1px 4px #0008}
.greet b{font-size:22px;display:block}
.greet span{font-size:13px}
main{padding:12px;margin-top:-6px}
.screen{display:none}.screen.on{display:block}
.grid{display:grid;grid-template-columns:1fr 1fr;gap:10px}
.card{background:var(--card);border-radius:16px;padding:12px 8px;text-align:center;border:1px solid #d3e8d0;box-shadow:0 2px 6px #1f6b3512}
.card .ic{font-size:30px}
.card h3{font-size:13px;font-weight:600;color:var(--mut)}
.card .val{font-size:24px;font-weight:700;margin:2px 0 6px}
.pill{display:inline-block;font-size:12px;padding:3px 10px;border-radius:99px;font-weight:600;background:#d8f0d4;color:var(--g1)}
.card.warn{background:var(--redbg);border-color:#f2b8b1}.card.warn .pill{background:#fbc9c4;color:var(--red)}
.card.info{background:var(--bluebg);border-color:#b7d4ee}.card.info .pill{background:#c6dff6;color:var(--blue)}
.panel{background:var(--card);border-radius:16px;padding:12px;margin-top:10px;border:1px solid #d3e8d0}
.pump{display:flex;align-items:center;gap:10px}
.pump .ic{font-size:28px}
.pump div{flex:1}.pump b{font-size:14px}.pump p{font-size:12px;color:var(--mut)}
.btn{border:0;border-radius:99px;padding:10px 16px;font-weight:700;font-size:14px;cursor:pointer;background:var(--g1);color:#fff}
.btn.grey{background:#8a8f8c}.btn.red{background:var(--red)}.btn:disabled{opacity:.55;cursor:not-allowed}
.btn.amb{background:#f5d142;color:#4a3a00}
.alert{margin-top:10px;border-radius:14px;padding:12px 14px;background:#ffe9c2;border-left:6px solid #e89a1a}
.alert b{display:block;font-size:15px}.alert span{font-size:13px}
.alert.ok{background:#e1f5dc;border-color:var(--g2)}
.alert.bad{background:var(--redbg);border-color:var(--red)}
.alert.info{background:var(--bluebg);border-color:var(--blue)}
.alert.warn{background:var(--ambbg);border-color:#e89a1a}
nav{position:fixed;bottom:0;width:100%;max-width:460px;display:flex;background:#fff;border-top:1px solid #cfe2cc;padding:6px 0 10px}
nav button{flex:1;background:none;border:0;font-size:11px;color:var(--mut);cursor:pointer;padding:4px}
nav button span{display:block;font-size:20px}
nav button.on{color:var(--g1);font-weight:700}
h2{font-size:18px;margin:4px 2px 8px}
.sec{font-weight:700;font-size:14px;margin-bottom:8px}
.row{display:flex;align-items:center;gap:10px;margin:8px 0;font-size:14px}
.row label{width:84px;font-weight:600}
.row input[type=range]{flex:1;accent-color:var(--g1)}
.row output{width:44px;text-align:right;font-weight:700}
.seg{display:flex;gap:8px}
.seg button{flex:1;padding:9px;border-radius:99px;border:1px solid #bcd6b8;background:#eef5ec;font-weight:600;cursor:pointer}
.seg button.on{background:var(--g1);color:#fff;border-color:var(--g1)}
.note{font-size:12px;color:var(--mut);margin-top:6px}
.sw{width:50px;height:28px;border-radius:99px;background:#9aa;border:0;position:relative;cursor:pointer}
.sw::after{content:"";position:absolute;top:3px;left:3px;width:22px;height:22px;border-radius:50%;background:#fff;transition:.2s}
.sw.on{background:var(--g1)}.sw.on::after{left:25px}
.between{display:flex;justify-content:space-between;align-items:center;gap:10px}
.save{width:100%;margin-top:12px;padding:14px;font-size:16px;border-radius:14px}
.prog{height:12px;border-radius:99px;background:#d3e8d0;margin-top:10px;overflow:hidden}
.prog div{height:100%;width:0;background:var(--g2)}
.calmsg{font-size:14px;margin-top:10px;font-weight:600}
.calmsg.ok{color:var(--g1)}.calmsg.bad{color:var(--red)}
.modal{display:none;position:fixed;inset:0;background:#000a;z-index:20;align-items:center;justify-content:center;padding:16px}
.mbox{background:#fff;border-radius:18px;padding:20px 18px;max-width:420px;width:100%;position:relative}
.mbox h2{margin:0 28px 10px 0}
.mbox ol{padding-left:20px;font-size:14px;line-height:1.6}
.x{position:absolute;top:10px;right:12px;border:0;background:#e6efe4;border-radius:50%;width:32px;height:32px;font-size:16px;cursor:pointer}
#toast{position:fixed;left:50%;bottom:96px;transform:translateX(-50%);background:#222;color:#fff;padding:10px 16px;border-radius:99px;font-size:13px;opacity:0;pointer-events:none;transition:.3s;z-index:30;max-width:90%;text-align:center}
#toast.on{opacity:1}
.demo button{margin:3px 3px 0 0;padding:7px 10px;font-size:12px}
@media (prefers-reduced-motion:reduce){*{transition:none!important}}
</style>
</head>
<body>
<div id="app">
 <header class="hero">
  <div class="top">
   <div class="logo">🌱</div>
   <div><h1>AgroShield 360</h1><small data-i="tag"></small></div>
   <div class="badge" id="conn"></div>
   <button class="gear" onclick="go('settings')" aria-label="Settings">⚙️</button>
  </div>
  <div class="greet"><b data-i="hello"></b><span data-i="glance"></span></div>
 </header>

 <main>
  <!-- HOME -->
  <section class="screen on" id="s-home">
   <div class="grid">
    <div class="card" id="c-soil"><div class="ic">💧</div><h3 data-i="moisture"></h3><div class="val" id="v-soil">--</div><span class="pill" id="p-soil">--</span></div>
    <div class="card" id="c-tank"><div class="ic">🛢️</div><h3 data-i="tank"></h3><div class="val" id="v-tank">--</div><span class="pill" id="p-tank">--</span></div>
    <div class="card" id="c-rain"><div class="ic">🌧️</div><h3 data-i="rain"></h3><div class="val" id="v-rain">--</div><span class="pill" id="p-rain">--</span></div>
    <div class="card" id="c-motor"><div class="ic">⚙️</div><h3 data-i="motor"></h3><div class="val" id="v-motor">--</div><span class="pill" id="p-motor">--</span></div>
   </div>
   <div class="panel pump">
    <div class="ic">🚰</div>
    <div><b data-i="pumpCtl"></b><p id="pump-note"></p></div>
    <button class="btn" id="b-on" onclick="motor(true)">ON</button>
    <button class="btn grey" id="b-off" onclick="motor(false)">OFF</button>
   </div>
   <div class="panel between">
    <b style="font-size:14px" data-i="mode"></b>
    <div class="seg" style="width:62%"><button id="hm-AUTO" onclick="setModeNow('AUTO')" data-i="auto"></button><button id="hm-MANUAL" onclick="setModeNow('MANUAL')" data-i="manual"></button></div>
   </div>
   <div id="alerts"></div>
   <div class="panel demo" id="demo-bar" style="display:none">
    <div class="sec">Demo mode (no ESP32)</div>
    <button class="btn grey" onclick="scn({moisture:62,tank:'MIDDLE',rain:false})">Normal</button>
    <button class="btn grey" onclick="scn({moisture:25,tank:'MIDDLE',rain:false})">Dry soil</button>
    <button class="btn grey" onclick="scn({moisture:25,tank:'FULL',rain:false})">Full + dry</button>
    <button class="btn grey" onclick="scn({moisture:55,tank:'EMPTY',rain:false})">Tank empty</button>
    <button class="btn grey" onclick="scn({moisture:50,tank:'MIDDLE',rain:true})">Rain</button>
    <button class="btn grey" onclick="scn({moisture:80,tank:'MIDDLE',rain:true})">Rain + wet</button>
    <button class="btn grey" onclick="scn({moisture:50,tank:'INVALID',rain:false})">Switch fault</button>
   </div>
  </section>

  <!-- SETTINGS -->
  <section class="screen" id="s-settings">
   <h2 data-i="settings"></h2>
   <div class="panel">
    <div class="sec" data-i="s1"></div>
    <div class="row"><label data-i="dry"></label><input type="range" id="dry" min="5" max="90"><output id="dry-o"></output></div>
    <div class="row"><label data-i="wet"></label><input type="range" id="wet" min="10" max="95"><output id="wet-o"></output></div>
    <div class="note" data-i="limNote"></div>
   </div>
   <div class="panel">
    <div class="sec" data-i="s2"></div>
    <div class="seg"><button id="m-AUTO" onclick="setFormMode('AUTO')" data-i="auto"></button><button id="m-MANUAL" onclick="setFormMode('MANUAL')" data-i="manual"></button></div>
    <div class="note" data-i="modeNote"></div>
   </div>
   <div class="panel">
    <div class="sec" data-i="s3"></div>
    <div class="seg"><button id="l-en" onclick="setLang('en')">English</button><button id="l-hi" onclick="setLang('hi')">हिंदी</button></div>
   </div>
   <div class="panel">
    <div class="between"><div class="sec" data-i="s4" style="margin:0"></div><button class="sw" id="sw-voice" onclick="toggleVoice()" aria-label="Voice alerts"></button></div>
   </div>
   <div class="panel">
    <div class="between"><div class="sec" data-i="s5" style="margin:0"></div><button class="btn amb" onclick="openModal()" data-i="calibrate"></button></div>
    <div id="cal" style="display:none">
     <div class="calmsg" id="cal-msg"></div>
     <div class="prog" id="cal-prog" style="display:none"><div id="cal-bar"></div></div>
     <button class="btn save" id="cal-btn" onclick="calAction()"></button>
    </div>
   </div>
   <button class="btn save" onclick="saveSettings()">💾 <span data-i="save"></span></button>
   <div class="note" style="text-align:center" data-i="saveNote"></div>
  </section>
 </main>

 <nav>
  <button class="on" id="n-home" onclick="go('home')"><span>🏠</span><i data-i="home" style="font-style:normal"></i></button>
  <button id="n-settings" onclick="go('settings')"><span>⚙️</span><i data-i="settings" style="font-style:normal"></i></button>
 </nav>

 <!-- Calibration instructions: stays open until the X is pressed -->
 <div class="modal" id="modal">
  <div class="mbox">
   <button class="x" onclick="closeModal()" aria-label="Close">✕</button>
   <h2 data-i="calTitle"></h2>
   <ol><li data-i="calI1"></li><li data-i="calI2"></li><li data-i="calI3"></li><li data-i="calI4"></li></ol>
  </div>
 </div>
 <div id="toast"></div>
</div>

<script>
/* ---------- Config ---------- */
// Opened as a file on a laptop: read live data from the ESP32 hotspot address.
// (Saving settings / motor / calibration only works when the page is opened from http://192.168.4.1)
const BASE = location.protocol === 'file:' ? 'http://192.168.4.1' : '';
const POLL_MS = 2000;

/* ---------- Text (English / Hindi) ---------- */
const TXT = {
en:{tag:'Smart Farming Made Simple',hello:'Namaste, Farmer! 👋',glance:'Your farm status at a glance',
 moisture:'Soil Moisture',tank:'Water Tank',rain:'Rain Status',motor:'Motor Status',
 home:'Home',settings:'Settings',connected:'Connected',disc:'Not connected',
 optimal:'Optimal',dryS:'Soil is Dry',wetS:'Soil is Wet',avail:'Available',full:'Full',empty:'Empty',
 water:'Water Present',stopFill:'Stop Filling',refill:'Refill Water',sensorFault:'Check Switches',unknown:'Unknown',
 noRain:'No Rain',rainY:'Rain Detected',normal:'Normal',paused:'Motor Paused',
 on:'ON',off:'OFF',ready:'Ready',active:'Irrigation Active',dueRain:'Due to Rain',tankEmptyP:'Tank Empty',
 pumpCtl:'Water Pump Control',pAuto:'Automatic mode. Switch to Manual to control the pump.',pMan:'Control the motor manually if needed.',pUnsafe:'Pump is blocked for safety.',
 mode:'Mode',
 aOkT:'All Systems Normal',aOkM:'Happy Farming! 🌱',aDryT:'Low Soil Moisture!',aDryM:'Irrigation is running.',aDryM2:'Soil is dry. Irrigation starts when it is safe.',
 aFullT:'Tank is Full - Stop Filling',aFullM:'Irrigation can still continue.',aEmptyT:'Tank Empty - Dry Run Risk',aEmptyM:'Motor is OFF. Please refill the water tank.',
 aRainT:'Rain Detected',aRainM:'Motor stopped for safety.',aWlT:'Waterlogging Risk!',aWlM:'Rain with wet soil. Motor is OFF.',
 aFaultT:'Tank Switch Fault!',aFaultM:'Check the float switches. Motor cannot start manually.',aDiscT:'Not Connected',aDiscM:'Join the AgroShield_360 Wi-Fi network.',
 s1:'1. Soil Moisture Limits',dry:'Dry Limit',wet:'Wet Limit',limNote:'Motor turns ON below Dry Limit and OFF when soil is wetter than Wet Limit.',
 s2:'2. Irrigation Mode',auto:'Automatic',manual:'Manual',modeNote:'Automatic mode uses sensors to control the motor. Safety rules always apply.',
 s3:'3. Language',s4:'4. Voice Alerts',s5:'5. Sensor Calibration',calibrate:'Calibrate',
 save:'Save Settings',saveNote:'Settings will be saved in ESP32 memory.',saved:'Settings saved',failed:'Could not reach ESP32',
 badLim:'Wet Limit must be at least 10% above Dry Limit',cmdFail:'Motor command refused',cmdOk:'Motor command sent',voiceTest:'Voice alerts are on.',
 calTitle:'Soil Sensor Calibration',
 calI1:'First, insert the sensor into dry soil.',calI2:'Wait for the dry calibration (about 10 seconds).',calI3:'Then moisten the soil well and insert the sensor again.',calI4:'Confirm when ready.',
 calReady:'Put the sensor in dry soil, then tap Start Calibration.',calStart:'Start Calibration',
 calDryRun:'Reading dry soil... keep the sensor still.',calDryDone:'Dry reading done. Now moisten the soil well and insert the sensor again.',calConfirm:'Confirm Wet Soil',
 calWetRun:'Reading wet soil... keep the sensor still.',calOk:'Calibration Successful',calOkM:'New calibration values have been saved.',
 calFail:'Calibration Failed',calFailM:'Please repeat with properly dry soil first, then well-moistened soil.',calRetry:'Try Again',calErr:'Calibration request failed. Check the connection.'},
hi:{tag:'स्मार्ट खेती, आसान तरीका',hello:'नमस्ते, किसान भाई! 👋',glance:'आपके खेत की स्थिति एक नज़र में',
 moisture:'मिट्टी की नमी',tank:'पानी की टंकी',rain:'बारिश की स्थिति',motor:'मोटर की स्थिति',
 home:'होम',settings:'सेटिंग्स',connected:'जुड़ा हुआ',disc:'जुड़ा नहीं',
 optimal:'बिल्कुल सही',dryS:'मिट्टी सूखी है',wetS:'मिट्टी गीली है',avail:'उपलब्ध',full:'भरी हुई',empty:'खाली',
 water:'पानी है',stopFill:'भरना बंद करें',refill:'पानी भरें',sensorFault:'स्विच जाँचें',unknown:'अज्ञात',
 noRain:'बारिश नहीं',rainY:'बारिश हो रही है',normal:'सामान्य',paused:'मोटर रुकी है',
 on:'चालू',off:'बंद',ready:'तैयार',active:'सिंचाई चालू',dueRain:'बारिश के कारण',tankEmptyP:'टंकी खाली',
 pumpCtl:'पानी पंप नियंत्रण',pAuto:'ऑटोमैटिक मोड है। पंप चलाने के लिए मैन्युअल चुनें।',pMan:'ज़रूरत हो तो मोटर हाथ से चलाएँ।',pUnsafe:'सुरक्षा के लिए पंप रुका है।',
 mode:'मोड',
 aOkT:'सब कुछ सामान्य है',aOkM:'खुशहाल खेती! 🌱',aDryT:'मिट्टी में नमी कम है!',aDryM:'सिंचाई चल रही है।',aDryM2:'मिट्टी सूखी है। सुरक्षित होने पर सिंचाई शुरू होगी।',
 aFullT:'टंकी भरी है - भरना बंद करें',aFullM:'सिंचाई फिर भी चल सकती है।',aEmptyT:'टंकी खाली - पंप सूखा चलने का खतरा',aEmptyM:'मोटर बंद है। कृपया टंकी में पानी भरें।',
 aRainT:'बारिश हो रही है',aRainM:'सुरक्षा के लिए मोटर बंद की गई।',aWlT:'जलभराव का खतरा!',aWlM:'बारिश और गीली मिट्टी। मोटर बंद है।',
 aFaultT:'टंकी स्विच में खराबी!',aFaultM:'फ्लोट स्विच जाँचें। मोटर हाथ से शुरू नहीं हो सकती।',aDiscT:'जुड़ा नहीं है',aDiscM:'AgroShield_360 वाई-फाई से जुड़ें।',
 s1:'1. नमी की सीमाएँ',dry:'सूखी सीमा',wet:'गीली सीमा',limNote:'सूखी सीमा से नीचे मोटर चालू होती है और मिट्टी गीली सीमा से ज़्यादा गीली होने पर बंद।',
 s2:'2. सिंचाई मोड',auto:'ऑटोमैटिक',manual:'मैन्युअल',modeNote:'ऑटोमैटिक मोड में सेंसर मोटर चलाते हैं। सुरक्षा नियम हमेशा लागू रहते हैं।',
 s3:'3. भाषा',s4:'4. आवाज़ अलर्ट',s5:'5. सेंसर कैलिब्रेशन',calibrate:'कैलिब्रेट',
 save:'सेटिंग्स सेव करें',saveNote:'सेटिंग्स ESP32 की मेमोरी में सेव होंगी।',saved:'सेटिंग्स सेव हो गईं',failed:'ESP32 से संपर्क नहीं हो पाया',
 badLim:'गीली सीमा, सूखी सीमा से कम से कम 10% ज़्यादा होनी चाहिए',cmdFail:'मोटर का आदेश अस्वीकार हुआ',cmdOk:'मोटर का आदेश भेजा गया',voiceTest:'आवाज़ अलर्ट चालू हैं।',
 calTitle:'मिट्टी सेंसर कैलिब्रेशन',
 calI1:'सबसे पहले सेंसर को सूखी मिट्टी में डालें।',calI2:'सूखे कैलिब्रेशन के लिए लगभग 10 सेकंड रुकें।',calI3:'फिर मिट्टी को अच्छी तरह गीला करें और सेंसर दोबारा डालें।',calI4:'तैयार होने पर पुष्टि करें।',
 calReady:'सेंसर को सूखी मिट्टी में रखें, फिर कैलिब्रेशन शुरू करें दबाएँ।',calStart:'कैलिब्रेशन शुरू करें',
 calDryRun:'सूखी मिट्टी की रीडिंग ली जा रही है... सेंसर को स्थिर रखें।',calDryDone:'सूखी रीडिंग हो गई। अब मिट्टी को अच्छी तरह गीला करें और सेंसर दोबारा डालें।',calConfirm:'गीली मिट्टी की पुष्टि करें',
 calWetRun:'गीली मिट्टी की रीडिंग ली जा रही है... सेंसर को स्थिर रखें।',calOk:'कैलिब्रेशन सफल रहा',calOkM:'नए कैलिब्रेशन मान सेव हो गए हैं।',
 calFail:'कैलिब्रेशन विफल रहा',calFailM:'कृपया पहले अच्छी तरह सूखी मिट्टी और फिर अच्छी तरह गीली मिट्टी के साथ दोबारा करें।',calRetry:'दोबारा कोशिश करें',calErr:'कैलिब्रेशन अनुरोध विफल रहा। कनेक्शन जाँचें।'}
};

/* ---------- State ---------- */
// Field names follow the firmware's /api/status response.
let S = {moisture:0,tank:'UNKNOWN',rain:false,motor:false,mode:'AUTO',dryLimit:30,wetLimit:70,alert:'NONE',raw:0};
let lang = localStorage.getItem('lang') || 'en';
let voiceOn = localStorage.getItem('voice') !== 'off';
let online = false, demo = false, cfgLoaded = false, lastSig = '', formMode = 'AUTO';
let pend = null; // pump command just sent; shown until the ESP32 confirms it
let calStep = 'idle', calTimer = null, calT0 = 0, calErr = false;
const $ = id => document.getElementById(id);
const t = k => (TXT[lang][k] ?? k);

/* ---------- Helpers ---------- */
function toast(m){const e=$('toast');e.textContent=m;e.classList.add('on');clearTimeout(toast.h);toast.h=setTimeout(()=>e.classList.remove('on'),2800);}
async function api(path, body){
  if(demo) return mockApi(path, body);
  const c=new AbortController(), id=setTimeout(()=>c.abort(),5000);
  try{
    const o={signal:c.signal};
    if(body!==undefined){o.method='POST';o.headers={'Content-Type':'application/json'};o.body=JSON.stringify(body);}
    const r=await fetch(BASE+path,o);
    const d=await r.json().catch(()=>({}));
    if(!r.ok||d.success===false){const e=new Error(d.message||String(r.status));e.status=r.status;throw e;}
    return d;
  } finally { clearTimeout(id); }
}
const VOICE_REPEATS = 5;     // each alert is spoken this many times
let speechOK = false, unlocked = false, keepRef = [];
function stopSpeech(){ if('speechSynthesis' in window) speechSynthesis.cancel(); }
function speak(text, force, times){
  if((!voiceOn && !force) || !('speechSynthesis' in window)) return;
  speechSynthesis.cancel();           // a new alert replaces the old one
  const n=times||VOICE_REPEATS; keepRef=[];
  for(let i=0;i<n;i++){               // queue all repeats at once (no timers, most reliable)
    const u=new SpeechSynthesisUtterance(text);
    u.lang = lang==='hi'?'hi-IN':'en-IN';
    u.rate=0.85; u.volume=1;          // slower + full volume = clearer
    u.onstart=()=>{ speechOK=true; };
    keepRef.push(u);                  // keep a reference so the browser does not drop it
    speechSynthesis.speak(u);
  }
}
// Phone browsers block sound until the page has been tapped once.
// On the first tap we unlock speech, and if the current alert was never heard we say it now.
function unlockSpeech(){
  if(unlocked) return; unlocked=true;
  if(voiceOn && !speechOK){ lastSig=''; setTimeout(render,100); }
}
['pointerdown','touchstart','keydown'].forEach(ev=>document.addEventListener(ev,unlockSpeech,{once:true,passive:true}));

/* ---------- Safety display logic (the ESP32 is the real authority) ---------- */
// FULL is only a "stop filling" warning. It never blocks the motor.
function unsafe(){return S.tank==='EMPTY' || S.tank==='INVALID' || S.rain;}

function getAlerts(){
  if(!online && !demo) return [{c:'warn',t:t('aDiscT'),m:t('aDiscM')}];
  const out=[]; let full=S.tank==='FULL';
  String(S.alert||'').split('|').map(x=>x.trim().toUpperCase()).forEach(p=>{
    if(p.startsWith('TANK EMPTY')) out.push({c:'bad',t:t('aEmptyT'),m:t('aEmptyM')});
    else if(p.startsWith('WATERLOGGING')) out.push({c:'bad',t:t('aWlT'),m:t('aWlM')});
    else if(p==='RAIN DETECTED') out.push({c:'info',t:t('aRainT'),m:t('aRainM')});
    else if(p==='SOIL DRY') out.push({c:'bad',t:t('aDryT'),m:S.motor?t('aDryM'):t('aDryM2')});
    else if(p.startsWith('TANK FULL')) full=true;
    else if(p && p!=='NONE') out.push({c:'warn',t:p,m:''});
  });
  if(S.tank==='INVALID') out.push({c:'bad',t:t('aFaultT'),m:t('aFaultM')});
  if(full) out.push({c:'info',t:t('aFullT'),m:t('aFullM')});
  if(!out.length) out.push({c:'ok',t:t('aOkT'),m:t('aOkM')});
  return out;
}

/* ---------- Render ---------- */
function setCard(id, cls, val, pill){
  $('c-'+id).className='card '+cls; $('v-'+id).textContent=val; $('p-'+id).textContent=pill;
}
function render(){
  document.documentElement.lang = lang;
  document.querySelectorAll('[data-i]').forEach(e=>e.textContent=t(e.dataset.i));
  const ok=online||demo;
  const cn=$('conn'); cn.textContent=ok?'📶 '+t('connected'):'⚠ '+t('disc'); cn.className='badge'+(ok?'':' off');

  const dry=S.moisture<S.dryLimit, wet=S.moisture>S.wetLimit;
  setCard('soil', dry?'warn':'', S.moisture+'%', dry?t('dryS'):wet?t('wetS'):t('optimal'));

  const tk=S.tank;
  if(tk==='EMPTY') setCard('tank','warn',t('empty'),t('refill'));
  else if(tk==='FULL') setCard('tank','info',t('full'),t('stopFill'));
  else if(tk==='MIDDLE') setCard('tank','',t('avail'),t('water'));
  else setCard('tank','warn',t('unknown'),t('sensorFault'));

  setCard('rain', S.rain?'info':'', S.rain?t('rainY'):t('noRain'), S.rain?t('paused'):t('normal'));
  setCard('motor','', S.motor?t('on'):t('off'), S.motor?t('active'):S.rain?t('dueRain'):tk==='EMPTY'?t('tankEmptyP'):t('ready'));

  const man=S.mode==='MANUAL';
  $('b-on').textContent=t('on'); $('b-off').textContent=t('off');
  // colour shows the real pump state: ON = green, OFF = red, the other button grey
  $('b-on').className='btn'+(S.motor?'':' grey');
  $('b-off').className='btn'+(S.motor?' grey':' red');
  $('b-on').disabled=!man||unsafe()||!ok;
  $('b-off').disabled=!man||!ok;
  $('pump-note').textContent=!man?t('pAuto'):unsafe()?t('pUnsafe'):t('pMan');
  $('hm-AUTO').classList.toggle('on',!man); $('hm-MANUAL').classList.toggle('on',man);

  const box=$('alerts'); box.textContent='';
  const al=getAlerts();
  al.forEach(a=>{const d=document.createElement('div');d.className='alert '+a.c;
    const b=document.createElement('b');b.textContent=a.t;d.appendChild(b);
    if(a.m){const s=document.createElement('span');s.textContent=a.m;d.appendChild(s);}
    box.appendChild(d);});
  // speak only when the set of alerts changes (not every 2 seconds)
  const sig=al.map(a=>a.t).join('|');
  if(sig!==lastSig){lastSig=sig; if(al[0].c!=='ok') speak(al.map(a=>a.t+'. '+a.m).join(' ')); else stopSpeech();}

  formMode=S.mode;
  $('m-AUTO').classList.toggle('on',S.mode==='AUTO'); $('m-MANUAL').classList.toggle('on',S.mode==='MANUAL');
  $('l-en').classList.toggle('on',lang==='en'); $('l-hi').classList.toggle('on',lang==='hi');
  $('sw-voice').classList.toggle('on',voiceOn);
  $('demo-bar').style.display=demo?'block':'none';
  renderCal();
}

/* ---------- Navigation ---------- */
function go(name){
  document.querySelectorAll('.screen').forEach(s=>s.classList.remove('on')); $('s-'+name).classList.add('on');
  document.querySelectorAll('nav button').forEach(b=>b.classList.remove('on')); $('n-'+name).classList.add('on');
  if(name==='settings') loadForm();
  window.scrollTo(0,0);
}

/* ---------- Settings ---------- */
function loadForm(){
  $('dry').value=S.dryLimit; $('wet').value=S.wetLimit;
  $('dry-o').textContent=S.dryLimit+'%'; $('wet-o').textContent=S.wetLimit+'%';
  formMode=S.mode; render();
}
$('dry').oninput=e=>$('dry-o').textContent=e.target.value+'%';
$('wet').oninput=e=>$('wet-o').textContent=e.target.value+'%';
function setFormMode(m){setModeNow(m);} // applies immediately, same as the Home switch
function setLang(l){lang=l;localStorage.setItem('lang',l);lastSig='';render();pushPrefs();}
function toggleVoice(){voiceOn=!voiceOn;localStorage.setItem('voice',voiceOn?'on':'off');if(voiceOn)speak(t('voiceTest'),true,1); else stopSpeech(); render();pushPrefs();}
// Language and voice are saved to the ESP32 immediately, using the already-saved limits and mode
async function pushPrefs(){
  if(!(online||demo)) return;
  try{ await api('/api/settings',settingsBody(S.dryLimit,S.wetLimit,S.mode)); }
  catch(e){ toast(e.status?e.message:t('failed')); }
}
function settingsBody(d,w,m){return {dryLimit:d,wetLimit:w,mode:m,language:lang==='hi'?'Hindi':'English',voiceAlerts:voiceOn};}

async function saveSettings(){
  const d=+$('dry').value, w=+$('wet').value;
  if(w-d<10) return toast(t('badLim'));
  try{
    await api('/api/settings',settingsBody(d,w,S.mode));
    S.dryLimit=d; S.wetLimit=w;
    toast(t('saved')); setTimeout(poll,400);
  } catch(e){ toast(e.status?e.message:t('failed')); }
  render();
}
// Home-screen Automatic / Manual switch: saves the mode with the current limits
async function setModeNow(m){
  if(m===S.mode) return;
  const prev=S.mode;
  S.mode=m; formMode=m; pend=null; render();
  try{
    await api('/api/settings',settingsBody(S.dryLimit,S.wetLimit,m));
    toast(t('saved')); setTimeout(poll,400);
  } catch(e){ S.mode=prev; formMode=prev; toast(e.status?e.message:t('failed')); }
  render();
}
async function motor(on){
  const prev=S.motor;
  pend={v:on,until:Date.now()+4000}; S.motor=on; render(); // update buttons instantly
  try{
    await api('/api/motor',{motor:on});
    toast(t('cmdOk'));
    setTimeout(poll,500); setTimeout(poll,2400); // ESP32 updates the relay on its next 2-second cycle
  } catch(e){ pend=null; S.motor=prev; render(); toast(t('cmdFail')+(e.status?': '+e.message:'')); }
}

/* ---------- Automatic calibration ---------- */
const CAL_SECONDS = () => demo ? 3 : 10;
function openModal(){ if(calStep==='dryRun'||calStep==='wetRun') return; $('modal').style.display='flex'; }
function closeModal(){
  $('modal').style.display='none';
  if(calStep==='idle'||calStep==='success'||calStep==='failed'){calStep='ready';calErr=false;}
  renderCal();
}
function startBar(){
  const b=$('cal-bar'); b.style.transition='none'; b.style.width='0'; void b.offsetWidth;
  b.style.transition='width '+CAL_SECONDS()+'s linear'; b.style.width='100%';
}
function renderCal(){
  const on=calStep!=='idle'; $('cal').style.display=on?'block':'none'; if(!on) return;
  const msg=$('cal-msg'), btn=$('cal-btn'), prog=$('cal-prog');
  const running=calStep==='dryRun'||calStep==='wetRun';
  prog.style.display=running?'block':'none';
  msg.className='calmsg';
  btn.style.display='block'; btn.disabled=false;
  switch(calStep){
   case 'ready':   msg.textContent=t('calReady'); btn.textContent=t('calStart'); break;
   case 'dryRun':  msg.textContent=t('calDryRun'); btn.style.display='none'; break;
   case 'dryDone': msg.textContent=t('calDryDone'); btn.textContent=t('calConfirm'); break;
   case 'wetRun':  msg.textContent=t('calWetRun'); btn.style.display='none'; break;
   case 'success': msg.className='calmsg ok'; msg.textContent='✅ '+t('calOk')+'. '+t('calOkM'); btn.style.display='none'; break;
   case 'failed':  msg.className='calmsg bad'; msg.textContent='❌ '+t('calFail')+'. '+(calErr?t('calErr'):t('calFailM')); btn.textContent=t('calRetry'); break;
  }
}
async function calAction(){
  try{
    if(calStep==='ready'){ await api('/api/calibrate/start',{}); calStep='dryRun'; calWatch(); }
    else if(calStep==='dryDone'){ await api('/api/calibrate/confirm',{}); calStep='wetRun'; calWatch(); }
    else if(calStep==='failed'){ calStep='ready'; calErr=false; }
  } catch(e){ calStep='failed'; calErr=true; }
  renderCal();
}
function calWatch(){
  clearInterval(calTimer); calT0=Date.now(); startBar();
  calTimer=setInterval(async()=>{
    try{
      const s=(await api('/api/calibrate/status')).status;
      if(calStep==='dryRun'&&s==='DRY_DONE'){calStep='dryDone';clearInterval(calTimer);}
      else if(calStep==='wetRun'&&(s==='SUCCESS'||s==='FAILED')){calStep=s==='SUCCESS'?'success':'failed';calErr=false;clearInterval(calTimer);setTimeout(poll,500);}
    } catch(e){}
    if((calStep==='dryRun'||calStep==='wetRun')&&Date.now()-calT0>30000){calStep='failed';calErr=true;clearInterval(calTimer);}
    renderCal();
  },1000);
  renderCal();
}

/* ---------- Polling the ESP32 ---------- */
// Turn the firmware's JSON into the dashboard's state.
function norm(f){
  const up=v=>String(v??'').toUpperCase().trim();
  return {
    moisture:Number(f.moisture)||0, raw:Number(f.soilRaw)||0,
    rain:f.rainDetected===true||up(f.rainDetected)==='TRUE',
    tank:up(f.tankStatus)||'UNKNOWN',
    motor:up(f.motor)==='ON'||f.motor===true,
    mode:up(f.mode)==='MANUAL'?'MANUAL':'AUTO',
    dryLimit:Number(f.dryLimit)||30, wetLimit:Number(f.wetLimit)||70,
    alert:String(f.alert??'NONE'), language:f.language, voiceAlerts:f.voiceAlerts
  };
}
let polling=false;
async function poll(){
  if(demo||polling) return;
  polling=true;
  try{
    const d=norm(await api('/api/status'));
    online=true;
    const {language,voiceAlerts,...rest}=d;
    S={...S,...rest};
    if(pend){ if(rest.motor===pend.v||Date.now()>pend.until) pend=null; else S.motor=pend.v; }
    if(!cfgLoaded){ // first load: take the saved language / voice from the ESP32
      cfgLoaded=true;
      if(language) lang=language==='Hindi'?'hi':'en';
      if(typeof voiceAlerts==='boolean') voiceOn=voiceAlerts;
      formMode=S.mode;
    }
  } catch(e){ online=false; }
  polling=false;
  render();
}

/* ---------- Demo mode: open index.html?demo=1 to test without hardware ---------- */
let demoCal='IDLE';
function simulate(){ // copy of the firmware's decision rules
  const empty=S.tank==='EMPTY', full=S.tank==='FULL', wl=S.rain&&S.moisture>S.wetLimit;
  let dec='OK', al='NONE';
  if(empty){dec='OFF';al='TANK EMPTY - DRY RUN RISK';}
  else if(wl){dec='OFF';al='WATERLOGGING RISK';}
  else if(S.rain){dec='OFF';al='RAIN DETECTED';}
  else if(S.moisture<S.dryLimit){dec='IRRIGATE';al='SOIL DRY';}
  if(full) al=al==='NONE'?'TANK FULL - STOP FILLING':al+' | TANK FULL - STOP FILLING';
  if(S.mode==='MANUAL') S.motor=!!S.manual&&!empty&&S.tank!=='INVALID'&&!S.rain;
  else {S.manual=false;S.motor=dec==='IRRIGATE';}
  S.alert=al;
}
function mockApi(path,b){
  const err=(m,s)=>{const e=new Error(m);e.status=s;throw e;};
  if(path==='/api/settings'){S.dryLimit=b.dryLimit;S.wetLimit=b.wetLimit;S.mode=b.mode;simulate();return {success:true};}
  if(path==='/api/motor'){
    if(S.mode!=='MANUAL') err('Switch to MANUAL mode first',400);
    if(b.motor&&(S.tank==='EMPTY'||S.tank==='INVALID'||S.rain)) err('Safety condition: Motor cannot start',409);
    S.manual=b.motor;simulate();return {success:true};
  }
  if(path==='/api/calibrate/start'){demoCal='DRY_RUNNING';setTimeout(()=>demoCal='DRY_DONE',3000);return {status:demoCal};}
  if(path==='/api/calibrate/confirm'){demoCal='WET_RUNNING';setTimeout(()=>demoCal='SUCCESS',3000);return {status:demoCal};}
  if(path==='/api/calibrate/status') return {status:demoCal};
  return {};
}
function scn(o){S={...S,...o,manual:false};simulate();render();}
function startDemo(){demo=true;online=false;S={...S,moisture:62,tank:'MIDDLE',rain:false,motor:false};simulate();render();}

/* ---------- Start ---------- */
render(); poll(); setInterval(poll,POLL_MS);
if(location.search.includes('demo=1')) startDemo();
</script>
</body>
</html>
)rawliteral";
