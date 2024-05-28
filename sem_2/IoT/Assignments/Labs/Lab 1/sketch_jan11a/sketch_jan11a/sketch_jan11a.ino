int min_initial;
int max_initial;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0;i<20;i++){
    min_initial=i*10;
    max_initial=min_initial+10;
    Serial.println(random(min_initial,max_initial));
    delay(1000);
  }

}
