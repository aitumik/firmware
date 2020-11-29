#include <Arduino.h>
#include "DHT.h"
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

String api = "http://192.168.0.107:5000/api/v1/data";

String ssid = "JOHN"; //enter your own ssid here
String password = "mugo2020"; //enter your own password here

DHT dht(4,DHT11);

float getTemp() {
  return dht.readTemperature();
}

float getHumid() {
  return dht.readHumidity();
}

void postTemperature(float temp) {

}

void setup() {
  //baud rate
  Serial.begin(115200);
  dht.begin();

  //setup wifi
  WiFi.begin(ssid,password);

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("#");
  }
  Serial.println("[**]Connected");
  delay(100);
}

void loop() {
  //get the current humidity and temperature
  float temperature = getTemp();
  float humidity = getHumid();

  //check if the wifi status is connected
  if(WiFi.status() == WL_CONNECTED) {
    HTTPClient client;
    client.begin(api.c_str());

    //add some headers
    client.addHeader("Content-Type","application/json");

    char payload[256];

    sprintf(payload,"{\"temp\":\"%f\",\"humidity\":\"%f\"}",temperature,humidity);

    int statusCode = client.POST((const uint8_t*)payload,strlen(payload));

    if(statusCode > 0) {
      String responseData = client.getString();
      Serial.print(responseData);
    } else {
      Serial.print("An error occured");
      Serial.print(client.getString());
    }
  }
  delay(10000);
}
