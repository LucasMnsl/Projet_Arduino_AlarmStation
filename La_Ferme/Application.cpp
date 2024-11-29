

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
  U = new Ultrasonic(Porte);
}
  
Application::~Application()
{
  delete S;
  delete R;
}  

void Application::init(void)
{
  Serial.begin(9600);
  S = new CapteurSon(13);
  S++;
  R = new CapteurRanger(20);
  R++;
  S->lire_nombre_capteur();
}


void Application::run(void)
{
  S->check_etat();
  R->check_etat(U);
  if((S->lire_etat() & R->lire_etat() ) ==1){
    Serial.print("sound: ");
    Serial.println(S->lire_sound());
    Serial.print("distance: ");
    Serial.println(R->lire_distance());
  }

    
  delay(50);
}
