#include "CapteurSon.h"
#include "Capteur.h"

CapteurSon::CapteurSon(int limit){
  l = limit;
}


long CapteurSon::lire_sound(){
  return sound;
}



void CapteurSon::check_etat(){
  sound = analogRead(pinson);
  if (sound > l){
    etat = 1;
  }
  else{
    etat = 0;
  }
}
