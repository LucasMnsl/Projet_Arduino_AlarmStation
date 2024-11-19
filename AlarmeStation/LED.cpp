#include <Arduino.h>
#include "LED.h"


LED::LED(){
  pinLED=LED_BUILTIN;
  pinMode(pinLED, OUTPUT);
  etat=false;
  Serial.println("--- Objet Led crée, pin = "+String(pinLED)+" ---");
};

LED::LED(int pin){
  pinLED=pin;
  pinMode(pinLED, OUTPUT);
  etat=false;
  Serial.println("*** Objet Led crée, pin = "+String(pinLED)+" ***");
}

LED::~LED(){
  Serial.println("*** Objet Led détruit, pin = "+String(pinLED)+" ***");
}

void LED::turnOn(){
  digitalWrite(pinLED, HIGH);
  etat=true;
  Serial.println("--- LED ON ---");
}

void LED::turnOff(){
  digitalWrite(pinLED, LOW);
  etat=false;
  Serial.println("--- LED OFF ---");
}
