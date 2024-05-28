const int touchPin=15;
const int ledPin=2;
const int threshhold=20;
int touchValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  touchValue=touchRead(touchPin);
  Serial.println(touchValue);
  if(touchValue<threshhold){
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }
  delay(1000); 
}
