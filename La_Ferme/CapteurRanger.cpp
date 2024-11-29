#include "Ultrasonic.h"
#include "Capteur.h"
#include "CapteurRanger.h"


long CapteurRanger::lire_distance(){
  return distance;
}

void CapteurRanger::check_etat(Ultrasonic *u){
  distance = u->MeasureInCentimeters();
  if (distance <=10){
    etat = 1;
  }
  else{
    etat = 0;
  }

}

