#include <WiFi.h>
#include <PubSubClient.h>
#include <ThingSpeak.h>

// Network credentials
const char* ssid = "Galaxy M21 2021 Edition22B9";
const char* password = "lunalove+10";

// ThingSpeak credentials
const char* mqtt_server = "mqtt3.thingspeak.com";
const char* mqttUserName = "HSEZLSo4OicyBAcaISAaByU"; // Set this to your ThingSpeak User API Key
const char* mqttPass = "QJjU6Sm2E5Lyk1Kxo3iNiDKV"; // Set this to your MQTT API Key
const char* clientID = "HSEZLSo4OicyBAcaISAaByU"; // Can be any unique client ID
const long channelID = 2469288 ; // Your ThingSpeak Channel ID
const int ledPin = 15; // GPIO pin number connected to LED

WiFiClient wiFiClient;
PubSubClient client(wiFiClient);

void connectToWiFi() {
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
}

void mqttCallback(char* topic, byte* payload, unsigned int length) {
  Serial.println("here");
  // Handle message arrived
  payload[length] = '\0'; // Ensure valid termination for string.
  String message = String((char*)payload);
  Serial.println(message);
  if (message == "1") {
    digitalWrite(ledPin, HIGH);
  } else if (message == "0") {
    digitalWrite(ledPin, LOW);
  }
}

void connectToMQTT() {
  client.setServer(mqtt_server, 1883);
  client.setCallback(mqttCallback);
  
  // Connect to MQTT Broker
  Serial.print("Connecting to MQTT...");
  while (!client.connected()) {
    if (client.connect(clientID, mqttUserName, mqttPass)) {
      Serial.println("connected");
      // Subscribe to the channel
      client.subscribe(("channels/" + String(channelID) + "/subscribe/fields/field1").c_str());
    } else {
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  connectToWiFi();
  connectToMQTT();
}

void loop() {
  if (!client.connected()) {
    connectToMQTT();
  }
  client.loop();
}