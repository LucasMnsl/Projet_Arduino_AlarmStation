#include "Ultrasonic.h"
#include "Capteur.h"
#include "CapteurRanger.h"

CapteurRanger::CapteurRanger(int l,int p){
  limit = l;
  if ((p == 2) or (p == 12) or (p == 14) or (p == 15)){
    port = p;
  }
  else{
    Serial.print("port incorret");
  }
  nombre_capteur++;
}


long CapteurRanger::lire_distance(){
  return distance;
}

void CapteurRanger::check_etat(Ultrasonic *U){
  distance = U->MeasureInCentimeters(); 
  if (distance <= limit){
    etat = 1;
  }
}

int CapteurRanger::lire_port(){
  return port;
}

void CapteurRanger::set_limit(int new_limit) {
    limit = new_limit;
}

int CapteurRanger::lire_limit(){
  return limit;
}

