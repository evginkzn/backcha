# BackCha 
## Overview
MVP firmware for plant monitoring device. The device maked of CPU board - NodeMCU v3 (Wemos), and three types of sensors: brightness, soil moisture, and temperature.

### Repository structure
- backcha - main directory with firmware source
- ds18b20_test - test sketch for the temperature sensor testing 
- mqtt_esp8266_test - test sketch for the MQTT testing
- node_mcu_soil_test - test of the soil moisture sensor

### Build requirements
##### Arduino IDE
For building and running the firmware, need to install MCU board specification. For this go to File→Preferences type to input box  Additional Boards Manager URLs this link http://arduino.esp8266.com/stable/package_esp8266com_index.json
After this, go to the Tools→Board →Boards Manager and find esp8266 package. Install this.
##### 1.1 Arduino libraries to be installed (some libraries may be not need, it just my configuration):
• OneWire
• DallasTemperature
• Adafruit Unified Sensor
• Adafruit TSL2591 Library
• Adafruit SleepyDog Library
• Adafruit MQTT Library
• Adafruit FONA Library
• Adafruit Circuit Playgroud
• PubSubClient
• PubSubClientTools

### Some comments for the firmware sources
Each object of the firmware defined in own source file. 
Internal variable with actual value will update for time defined from ConversionTime const (in future, if it need, possible create adjustable variable). For this need periodically call the run() method.
Timeout of pushing to the MQTT server defined in loop() method, now it qual 2000 ms.

Settings of MQTT connection defined in mqttService.cpp file as constants.