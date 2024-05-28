#define IR_sensor 13

void setup() {
  Serial.begin(115200);
  pinMode(IR_sensor, INPUT);
}

void loop() {
  if (digitalRead(IR_sensor)==LOW){
    Serial.println("detected-HIGH");
  }
  else{
    Serial.println("not detected-LOW");
  }
  delay(5000);
}
