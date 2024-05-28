#include <WiFi.h>
#include <WebServer.h>

const char *ssid = "Anagha";
const char *password = "99887766";

WebServer server(80);

const int pirPin = 2; 
bool motionDetected = false;
int motionCounter = 0; // Counter for the number of motions detected

void setup() {
  Serial.begin(115200);

  pinMode(pirPin, INPUT);

  // Connect to Wi-Fi
  Serial.println("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Define server routes
  server.on("/", HTTP_GET, handleRoot);
  server.on("/status", HTTP_GET, handleStatus);  
  server.on("/counter", HTTP_GET, handleCounter); // Added route for the counter

  // Start server
  server.begin();
  Serial.println("Server started");
}

void loop() {
  // Handle client requests
  server.handleClient();

  // Update PIR sensor reading
  bool currentMotionState = digitalRead(pirPin) == HIGH;

  // Check if motion state has changed
  if (currentMotionState != motionDetected) {
    if (currentMotionState) {
      // Motion detected, increment counter
      motionCounter++;
    }

    // Update motion detected state
    motionDetected = currentMotionState;
  }

  // Print PIR sensor status
  Serial.println(motionDetected ? "Motion Detected" : "No Motion Detected");

  delay(1000); // Adjust delay as needed
}

void handleRoot() {
  String page = "<html><body>";
  page += "<h1>Count</h1>";
  page += "<p id='counter'>Motion Count: " + String(motionCounter) + "</p>";
  page += "<script>";
  page += "setInterval(function() {"
          "  fetch('/status')"
          "    .then(response => response.text())"
          "    .then(data => document.getElementById('status').innerText = data);"
          "}, 1000);";
  page += "setInterval(function() {"
          "  fetch('/counter')"
          "    .then(response => response.text())"
          "    .then(data => document.getElementById('counter').innerText = 'Motion Count: ' + data);"
          "}, 1000);";
  page += "</script>";
  page += "</body></html>";

  server.send(200, "text/html", page);
}

void handleStatus() {
  server.send(200, "text/plain", motionDetected ? "Motion Detected" : "No Motion Detected");
}

void handleCounter() {
  server.send(200, "text/plain", String(motionCounter));
}