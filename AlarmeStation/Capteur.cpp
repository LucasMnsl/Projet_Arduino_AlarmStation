#include "Capteur.h"

int Capteur::nombre_capteur = 0;

int Capteur::lire_nombre_capteur(){
  return nombre_capteur;
}

int Capteur::lire_etat(){
  return etat;
}

void Capteur::reset(){
  etat = 0;
}

