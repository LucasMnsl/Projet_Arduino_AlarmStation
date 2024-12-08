/*********************************************************************
 * @file  Apllication.cpp
 * @author <MANSILHA Lucas mansilha@insa-toulouse.fr, LIN Hoakai halin@insa-toulouse.fr>
 * @brief Fichier source de l'application
 *********************************************************************/
#include <Arduino.h>
#include "Application.h"


Application::Application(int pinPourLED, int pinPourBUZZER, int pinPourBUTTON1, int pinPourBUTTON2, int Port, int pinpourSon, int limit_son, int limit_distance)
{
  maPinBUTTON1=pinPourBUTTON1;
  maPinBUTTON2=pinPourBUTTON2;
  monMENU=nullptr;
  maPinLED=pinPourLED;
  maLED=nullptr;
  maPinBUZZER=pinPourBUZZER;
  monBUZZER=nullptr;
  maPortUltrasonic = Port;
  maPinson = pinpourSon;
  maLimitSon = limit_son;
  maLimitDistance = limit_distance;
}
  
Application::~Application()
{
  delete maLED;
  delete monBUZZER;
  delete monMENU;
  delete maCapteurSon;
  delete maCapteurRanger; 
  delete ultrasonic;
}  

void Application::init(void)
{
  maCapteurSon = new CapteurSon(maLimitSon, maPinson);
  maCapteurRanger = new CapteurRanger(maLimitDistance,maPortUltrasonic);
  ultrasonic = new Ultrasonic(maCapteurRanger->lire_port());
  delay(5000);        //5sec pour lancer le moniteur série
  Serial.begin(9600);
  maLED=new LED(maPinLED);
  delay(1000);
  monBUZZER=new BUZZER(maPinBUZZER);
  delay(1000);
  monMENU=new MENU(maPinBUTTON1, maPinBUTTON2);
  delay(1000);
}



void Application::run(void)
{
  maCapteurSon->check_etat();
  maCapteurRanger->check_etat(ultrasonic);
  Serial.print("sound: ");
  Serial.println(maCapteurSon->lire_sound());
  Serial.print("distance: ");
  Serial.println(maCapteurRanger->lire_distance());
  monMENU->checkButtons(monBUZZER, maLED);
  monMENU->afficherMenu(monBUZZER, maLED);
  /*
  maLED->turnOn();
  monBUZZER->turnOn();
  */
  delay(500);
}
