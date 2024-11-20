//Capteur à utiliser avec sa librairie (à télécharger) comme cela :

#include "Ultrasonic.h"

Ultrasonic myLenghtSensor(14);
long distanceInCm=0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  distanceInCm=myLenghtSensor.MeasureInCentimeters();
  Serial.println("Distance of the obstacle : "+String(distanceInCm)+"cm");
  delay(250);
}
