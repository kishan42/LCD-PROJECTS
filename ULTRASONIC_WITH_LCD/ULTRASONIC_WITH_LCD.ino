#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

long duration;
long distance;

// Set the LCD address to 0x27 for a 16 chars and 2 line display
// SDA - A4
// SCL - A5

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
  lcd.begin();
  lcd.backlight();
  pinMode(7,INPUT);
 pinMode(8,OUTPUT);
// lcd.setCursor(0,0);
 //lcd.print("distance :");
}

void loop()
{  
   digitalWrite(8,LOW);
  delayMicroseconds(2);
  digitalWrite(8,HIGH);
  delayMicroseconds(10);

  duration = pulseIn(7,HIGH);

  distance = duration/58.2;

  //Serial.println(distance);

  delay(50);
   lcd.setCursor(0,0);
   lcd.print((String)"distance :" + distance);
  // lcd.scrollDisplayLeft();
  // lcd.setCursor(0,1);
 //  lcd.print(distance);
   delay(300);
   lcd.clear();
  
  // lcd.setCursor(0,2);
 //  lcd.print("hello!");
  // Do nothing here...
}
