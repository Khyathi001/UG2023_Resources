#include <WebServer.h>
#include <WiFi.h>

const int irSensorPin = 2;  
const int triggerPin = 13;   
const int echoPin = 12;      

int count = 0;
int previousDistance = 0;

const char* ssid = "Anagha";
const char* password = "99887766";

WebServer server(80);

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  Serial.println(WiFi.localIP());

  pinMode(irSensorPin, INPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  server.on("/", handleRoot);

  server.begin();
}

void loop() {

    server.handleClient();

  int irStatus = digitalRead(irSensorPin);
  int ultrasonicDistance = getUltrasonicDistance();

  if (irStatus == HIGH) {
    if (ultrasonicDistance > previousDistance) {
      count++;
    } else if ((ultrasonicDistance < previousDistance) && (count>0)) {
      count--;
    }
  }

  previousDistance = ultrasonicDistance;


  delay(3000);
}

int getUltrasonicDistance() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

void handleRoot() {
  String html = "<html><head><title>Count Display</title>";
  html += "<meta http-equiv='refresh' content='1'>";
  html += "</head><body><h1>Count: ";
  html += count;
  html += "</h1></body></html>";
  server.send(200, "text/html", html);
}