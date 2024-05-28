#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Anagha";
const char* password = "99887766";

const int LED_PIN = 5; 
const int MOTION_SENSOR_PIN = 2; 

WebServer server(80);

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  pinMode(MOTION_SENSOR_PIN, INPUT);

  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html", "<!DOCTYPE html><html><head><title>ESP32 Web Server</title><script>function updateSensorStatus() { var xhttp = new XMLHttpRequest(); xhttp.onreadystatechange = function() { if (this.readyState == 4 && this.status == 200) { document.getElementById('sensorStatus').innerHTML = this.responseText; } }; xhttp.open('GET', '/data', true); xhttp.send(); } setInterval(updateSensorStatus, 1000); </script></head><body><h1>Reading</h1><div id='sensorStatus'></div></body></html>");
  });

  server.on("/data", HTTP_GET, []() {
    String data = digitalRead(MOTION_SENSOR_PIN) ? "Motion Detected" : "No Motion Detected";
    server.send(200, "text/plain", data);
  });

  server.begin();
  Serial.println("Server started");
}

void loop() {
  server.handleClient();

  int motionSensorReading = digitalRead(MOTION_SENSOR_PIN);
  Serial.print("Motion Sensor Reading: ");
  Serial.println(motionSensorReading);

  digitalWrite(LED_PIN, motionSensorReading);

  delay(1000);
}