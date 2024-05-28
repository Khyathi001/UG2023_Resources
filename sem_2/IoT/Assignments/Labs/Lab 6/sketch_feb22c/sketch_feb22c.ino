#include <WiFi.h>

const char* ssid = "Anagha";
const char* password = "99887766";

const int ledPin = 13; 
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  Serial.println("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("Connected to WiFi");
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New client connected");

    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);

        // Check for the end of the HTTP request
        if (c == '\n') {
          // Process the client request
          if (currentLine.length() > 0) {
            if (currentLine.startsWith("GET /L")) {
              // Turn the LED LOW
              digitalWrite(ledPin, LOW);
            } else if (currentLine.startsWith("GET /H")) {
              // Turn the LED HIGH
              digitalWrite(ledPin, HIGH);
            }

            // Send the HTML response
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.println("<html><body>");
            client.println("<h1>ESP32 LED Control</h1>");
            client.println("<p>Current LED State: " + String(digitalRead(ledPin)) + "</p>");
            client.println("<a href='/L'>Turn LED LOW</a><br>");
            client.println("<a href='/H'>Turn LED HIGH</a>");
            client.println("</body></html>");
          }

          // Clear the current line
          currentLine = "";

          // Stop the client connection
          client.stop();
          Serial.println("Client disconnected");
        } else if (c != '\r') {
          // Append to the current line
          currentLine += c;
        }
      }
    }
  }
}
