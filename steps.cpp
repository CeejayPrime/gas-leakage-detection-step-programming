#include <WiFi.h>
#include <MQUnifiedsensor.h>
#include <ThingsBoard.h>

const char* ssid = "Project";
const char* password = "Project123";

#define TOKEN                         "TOKEN"
#define THINGSBOARD_SERVER            "demo.thingsboard.io"

#define pin                           34
#define LED_PIN                    18

WiFiClient espClient;
ThingsBoard tb(espClient);
int status = WL_IDLE_STATUS;

unsigned long lastSend;
unsigned long endMillis;
unsigned long startMillis;

float gas_Reading = 0;
double Gas_Level = (0);

void setup() {
  Serial.begin(9600);

  if (Serial)
    Serial.println("Serial is open");
  WiFi.begin(ssid, password);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  Gas_Level = analogRead(pin);
  gas_Reading = Gas_Level / 68.26;

  if (gas_Reading >= 50) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  if (!tb.connected()) {
    // Connect to the ThingsBoard
    tb.connect(THINGSBOARD_SERVER, TOKEN);
    if (!tb.connect(THINGSBOARD_SERVER, TOKEN)) {
      Serial.println("Failed to connect");
    }
    else {
      Serial.println("Connected");
    }
  }
  tb.sendTelemetryFloat("Gas Level", gas_Reading);
  delay(200);
}
