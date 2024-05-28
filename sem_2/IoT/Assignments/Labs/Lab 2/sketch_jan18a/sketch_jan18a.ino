#define SENSOR_PIN 13
#define SIGNAL_PIN 12

void setup() {
  Serial.begin(115200);
  pinMode(SENSOR_PIN, OUTPUT);
  digitalWrite(SENSOR_PIN,LOW);
}

void loop() {
  digitalWrite(SENSOR_PIN, HIGH);
  int val = analogRead(SIGNAL_PIN);
  digitalWrite(SENSOR_PIN, LOW);
  Serial.println(val);
  delay(1000);
}
