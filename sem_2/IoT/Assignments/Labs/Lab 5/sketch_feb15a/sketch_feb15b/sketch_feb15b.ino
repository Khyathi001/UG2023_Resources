#include <ESP32Servo.h>
#include "DHT.h"
#define DHTTYPE DHT11    
#define dht_dpin 13     

DHT dht(dht_dpin, DHTTYPE);  
Servo myServo;
int initialAngle = 0; 
const int servoPin = 15; 

void setup() {
    Serial.begin(115200); 
    myServo.attach(servoPin); 
    myServo.write(initialAngle); 
    dht.begin();
}

void loop() {
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C, Humidity: ");
    Serial.print(humidity);
    Serial.println("%");

    float tempThreshold = 27.0; 
    float humidityThreshold = 60.0; 

    if (temperature >= tempThreshold && humidity >= humidityThreshold) {
      myServo.write(90); 
      delay(1000); 
      myServo.write(0);
    } 
    else {
      myServo.write(0);
      delay(1000); 
    }

    float additionalThresholdHumidity = 70.0;
    if (humidity >= additionalThresholdHumidity) {
        myServo.write(45); 
        delay(500); 
        myServo.write(0);
    }
    else{
      myServo.write(0);
      delay(500);
    }
    delay(1000); 
}