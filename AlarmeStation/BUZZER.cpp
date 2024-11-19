#include <Arduino.h>
#include "BUZZER.h"


BUZZER::BUZZER(){
  pinBUZZER=14;  //dans le cas ou on ne file pas la pin du buzzer il faudrait lever une erreur en vrai
  pinMode(pinBUZZER, OUTPUT);
  etat=false;
  isFreq1=false;
  Serial.println("--- Objet Buzzer crée, pin = "+String(pinBUZZER)+" ---");
};

BUZZER::BUZZER(int pin){
  pinBUZZER=pin;
  pinMode(pinBUZZER, OUTPUT);
  etat=false;
  isFreq1=false;
  Serial.println("*** Objet Buzzer crée, pin = "+String(pinBUZZER)+" ***");
}

BUZZER::~BUZZER(){
  Serial.println("*** Objet Buzzer détruit, pin = "+String(pinBUZZER)+" ***");
}

void BUZZER::turnOn(){
  currentMillis=millis();
  if (currentMillis-lastMillis>=deltaMillis){
    if (isFreq1){
        tone(pinBUZZER, freq1);
    }
    else if (!isFreq1){
       tone(pinBUZZER, freq2);
    }
    isFreq1=!isFreq1;
    lastMillis=currentMillis;
  }
  etat=true;
  Serial.println("--- BUZZER ON ---");
}

void BUZZER::turnOff(){
  digitalWrite(pinBUZZER, LOW);
  etat=false;
  Serial.println("--- BUZZER OFF ---");
}
