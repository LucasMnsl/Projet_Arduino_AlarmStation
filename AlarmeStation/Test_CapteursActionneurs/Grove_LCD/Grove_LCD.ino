#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 50;
const int colorG = 50;
const int colorB = 255;

const int BUTTON=14;
int currentValue=0;
int pastValue=0;

int menu=1;

void setup() 
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB);
    // Print a message to the LCD.
    pinMode(BUTTON, INPUT);
    delay(1000);
    Serial.begin(9600);
}

void loop() 
{
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    lcd.setCursor(0, 0);
    lcd.print("Station alarme");
    if (menu==1){
      lcd.setCursor(0, 1);
      lcd.print("-> Réglages");
    }
    else if (menu==2) {
      lcd.setCursor(0, 1);
      lcd.print("-> Test alarme");
    }
    currentValue=digitalRead(BUTTON);
    Serial.println(currentValue);
    if (currentValue==1 and pastValue==0) {
      pastValue=1;
      if(menu<2){
        menu++;
      }
      else {
        menu=1;
      }
    }
    else if (currentValue==0){
        pastValue=0;
    }
  
    delay(1000);
}
