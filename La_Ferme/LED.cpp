#include <iostream>
#include <Arduino.h>
#include "LED.h"

using namespace std;

LED::LED(){
  pinLED=LED_BUILTIN;
  pinMode(pinLED, OUTPUT);
  cout<<"LED créée, pin : BUILT_IN"<<endl;
};

LED::LED(int pin){
  pinLED=pin;
  pinMode(pinLED, OUTPUT);
  cout<<"LED créée, pin : "<<pinLED<<endl;
}

LED::~LED(){
  cout<<"LED supprimée"<<endl;
}

void LED::turnOn(){
  digitalWrite(pinLED, HIGH);
}

void LED::turnOff(){
  digitalWrite(pinLED, LOW);
}

