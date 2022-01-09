#include <Wire.h> 
#include "dht.h"
#include <LiquidCrystal_I2C.h>
dht DHT;
// Set the LCD address to 0x27 for a 16 chars and 2 line display
// SDA - A4
// SCL - A5

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
  
  lcd.begin();
  lcd.backlight();
 // Serial.begin(9600);
  delay(500);//Delay to let system boot
 // Serial.println("DHT11 Humidity & temperature Sensor\n\n");
 // delay(1000);//Wait before accessing Sensor
}

void loop()
{  
   DHT.read11(A1);
   lcd.setCursor(0,0);
   lcd.print((String)"humidity: " + DHT.humidity + "%");
 //  lcd.scrollDisplayLeft();
   lcd.setCursor(0,1);
   lcd.print((String)"temprature: " + DHT.temperature + "C");
   delay(300);
  // lcd.setCursor(0,2);
 //  lcd.print("hello!");
  // Do nothing here...
}
