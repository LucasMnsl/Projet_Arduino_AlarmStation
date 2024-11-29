#include <Ultrasonic.h>
#include "Application.h"
#include "Capteur.h"
#include "CapteurSon.h"
#include "CapteurRanger.h"
#include <Arduino.h>

Application myapplication(13);

void setup() 
{

  myapplication.init();
  
}

void loop() 
{
  myapplication.run();
}

