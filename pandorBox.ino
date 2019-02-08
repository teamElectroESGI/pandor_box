#include <rgb_lcd.h>
#include <Wire.h>
#include "DHT.h"
#include <EEPROM.h>

#define DHTPIN 4
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

//create screen object 
rgb_lcd lcd;

// define constante 
const int colorR = 255;
const int colorG = 255;
const int colorB = 255;
const int gasPin = A0;
const int photocellPin = A1;
int photocellReading = 0 ;
int tempMax = 0;
int tempMin = 0;
int epromADR1 = 0;
int epromADR2 = 100;
int EEPROMdata1 = 0;
int EEPROMdata2 = 0;

void setup() {
  
  Serial.begin(9600);
      //setting LCD (ecrans)
      lcd.begin(16, 2);
      lcd.setRGB(colorR, colorG, colorB);
      dht.begin();
      
      //function de demarage 
    StartVal();
      // affiche les dernier min et max enregistrer 
  
    delay(10000);
}

void loop() {
 //set the screen . to 0
  lcd.setCursor(0, 0);
  
    // affiche le co2 en ppm sur l'ecrans 
    lcd.print(analogRead(gasPin));
    lcd.print(" CO By PPM   ,  ");

    
  // recupere les valeur la luminausité 
   photocellReading = analogRead(photocellPin);
  // affiche la valeur sur l'ecrans 
   lcd.print(photocellReading);
   lcd.print(" LUX ");

    
    // passe sur la ligne 2 e l'ecrans 
      lcd.setCursor(0, 1);


     // Read Humidity en PC
  float h = dht.readHumidity();
  // Read temperature as Celsius 
  float t = dht.readTemperature();
   

  // recupere les valeur min et max de temperature and save in eeprom
  if(h>tempMax){
    tempMax = h;
    EEPROM.put(epromADR1, tempMax);
  }
  if(h<tempMin){
   tempMin = h;
   EEPROM.put(epromADR2, tempMin);
  }


   //affiche la temperature  et l'humidité sur l'ecrans 
     lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print(" % ");
  lcd.print(" et ");
  lcd.print(t);
  lcd.print(" C "); 
  lcd.autoscroll();
   delay(1000);
}

/*

Fonction de demarage 

affiche les anciennes temperatures min et max pendant 20s puis repasse a l'affichage classique 

*/
void StartVal(){
  EEPROM.get(epromADR1,EEPROMdata1);
  EEPROM.get(epromADR1,EEPROMdata2);
  lcd.print("Bonjour, demarage en cours");
  lcd.setCursor(0, 1);
  lcd.print("temperature max : "+EEPROMdata1); 
  lcd.print("temperature min : "+EEPROMdata2);
   lcd.autoscroll();
  delay(10000);


}
