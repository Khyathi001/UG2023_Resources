#include "DHT.h"

#define DHTTYPE DHT11    
#define dht_dpin 13     

DHT dht(dht_dpin, DHTTYPE);  

float temperatureSum = 0;    
float humiditySum = 0;
int count = 0;  

void setup() {
  Serial.begin(115200);  
  dht.begin();        
}

void loop() {
  delay(1000);  
  
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
  
  temperatureSum = temperatureSum + temperature;
  humiditySum = humiditySum + humidity;
  count++;
  
  if (count == 5) {  
    float meanTemperature = temperatureSum / count;
    float meanHumidity = humiditySum / count;

    Serial.print(meanTemperature);
    Serial.print(" ");
    Serial.println(meanHumidity);

    temperatureSum = 0;
    humiditySum = 0;
    count = 0;
  }
}