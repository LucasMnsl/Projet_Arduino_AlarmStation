

/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"
#include "Capteur.h"
#include "CapteurSon.h"
#include "CapteurRanger.h"
#include "Ultrasonic.h"




Application::Application(int Porte)
{
}
  
Application::~Application()
{
  delete S;
  delete R;
}  

void Application::init(void)
{
  Serial.begin(115200);
  S = new CapteurSon(12,A0);
  R = new CapteurRanger(50,12);
  
}


void Application::run(void)
{
  //Serial.println(R->lire_port()); 
  ultrasonic = new Ultrasonic(R->lire_port());
  //Serial.println(S->lire_nombre_capteur());
  S->check_etat();
  R->check_etat(ultrasonic);
  if((S->lire_etat() & R->lire_etat() ) ==1){
    Serial.print("sound: ");
    Serial.println(S->lire_sound());
    Serial.print("distance: ");
    Serial.println(R->lire_distance());
  }
    
  delay(500);
}
