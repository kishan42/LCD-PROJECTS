#include<Wire.h>
#include<Keypad.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

const byte row = 4;
const byte col = 4;
String op;
int a[50];
int i = 0;
 

char hexaKeys[row][col] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '%'},
  {'*', '0', '=', '/'}
};

byte rowPins[row] = {9, 8, 7, 6};
byte colPins[col] = {5, 4, 3, 2};




Keypad cpad = Keypad(makeKeymap(hexaKeys),rowPins,colPins,row,col);

void setup() {
  // put your setup code here, to run once:
   lcd.begin();
   lcd.backlight();
   lcd.print("enter operation :");
   delay(500);
   lcd.clear();
   
}

void loop() {
  // put your main code here, to run repeatedly:
    
    char key = cpad.getKey();
     if(key == '1' ||key == '2' ||key == '3' ||key == '4' ||key == '5' ||key == '6' ||key == '7' ||key == '8' ||key == '9'){ 
       lcd.print(key);
       a[i] = a[i]*10 + (key - '0');
      
   //  lcd.setCursor(0,1); 
    }
    
    if(key == '*' ||key == '/' ||key == '-' ||key == '+' ||key == '%' ){    
      op = String(key);
      lcd.print(op);  
      i++;
    }
     
     if(key == '='){
      lcd.clear();
     lcd.setCursor(5,1);
     // lcd.print(a[0] + a[i]);
       if(op == "-"){
      //  mine(a[i],a[0]); 
        lcd.print((String)a[0] + '-' + a[i] + '=' + (a[0] - a[i]));
         lcd.setCursor(0,0);
         for(int j=0;j<=i;j++){
        a[j] = 0;
      }
         i = 0;
      }
     if(op == "+"){
         // sum(a[0],a[i]);
         lcd.print((String)a[0] + '+' + a[i] + '=' + (a[0] + a[i]));
          lcd.setCursor(0,0);
          for(int j=0;j<=i;j++){
        a[j] = 0;
      }
         i =0;
      }
      if(op == "*"){
        lcd.print((String)a[0] + '*' + a[i] + '=' + (a[0] * a[i]));
         lcd.setCursor(0,0);
         for(int j=0;j<=i;j++){
        a[j] = 0;
      }
         i=0;
       }
      if(op == "/"){
        lcd.print((String)a[0] + '/' + a[i] + '=' + (float(a[0]) /  float(a[i])));
         lcd.setCursor(0,0);
         for(int j=0;j<=i;j++){
        a[j] = 0;
      }
         i=0;
      }
       if(op == "%"){
        lcd.print((String)a[0] + '%' + a[i] + '=' + (a[0] % a[i]));
         lcd.setCursor(0,0);
         for(int j=0;j<=i;j++){
           a[j] = 0;
          }
         i=0;
       }           
     }     
}
