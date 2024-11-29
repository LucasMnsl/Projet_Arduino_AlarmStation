#include "Application.h"

//Rappel arguments dans l'ordre : pin LED, pin BUZZER, pin BUTTON 1, pin BUTTON 2
Application myApplication(14, 12, 13, 15);

void setup()
{
  myApplication.init();
}

void loop() 
{
  myApplication.run();
}
