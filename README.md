# Pandore Box

## Description 

Box project which that retrieves several pieces of information from the room environnement

Why ?

For improved the quality of life in the workspace and because it's fun!!!.

## Code

### Librairies used

- include <rgb_lcd.h> : for LCD screen
- include <Wire.h> : for communicated with I2C / TWI devices
- include "DHT.h" : for temperature and humidity sensor
- include <EEPROM.h> : for used internal memory to Arduino

### Functions used

- setup() : function for started application
- loop() : function to peform actions
- StartVal() : function for displayed the old min and max temperatures for 20s 		 and then switches back to the classic display
 
