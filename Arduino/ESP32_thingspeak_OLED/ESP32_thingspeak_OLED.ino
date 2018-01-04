/*
 
 Send wifi signal data to Thingspeak and mirror report on OLED screen
 Tested on Heltec ESP32 Wi-Fi Device
  
 Adapted from the work of
  * Hans Scharler (http://nothans.com)
  * Makerbro (https://acrobotic.com/)

  THO x NIBO

*/

// OLED
#include <Wire.h>
#include <ACROBOTIC_SSD1306.h>

// WIFI
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>

// Wi-Fi Settings
const char* ssid = "XXX"; // your wireless network name (SSID)
const char* password = "XXX"; // your Wi-Fi network password

WiFiClient client;

// ThingSpeak Settings
const int channelID = XXX;
String writeAPIKey = "XXX"; // write API key for your ThingSpeak Channel
const char* server = "api.thingspeak.com";
const int postingInterval = 20 * 1000; // post data every 20 seconds

void setup() {
  
  // OLED setup
  pinMode(16,OUTPUT);
  digitalWrite(16, LOW);    // set GPIO16 low to reset OLED
  delay(50); 
  digitalWrite(16, HIGH);   // while OLED is running, must set GPIO16 to high  
  Wire.begin(4,15);  
  oled.init();              // Initialze SSD1306 OLED display
  oled.clearDisplay();      // Clear screen  
  oled.setFont(font5x7);
  oled.setTextXY(0,0);
  oled.putString("thinking...");
    
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void loop() {
  if (client.connect(server, 80)) {
    
    // Measure Signal Strength (RSSI) of Wi-Fi connection
    long rssi = WiFi.RSSI();

    // Construct API request body
    String body = "field1=";
           body += String(rssi);
    
    Serial.print("RSSI: ");
    Serial.println(rssi); 

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + writeAPIKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(body.length());
    client.print("\n\n");
    client.print(body);
    client.print("\n\n");

    oled.clearDisplay();
    oled.setFont(font8x8);    // limited size options with this library?
    oled.setTextXY(0,0);
    oled.putString(String(rssi));

  }
  client.stop();

  // wait and then post again
  delay(postingInterval);
}
