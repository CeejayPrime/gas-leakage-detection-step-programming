

#define SERIAL_DEBUG_BAUD                 9600

#define GAS_SENSOR_1                      A0
//#define GAS_SENSOR_2                      A2
//#define GAS_SENSOR_3                      A6

#define BUZZER_ALARM                       4

//#define LED_RED

int VAL_GAS_1 = 0;
//int VAL_GAS_2 = 0;
//int VAL_GAS_3 = 0;


//RTC_DS3231 rtc;

unsigned long lastSend;
unsigned long endMillis;
unsigned long startMillis;

void setup () {
  Serial.begin(9600);

}

void loop() {
  VAL_GAS_1 = analogRead(GAS_SENSOR_1);
  //  VAL_GAS_2 = analogRead(GAS_SENSOR_2);
  //  VAL_GAS_3 = analogRead(GAS_SENSOR_3);

  //  Serial.println("Gas 2 sensor reading" + String(VAL_GAS_2));
  //  Serial.println("Gas 3 sensor reading" + String(VAL_GAS_3));

  endMillis = millis();
  unsigned long sendTelemetryTime = endMillis - startMillis;

  if (millis() - lastSend > 1000) {
    Serial.println("Gas 1 sensor reading" + String(VAL_GAS_1));
    lastSend = millis();
  }
}
