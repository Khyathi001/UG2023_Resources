#define IR_sensor 5
#define LED 13
int value=0;

void setup() {
  Serial.begin(115200);
  pinMode(IR_sensor, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED,LOW);
  value=digitalRead(IR_sensor);
  if (value==LOW){
    Serial.println("object detected");
    digitalWrite(LED,HIGH);
    delay(1000);
    digitalWrite(LED,LOW);
    delay(500);
  }
  else{
    Serial.println("object not detected");
    digitalWrite(LED,LOW);
  }
  delay(1000);
}