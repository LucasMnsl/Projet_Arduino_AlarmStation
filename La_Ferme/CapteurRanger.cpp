#include "Ultrasonic.h"
#include "Capteur.h"
#include "CapteurRanger.h"

CapteurRanger::CapteurRanger(int limit){
  l = limit;
}


long CapteurRanger::lire_distance(){
  return distance;
}

void CapteurRanger::check_etat(Ultrasonic *u){
  distance = u->MeasureInCentimeters();
  if (distance <=l){
    etat = 1;
  }
  else{
    etat = 0;
  }

}

