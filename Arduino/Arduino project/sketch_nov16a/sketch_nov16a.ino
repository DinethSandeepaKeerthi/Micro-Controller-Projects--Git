#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

const char* ssid = "NANO";
const char* password = "slintecpass";

bool ledState1 = 0;
bool ledState2 = 0;

const int ledPin1 = 2;
const int ledPin2 = 15;

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <title>ESP Web Server</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="icon" href="data:,">
  <style>
  /* Your styles here */
  </style>
</head>
<body>
  <div class="topnav">
    <h1>ESP WebSocket Server</h1>
  </div>
  <div class="content">
    <div class="card">
      <h2>Output - GPIO 2</h2>
      <p class="state">state: <span id="state1">%STATE1%</span></p>
      <button id="button1" class="button">Toggle 1</button>
      <h2>Output - GPIO 3</h2>
      <p class="state">state: <span id="state2">%STATE2%</span></p>
      <button id="button2" class="button">Toggle 2</button>
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
    } else if (strcmp((char*)data, "toggle2") == 0) {
      ledState2 = !ledState2;
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
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  
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
  digitalWrite(ledPin1, ledState1);
  digitalWrite(ledPin2, ledState2);
}

