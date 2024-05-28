#define LedPin 2
int num;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LedPin,OUTPUT);
  while (Serial.available()==0){}
  num=Serial.parseInt();

}



void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite (LedPin, HIGH);	
  delay(num*1000);	
  digitalWrite (LedPin, LOW);	
  delay(num*1000);	
}
