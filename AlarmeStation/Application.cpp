/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include <Arduino.h>
#include "Application.h"


Application::Application(int pinPourLED, int pinPourBUZZER)
{
  maPinLED=pinPourLED;
  maLED=nullptr;
  maPinBUZZER=pinPourBUZZER;
  monBUZZER=nullptr;
}
  
Application::~Application()
{
  delete maLED;
  delete monBUZZER;
}  

void Application::init(void)
{
  delay(5000); //5sec pour lancer le moniteur série
  Serial.begin(9600);
  maLED=new LED(maPinLED);
  delay(1000);
  monBUZZER=new BUZZER(maPinBUZZER);
  delay(1000);
}


void Application::run(void)
{
  maLED->turnOn();
  monBUZZER->turnOn();
  delay(10000);
}
