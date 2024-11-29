/*********************************************************************
 * @file  LED.cpp
 * @author <MANSILHA Lucas mansilha@insa-toulouse.fr>
 * @brief Fichier source de la classe
 *********************************************************************/
#include <Arduino.h>
#include "LED.h"


LED::LED(){
  pinLED=LED_BUILTIN;
  pinMode(pinLED, OUTPUT);
  etat=false;
  isHigh=false;
  delai=300;
  Serial.println("--- Objet Led crée, pin = "+String(pinLED)+" ---");
};

LED::LED(int pin){
  pinLED=pin;
  pinMode(pinLED, OUTPUT);
  etat=false;
  isHigh=false;
  delai=300;
  Serial.println("*** Objet Led crée, pin = "+String(pinLED)+" ***");
}

LED::~LED(){
  Serial.println("*** Objet Led détruit, pin = "+String(pinLED)+" ***");
}

bool LED::getEtat(){
   return etat; 
}

int LED::getDelai(){
  return delai;
}

void LED::setDelai(int t){
  delai=t;
}


void LED::turnOn(){
  currentMillis=millis();
  if (currentMillis-lastMillis>=delai){
    if (isHigh){
        digitalWrite(pinLED, HIGH);
    }
    else if (!isHigh){
       digitalWrite(pinLED, LOW);
    }
    isHigh=!isHigh;
    lastMillis=currentMillis;
  }
  if (not(etat)){
    etat=true;
    Serial.println("--- LED ON ---");
  }
}

void LED::turnOff(){
  digitalWrite(pinLED, LOW);
  etat=false;
  Serial.println("--- LED OFF ---");
}
