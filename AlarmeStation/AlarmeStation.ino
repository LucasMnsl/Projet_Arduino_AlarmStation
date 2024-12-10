#include "Application.h"

//Rappel arguments dans l'ordre : pin LED, pin BUZZER, pin BUTTON 1, pin BUTTON 2, Port, pinpourSon, limit_son, limit_distance
Application myApplication(14, 0, 13, 15, 12, A0, 30, 30);

void setup()
{
  myApplication.init();
}

void loop() 
{
  myApplication.run();
}
