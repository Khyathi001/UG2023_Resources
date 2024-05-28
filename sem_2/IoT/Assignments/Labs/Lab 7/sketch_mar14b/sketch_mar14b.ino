#include <WiFi.h>
#include <Thingspeak.h>
#include <PubSubClient.h>

// Define WiFi credentials
const char *ssid = "your_network_name";
const char *password = "your_network_password";

// Define ThingSpeak credentials
const char *mqttServer = "mqtt.thingspeak.com";
const char *channelID = "your_channel_ID";
const char *apiKey = "your_API_key";
const char *writeAPIKey = "your_write_API_key";

// Define GPIO pin for LED
const int ledPin = 2; // Change this according to your ESP32 pin configuration

// Initialize WiFi client and ThingSpeak MQTT client
WiFiClient espClient;
PubSubClient client(espClient);

// Function to connect to WiFi
void connectWiFi() {
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
}

// Function to connect to ThingSpeak MQTT server
void connectMQTT() {
  Serial.print("Connecting to ThingSpeak MQTT...");
  client.setServer(mqttServer, 1883);
  while (!client.connected()) {
    if (client.connect("ESP32Client", apiKey, NULL)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

// Function to publish data to ThingSpeak
void publishToThingSpeak(float data) {
  // Create a string payload for publishing to ThingSpeak
  String payload = String("field1=") + String(data);

  // Publish data to ThingSpeak channel
  if (client.publish("channels/" + String(channelID) + "/publish/" + String(writeAPIKey), payload.c_str())) {
    Serial.println("Publish success");
  } else {
    Serial.println("Publish failed");
  }
}

// Setup function
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  connectWiFi();
  connectMQTT();
}

// Loop function
void loop() {
  // Check for MQTT messages
  client.loop();
  
  // Read LED state from ThingSpeak
  float ledState = ThingSpeak.readFloatField(channelID, 1, apiKey);
  
  // Control LED based on received state
  if (ledState == 1) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
