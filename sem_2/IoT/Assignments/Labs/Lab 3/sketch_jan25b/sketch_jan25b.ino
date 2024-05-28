#include"BluetoothSerial.h"
const int trigger_pin=27;
const int echo_pin=14;
long int duration;
float distance;
const int speed_of_sound=343.2;

BluetoothSerial SerialBT;

void setup()
{
    Serial.begin(115200);
    SerialBT.begin("Anagha");
    pinMode(trigger_pin,OUTPUT);
    pinMode(echo_pin,INPUT);
}

void loop(){
    digitalWrite(trigger_pin,LOW);
    delayMicroseconds(5);
    digitalWrite(trigger_pin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger_pin,LOW);
    duration=pulseIn(echo_pin,HIGH);
    distance=0.034*duration/2;
    SerialBT.print("distance in cm:");
    SerialBT.println(distance);
    SerialBT.print("distance in mm:");
    SerialBT.println(distance*10);
    delay(2000);
}
