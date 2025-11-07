#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

const char* ssid = "NANO";
const char* password = "slintecpass";

bool ledState1 = LOW;  // Initially set to LOW (OFF)
bool ledState2 = HIGH; // Initially set to HIGH (OFF)

const int ledPin1 = 2;
const int ledPin2 = 15;

unsigned long lastActivationTime1 = 0;
unsigned long lastActivationTime2 = 0;
const unsigned long activationDuration = 1000; // 1 second

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>AHU Controlling UI</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="icon" href="data:,">
  <style>
    /* Your styles here */
    .button1 {
      background-color: white; /* Initially white */
    }

    .button2 {
      background-color: white; /* Initially white */
    }

    .on {
      background-color: #4CAF50; /* Green */
    }

    .stop-on {
      background-color: #FF0000; /* Red */
    }
  </style>
</head>
<body>
  <div class="topnav">
    <h1>AHU Controlling UI</h1>
  </div>
  <div class="content">
    <div class="card">
      <h2>START</h2>
      <p class="state">state: <span id="state1">%STATE1%</span></p>
      <button id="button1" class="button button1">Toggle START</button>
      <h2>STOP</h2>
      <p class="state">state: <span id="state2">%STATE2%</span></p>
      <button id="button2" class="button button2">Toggle STOP</button>
    </div>
  </div>
  <script>
    var gateway = `ws://${window.location.hostname}/ws`;
    var websocket;
    window.addEventListener('load', onLoad);

    function initWebSocket() {
      console.log('Trying to open a WebSocket connection...');
      websocket = new WebSocket(gateway);
      websocket.onopen    = onOpen;
      websocket.onclose   = onClose;
      websocket.onmessage = onMessage;
    }

    function onOpen(event) {
      console.log('Connection opened');
    }

    function onClose(event) {
      console.log('Connection closed');
      setTimeout(initWebSocket, 2000);
    }

    function onMessage(event) {
      var state1, state2;
      var states = event.data.split(',');
      if (states.length == 2) {
        state1 = states[0] === "1" ? "ON" : "OFF";
        state2 = states[1] === "1" ? "ON" : "OFF";
        document.getElementById('state1').innerHTML = state1;
        document.getElementById('state2').innerHTML = state2;

        // Set button background color based on state
        document.getElementById('button1').classList.toggle('on', state1 === "ON");
        document.getElementById('button2').classList.toggle('on', state2 === "ON");
        document.getElementById('button2').classList.toggle('stop-on', state2 === "ON");
      }
    }

    function onLoad(event) {
      initWebSocket();
      initButtons();
    }

    function initButtons() {
      document.getElementById('button1').addEventListener('click', function() {
        websocket.send('toggle1');
      });
      document.getElementById('button2').addEventListener('click', function() {
        websocket.send('toggle2');
      });
    }
  </script>
</body>
</html>
)rawliteral";

void notifyClients() {
  ws.textAll(String(ledState1) + "," + String(ledState2));
}

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo*)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    data[len] = 0;
    if (strcmp((char*)data, "toggle1") == 0) {
      ledState1 = !ledState1;
      lastActivationTime1 = millis(); // Record the time when the output is turned on
      ledState2 = !ledState1; // When start is toggled, stop is set to the opposite state
    } else if (strcmp((char*)data, "toggle2") == 0) {
      ledState2 = !ledState2;
      lastActivationTime2 = millis(); // Record the time when the output is turned on
      ledState1 = !ledState2; // When stop is toggled, start is set to the opposite state
    }
    notifyClients();
  }
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
             void *arg, uint8_t *data, size_t len) {
  switch (type) {
    case WS_EVT_CONNECT:
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      break;
    case WS_EVT_DATA:
      handleWebSocketMessage(arg, data, len);
      break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      break;
  }
}

void initWebSocket() {
  ws.onEvent(onEvent);
  server.addHandler(&ws);
}

String processor(const String& var){
  if(var == "STATE1"){
    return ledState1 ? "ON" : "OFF";
  }
  else if (var == "STATE2"){
    return ledState2 ? "ON" : "OFF";
  }
  return String();
}

void setup(){
  Serial.begin(115200);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  digitalWrite(ledPin1, ledState1);
  digitalWrite(ledPin2, ledState2);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println(WiFi.localIP());

  initWebSocket();

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });

  server.begin();
}

void loop() {
  ws.cleanupClients();
  
  // Check if the time has passed the activation duration
  if (ledState1 == HIGH && millis() - lastActivationTime1 >= activationDuration) {
    ledState1 = LOW;
    notifyClients();
  }
  if (ledState2 == HIGH && millis() - lastActivationTime2 >= activationDuration) {
    ledState2 = LOW;
    notifyClients();
  }

  digitalWrite(ledPin1, ledState1);
  digitalWrite(ledPin2, ledState2);
}
