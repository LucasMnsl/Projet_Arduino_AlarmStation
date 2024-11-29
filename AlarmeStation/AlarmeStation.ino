#include "Application.h"

//Rappel arguments dans l'ordre : pin LED, pin BUZZERè
Application myApplication(14, 12, 13, 15);

void setup()
{
  myApplication.init();
}

void loop() 
{
  myApplication.run();
}
