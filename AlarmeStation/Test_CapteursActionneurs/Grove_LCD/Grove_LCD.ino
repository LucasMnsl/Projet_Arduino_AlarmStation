#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 255;
const int colorB = 255;

const int BUTTON1=13;
const int BUTTON2=15;
const int LED=14;
const int BUZZER=12;
int ETAT_LED=LOW;
int ETAT_BUZZER=LOW;
int currentValueB1=0;
int pastValueB1=0;
int currentValueB2=0;
int pastValueB2=0;

int menu=1;

void setup() 
{
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB);
    // Print a message to the LCD.
    pinMode(BUTTON1, INPUT);
    pinMode(BUTTON2, INPUT);
    pinMode(LED, OUTPUT);
    pinMode(BUZZER, OUTPUT);
    delay(1000);
    Serial.begin(9600);
}

void loop() 
{
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    if (menu==1){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Station alarme");
      lcd.setCursor(0, 1);
      lcd.print("-> Reglages");
    }
    else if (menu==2) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Station alarme");
      lcd.setCursor(0, 1);
      lcd.print("-> Test alarme");
    }
    else if (menu==21){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Test alarme");
      lcd.setCursor(0, 1);
      lcd.print("-> Test LED");
      if (ETAT_LED==HIGH){
        lcd.setCursor(15, 1);
        lcd.print("1");
      }else{
        lcd.setCursor(15, 1);
        lcd.print("0");
      }
    }
    else if (menu==22){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Test alarme");
      lcd.setCursor(0, 1);
      lcd.print("-> Test BUZZER");
      if (ETAT_BUZZER==HIGH){
        lcd.setCursor(15, 1);
        lcd.print("1");
      }else{
        lcd.setCursor(15, 1);
        lcd.print("0");
      }
    }
    
    currentValueB1=digitalRead(BUTTON1);
    currentValueB2=digitalRead(BUTTON2);
    Serial.print("Bouton 1 : ");
    Serial.print(currentValueB1);
    Serial.print(" ; ");
    Serial.print("Bouton 2 : ");
    Serial.println(currentValueB2);
    
    if (currentValueB1==1 and pastValueB1==0) {
      pastValueB1=1;
      if(menu==1){
        menu++;
      }
      else if (menu==2){
        menu=1;
      }
      else if (menu==21){
        menu++;
      }
      else if (menu==22){
        menu=21;
      }
    }
    else if (currentValueB1==0){
        pastValueB1=0;
    }

    if (currentValueB2==1 and pastValueB2==0) {
      pastValueB2=1;
      if(menu==1){
        menu=11;
      }
      else if (menu==2){
        menu=21;
      }
      else if (menu==21){
        if (ETAT_LED==LOW){
          ETAT_LED=HIGH;
          digitalWrite(LED, ETAT_LED);
        }
        else {
          ETAT_LED=LOW;
          digitalWrite(LED, ETAT_LED);
        }
        
      }
      else if (menu==22){
        if (ETAT_BUZZER==LOW){
          ETAT_BUZZER=HIGH;
          digitalWrite(BUZZER, ETAT_BUZZER);
        }
        else {
          ETAT_BUZZER=LOW;
          digitalWrite(BUZZER, ETAT_BUZZER);
        }
      }
    }
    else if (currentValueB2==0){
        pastValueB2=0;
    }
  
    delay(100);
}
