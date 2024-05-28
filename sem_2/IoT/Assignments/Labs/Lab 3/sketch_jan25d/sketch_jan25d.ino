#include "BluetoothSerial.h"

const int trigger_pin=27;
const int echo_pin=14;
const int LED=5;
const int speed_of_sound=343; 
float initial_distance;
float final_distance;
unsigned long initial_duration;
unsigned long final_duration; 
float speed;
float initial_time;
float final_time;

BluetoothSerial SerialBT;

void setup()
{
    Serial.begin(115200);
    SerialBT.begin("Anagha");
    pinMode(trigger_pin,OUTPUT);
    pinMode(echo_pin,INPUT);
    pinMode(LED,OUTPUT);  
}

void loop()
{
  if (SerialBT.available()){
    char command=SerialBT.read();
    if (command=='s'){
      digitalWrite(trigger_pin,LOW);
      delayMicroseconds(5);
      digitalWrite(trigger_pin,HIGH);
      delayMicroseconds(10);
      digitalWrite(trigger_pin,LOW);
      initial_time=micros();

      initial_duration=pulseIn(echo_pin, HIGH);

      initial_distance=0.034*initial_duration/2;
      digitalWrite(trigger_pin,LOW);
      delayMicroseconds(5);
      digitalWrite(trigger_pin,HIGH);
      delayMicroseconds(10);
      digitalWrite(trigger_pin,LOW);
      final_duration=pulseIn(echo_pin, HIGH);
      //final_time=micros();
      final_distance=0.034*final_duration/2; 
      final_time=micros();
      speed=(abs(final_distance-initial_distance)/(final_time-initial_time))*1000000;
      SerialBT.print("The speed is: ");
      SerialBT.println(speed/100);
    }
  }

    
    delay(2000);
}