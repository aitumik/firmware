#include <Arduino.h>
#include "DHT.h"
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

String api = "http://192.168.0.107:5000/api/v1";

String ssid = "MUGO"; //enter your own ssid here
String password = "mugo2020"; //enter your own password here

DHT dht(4,DHT11);

float getTemp() {
  return dht.readTemperature();
}

float getHumid() {
  return dht.readHumidity();
}

void setup() {
  //baud rate
  Serial.begin(115200);
  dht.begin();

  //setup wifi
  WiFi.begin(ssid,password);

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("..");
  }
  Serial.println("[**]Connected");
}

void loop() {
  
}
