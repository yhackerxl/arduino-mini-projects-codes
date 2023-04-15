#include <ESP8266WiFi.h>

const char* ssid = "Anuar's phone";     // Replace with your network SSID
const char* password = "vally2023"; // Replace with your network password

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  

  Serial.println("Connected to WiFi");
}

void loop() {
  // Your code here
}
