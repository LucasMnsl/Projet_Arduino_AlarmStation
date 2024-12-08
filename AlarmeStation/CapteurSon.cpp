#include "CapteurSon.h"
#include "Capteur.h"

CapteurSon::CapteurSon(int l, int pin){
  limit = l;
  pinson = pin;
  nombre_capteur++;
}


long CapteurSon::lire_sound(){
  return sound;
}

void CapteurSon::set_limit(int new_limit) {
    limit = new_limit;
}

void CapteurSon::check_etat(){
  delay(100);
  sound = analogRead(pinson);
  if (sound > limit){
    etat = 1;
  }
}

int CapteurSon::lire_limit(){
  return limit;
}
