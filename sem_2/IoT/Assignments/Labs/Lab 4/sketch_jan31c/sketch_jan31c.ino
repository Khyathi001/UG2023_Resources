#define IR_sensor 5
#define LED 13
int lastDetectionTime=0;
int detectionInterval=10;

void setup() {
  Serial.begin(115200);
  pinMode(IR_sensor, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {

  while (digitalRead(IR_sensor)==LOW){
    Serial.println("detected");
    if (lastDetectionTime<detectionInterval){
      lastDetectionTime+=1;
      delay(1000);
    }
    else{
      break;
    }
  }
  if (lastDetectionTime==detectionInterval){
    digitalWrite(LED,HIGH);
    delay(2000);
    digitalWrite(LED,LOW);
    lastDetectionTime=0;
  }
  else{
    Serial.println("not detected");
    digitalWrite(LED,LOW);
    lastDetectionTime=0;
  }
  delay(1000);
}
