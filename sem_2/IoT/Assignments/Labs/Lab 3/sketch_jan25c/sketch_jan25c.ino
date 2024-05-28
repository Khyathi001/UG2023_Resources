#include "BluetoothSerial.h"

const int trigger_pin=27;
const int echo_pin=14;
const int LED=5;
unsigned long duration;
float distance;    
float threshold;
const float speed_of_sound=343.2;  

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
    digitalWrite(trigger_pin,LOW);
    delayMicroseconds(5);
    digitalWrite(trigger_pin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger_pin,LOW);
    duration=pulseIn(echo_pin, HIGH);
    distance=0.034*duration/2;
    
    SerialBT.print("distance in cm:");
    SerialBT.println(distance);

    if (SerialBT.available())
    {
        String t=SerialBT.readString();
        threshold=t.toInt();   
    }

    if (threshold>=distance)
    {
       SerialBT.println("Object in Vicinity");
       digitalWrite(LED,HIGH);
    }
    else
    {
        digitalWrite(LED,LOW);
    }
    delay(2000);
}