int GAS_SENSOR_1 = A0;

float VAL_GAS_1;

//unsigned long lastSend;
//unsigned long endMillis;
//unsigned long startMillis;

#define gasHigh A1
#define alert 3

int Tone = 440;
boolean isGasHigh = false;

void setup () {
  Serial.begin(9600);
  pinMode(gasHigh, INPUT);
  pinMode(alert, OUTPUT);
}

void loop() {
  isGasHigh = digitalRead(gasHigh);

  VAL_GAS_1 = analogRead(GAS_SENSOR_1);
  gas_Reading = map(VAL_GAS_1, 0, 1023, 60, 0);
  
  Serial.println("Gas 1 sensor raw value " + String(VAL_GAS_1));
  Serial.println("Gas 1 sensor reading " + String(gas_Reading));
  
  if (isGasHigh) {
    Serial.println("gas value is high");
    tone(alert, Tone);
  }
  delay(2000);

}
