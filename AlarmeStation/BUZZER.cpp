/*********************************************************************
 * @file  BUZZER.cpp
 * @author <MANSILHA Lucas mansilha@insa-toulouse.fr>
 * @brief Fichier source de la classe
 *********************************************************************/
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

bool BUZZER::getEtat(){
  return etat;
}

int BUZZER::getFreq1(){
  return freq1;
}

int BUZZER::getFreq2(){
  return freq2;
}

int BUZZER::getDeltaMillis(){
  return deltaMillis;
}

void BUZZER::setFreq1(int f){
  freq1=f;
}

void BUZZER::setFreq2(int f){
  freq2=f;
}

void BUZZER::setDeltaMillis(int t){
  deltaMillis=t;
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
  if (not(etat)){
    etat=true;
    Serial.println("--- BUZZER ON ---");
  }
  
}

void BUZZER::turnOff(){
  digitalWrite(pinBUZZER, LOW);
  etat=false;
  Serial.println("--- BUZZER OFF ---");
}
