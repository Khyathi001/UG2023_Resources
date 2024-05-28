#define SENSOR_PIN 13
#define SIGNAL_PIN 12
#define LED_PIN 2
#define TOUCH_PIN 15
#define waterThreshold 50

int requiredWaterLevel=0; 

void setup() {
  Serial.begin(115200);
  pinMode(SENSOR_PIN,OUTPUT);
  digitalWrite(SENSOR_PIN,LOW);
  pinMode(LED_PIN,OUTPUT);
  digitalWrite(LED_PIN,LOW);
}

void loop() {
  digitalWrite(SENSOR_PIN,HIGH);
  int waterLevel=analogRead(SIGNAL_PIN);
  digitalWrite(SENSOR_PIN,LOW);
  int touchValue=digitalRead(TOUCH_PIN);

  if (touchValue==HIGH) {
    requiredWaterLevel=waterLevel;
    Serial.println("Touch detected. Updated required water level to: " + String(requiredWaterLevel));
  }

  if (waterLevel > (requiredWaterLevel + waterThreshold) || waterLevel < (requiredWaterLevel - waterThreshold)) {
    Serial.print("Water level is ");
    if (waterLevel > requiredWaterLevel) {
      Serial.println("above the required level. Turning on LED.");
    } else {
      Serial.println("below the required level. Turning on LED.");
    }
    digitalWrite(LED_PIN,HIGH); 
  } 
  else {
    digitalWrite(LED_PIN,LOW); 
  }

  delay(1000);
  Serial.flush();
}
