/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"


Application::Application() :led1(14)
{
  
  ; 
}
  
Application::~Application()
{
  // Code
  ;
}  

void Application::init(void)
{
  //led1.config(14);
  led1.turnOff();
    ;
}


void Application::run(void)
{
  led1.turnOn();
    ;
}
