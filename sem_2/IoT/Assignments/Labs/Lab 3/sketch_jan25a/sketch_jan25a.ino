const int trigger_pin=27;
const int echo_pin=14;
unsigned long duration;
float distance;
const float speed_of_sound=343.2;

void setup()
{
    Serial.begin(115200);
    pinMode(trigger_pin,OUTPUT);
    pinMode(echo_pin,INPUT);
}

void loop(){
    digitalWrite(trigger_pin,LOW);
    delayMicroseconds(5);
    digitalWrite(trigger_pin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger_pin,LOW);
    duration=pulseIn(14,HIGH);
    distance=0.034*duration/2;
    Serial.print("distance in cm:");
    Serial.println(distance);
    Serial.print("distance in mm:");
    Serial.println(distance*10);
    delay(500);
}
