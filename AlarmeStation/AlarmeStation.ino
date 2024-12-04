#include "Application.h"

//Rappel arguments dans l'ordre : pin LED, pin BUZZER, pin BUTTON 1, pin BUTTON 2
Application myApplication(14, 12, 13, 15);

void setup()
{
  //initialisation de l'application
  myApplication.init();
}

void loop() 
{
  //mise en marche de l'application
  myApplication.run();
}
