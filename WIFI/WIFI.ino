#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

const char* host = "WiFi_Robot4_NodeMCU";
const char *ssid = "Twitch Drone"; // The name of the Wi-Fi network that will be created
const char *password = "1101104555";   // The password required to connect to it, leave blank for an open network

ESP8266WebServer server(80);

void setup() {
  Serial.begin(9600);
  delay(10);
 // Serial.println('\n');
pinMode(LED_BUILTIN, OUTPUT);
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);             // Start the access point
 // Serial.print("Access Point \"");
 // Serial.print(ssid);
 // Serial.println("\" started");

 // Serial.print("IP address:\t");
 // Serial.println(WiFi.softAPIP());         // Send the IP address of the ESP8266 to the computer
       server.on ( "/", HTTP_handleRoot );
     server.onNotFound ( HTTP_handleRoot );
     server.begin();  
}
bool state = false;
void loop() {
  server.handleClient();
   delay(50);
//   Serial.println("1");
   
//   delay(3000);
//   Serial.println ("0");
//   digitalWrite(LED_BUILTIN, LOW);
//   delay(3000);
}

void HTTP_handleRoot(void) {

if( server.hasArg("State") ){
       Serial.println(server.arg("State"));
       state = !state;
       digitalWrite(LED_BUILTIN,state );
  }
  server.send ( 200, "text/html", "" );
}
