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
  Serial.begin(9600);
  maCapteurSon = new CapteurSon(maLimitSon, maPinson);
  maCapteurRanger = new CapteurRanger(maLimitDistance,maPortUltrasonic);
  ultrasonic = new Ultrasonic(maCapteurRanger->lire_port());
  maLED=new LED(maPinLED);
  monBUZZER=new BUZZER(maPinBUZZER);
  monMENU=new MENU(maPinBUTTON1, maPinBUTTON2);
}



void Application::run(void)
{
  try{
    maCapteurSon->check_etat();
    maCapteurRanger->check_etat(ultrasonic);

    monMENU->checkButtons(monBUZZER, maLED, maCapteurSon, maCapteurRanger);
    monMENU->afficherMenu(monBUZZER, maLED, maCapteurSon, maCapteurRanger);
  }
  catch (int erreur){
    switch (erreur){
      case 1 : Serial.println("Impossible ce paramètre ne peut pas être négatif");
      default : Serial.println("Interception d'une erreur inconnue");
    }
  }

  delay(50);
}
