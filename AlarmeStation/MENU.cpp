/*********************************************************************
 * @file  LED.cpp
 * @author <MANSILHA Lucas mansilha@insa-toulouse.fr>
 * @brief Fichier source de la classe
 *********************************************************************/
#include <Arduino.h>
#include "Menu.h"

MENU::MENU(){
  
};

MENU::MENU(int pin1, int pin2){
  pinB1=pin1;
  pinB2=pin2;
  etat=1;
  monLCD.begin(16, 2);
  monLCD.setRGB(50, 50, 255);
  pinMode(pinB1, INPUT);
  pinMode(pinB2, INPUT);
  Serial.println("*** Objet Menu créé, pin écran=I2C, pin bouton 1="+String(pinB1)+", pin bouton 2="+String(pinB2)+" ***");
}

MENU::~MENU(){
  Serial.println("*** Objet Menu détruit, pin écran=I2C, pin bouton 1="+String(pinB1)+", pin bouton 2="+String(pinB2)+" ***");
}

void MENU::afficherMenu(BUZZER *leBUZZER, LED *laLED){
  switch (etat){
    case 1 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Station alarme");
      monLCD.setCursor(0, 1);
      monLCD.print("->Reglage");
      break;
    case 10 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Reglage");
      monLCD.setCursor(0, 1);
      monLCD.print("->Reglage f1");
      break;
    case 100 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Reglage f1 :");
      monLCD.setCursor(3, 1);
      monLCD.print(String(leBUZZER->getFreq1()));
      break;
    case 11 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Reglage");
      monLCD.setCursor(0, 1);
      monLCD.print("->Reglage f2");
      break;
    case 110 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Reglage f2 :");
      monLCD.setCursor(3, 1);
      monLCD.print(String(leBUZZER->getFreq2()));
      break;
    case 12 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Reglage");
      monLCD.setCursor(0, 1);
      monLCD.print("->Reglage delai");
      break;
    case 120 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Reglage delai :");
      monLCD.setCursor(3, 1);
      monLCD.print(String(leBUZZER->getDeltaMillis()));
      break;
    case 2 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Station alarme");
      monLCD.setCursor(0, 1);
      monLCD.print("->Test alarme");
      break;
    case 20 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Test alarme");
      monLCD.setCursor(0, 1);
      monLCD.print("->Test LED");
      break;
    case 21 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Test alarme");
      monLCD.setCursor(0, 1);
      monLCD.print("->Test BUZZER");
      break;
  }
}

void MENU::checkButtons(BUZZER *leBUZZER, LED *laLED){
    
    if (leBUZZER->getEtat()){
      leBUZZER->turnOn();
    }
  
    currentValueB1=digitalRead(pinB1);
    currentValueB2=digitalRead(pinB2);
    Serial.println(String(etat));
    if (currentValueB1==1 and pastValueB1==0 and currentValueB2==0) {
      pastValueB1=1;
      if(etat==1 or etat==20 or etat==10 or etat==11) etat++;
      else if (etat==12) etat=10;
      else if (etat==2) etat=1;
      else if (etat==21) etat=20;
    }
    else if (currentValueB1==0){
      pastValueB1=0;
    }

    if (currentValueB2==1 and pastValueB2==0 and currentValueB1==0) {
      pastValueB2=1;
      if(etat==1) etat=10;
      else if (etat==10) etat=100;
      else if (etat==11) etat=110;
      else if (etat==12) etat=120;
      else if (etat==2) etat=20;
      else if (etat==20){
        if (not(laLED->getEtat())){
          laLED->turnOn();
        }
        else {
          laLED->turnOff();
        }
      }
      else if (etat==21){
        if (not(leBUZZER->getEtat())){
          leBUZZER->turnOn();
        }
        else {
          leBUZZER->turnOff();
        }
      }
    }
    else if (currentValueB2==0){
        pastValueB2=0;
    }

    if (currentValueB1==1 and currentValueB2==1 and pastValueB2==0){
      etat=1;
      pastValueB2=1;
      pastValueB1=1;
    }
}
