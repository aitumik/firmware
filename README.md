# Humidity and Temperature Firmware
This is the firmware that will be flashed on esp8266 mcu and that will be reading the temperature and humidity

> Note because of demonstration purposes the firmware is set to send the
> humidity and the temperature after every 1 second but In real scenarios we
> will set the firmware to send data after 30 minutes and average for the whole
> week or whole day 

## Setup
### Requirements
* esp8266 mcu (or any other arv mcu provided that it can access the internet)
  like the one below
  ![esp_image](/screenshots/esp8266.png)
* A breadboard
* Jumper cables
* DHT11 humidity and temperature sensor
* A usb cable for powering the mcu

### Instructions(Hardware)
* Mount the mcu on the board at the center as shown in the image below
![esp mounted](/screenshots/espmounted.png)
* Mount the DHT11 humidity and temperature sensor on the bread board as show
  below
![dht_mounted](/screenshots/dhtmounted.png)
* Take one of the gpio pins and connect it to the data terminal on the dht11
sendor
* Connect the voltage(3.3v) pin to the the vcc terminal on the dht11 sensor
* Connect the esp8266 ground(GND) to the dht11 sensor ground
* Connect the cable to any power source

### Instructions(Software)
Make sure you have the following:
  * PlatformIO or Arduino IDE with esp8266 Adafruit capability for compiling
  * esptool for flashing
  * And a data cable for connection your computer with the board
  * I would advise you to install PlatformIO extension on vscode
Clone the project from github
```bash
git clone git@github.com:aitumik/firmware.git && cd firmware
```
Change the following in your code
```c
String ssid = "your ssid";
String password = "your password";
```
Build the project
```bash
pio run --target upload
```
Now if the [API](https://github.com/aitumik/firmware-api) is up and running
either on the same network with the firmware or just a remote server that the
firmware can reach, then you should be able to receive requests from the mcu

Example in screenshot
![Example](/screenshots/data.png)

## License
[MIT](http://google.com=?MIT")
