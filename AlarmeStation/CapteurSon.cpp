#include "CapteurSon.h"
#include "Capteur.h"

CapteurSon::CapteurSon(int limit, int pin){
  l = limit;
  pinson = pin;
  nombre_capteur++;
}


long CapteurSon::lire_sound(){
  return sound;
}



void CapteurSon::check_etat(){
  delay(100);
  sound = analogRead(pinson);
  if (sound > l){
    etat = 1;
  }
}
