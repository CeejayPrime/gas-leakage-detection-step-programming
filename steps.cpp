#include <ThingsBoard.h>

#include <WiFiEspClient.h>
#include <WiFiEsp.h>
#include "SoftwareSerial.h"

#define WIFI_AP                           "WIFI_SSID"
#define WIFI_PASSWORD                     "WIFI_PASSWORD"

#define TOKEN                             "E8QhroHvcEbBV3qSdeBK"
#define THINGSBOARD_SERVER                "demo.thingsboard.io"

#define SERIAL_DEBUG_BAUD                 9600
#define SERIAL_ESP8266_BAUD               9600

int GAS_SENSOR_1 = A0;
int gas_Reading = 0;
float VAL_GAS_1;

//unsigned long lastSend;
//unsigned long endMillis;
//unsigned long startMillis;

#define gasHigh A1
#define alert 3

int Tone = 440;
boolean isGasHigh = false;

SoftwareSerial soft(2, 3);

WiFiEspClient espClient;

ThingsBoard tb(espClient);

int status = WL_IDLE_STATUS;

unsigned long lastSend;
unsigned long endMillis;
unsigned long startMillis;

void setup () {
  Serial.begin(SERIAL_DEBUG_BAUD);
  soft.begin(SERIAL_ESP8266_BAUD);

  WiFi.init(&soft);

  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    while (true);
    
  pinMode(gasHigh, INPUT);
  pinMode(alert, OUTPUT);
}

void loop() {
  isGasHigh = digitalRead(gasHigh);

  VAL_GAS_1 = analogRead(GAS_SENSOR_1);
  gas_Reading = map(VAL_GAS_1, 0, 1023, 60, 0);
  
  Serial.println("Gas 1 sensor raw value " + String(VAL_GAS_1));
  Serial.println("Gas 1 sensor reading " + String(gas_Reading));
  
  if (status != WL_CONNECTED) {
    Serial.println("Connecting to AP...");
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(WIFI_AP);

    status = WiFi.begin(WIFI_AP, WIFI_PASSWORD);
    return;
  }

  if (!tb.connected()) {
    Serial.print("Connected to: ");
    Serial.print(THINGSBOARD_SERVER);
    Serial.print(" with token ");
    Serial.println(TOKEN);

    if (!tb.connect(THINGSBOARD_SERVER, TOKEN)) {
      Serial.println("Failed to connect");
      return;
    }
  }

  Serial.println("Sending data...");

  endMillis = millis();
  unsigned long sendTelemetryTime = endMillis - startMillis;

  if (millis() - lastSend > 1000) {
     
  if (isGasHigh and gas_Reading >= 30) {
    Serial.println("gas value is high");
    tone(alert, Tone);
  }
    tb.sendTelemetryInt("Gas sensor 1", gas_Reading);
  }

}
