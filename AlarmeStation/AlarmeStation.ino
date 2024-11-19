#include "Application.h"

//Rappel arguments dans l'ordre : pin LED, pin BUZZER
Application myApplication(14, 12);

void setup()
{
  myApplication.init();
}

void loop() 
{
  myApplication.run();
}
