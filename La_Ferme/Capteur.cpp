#include "Capteur.h"

int Capteur::nombre_capteur = 0;

int Capteur::lire_nombre_capteur(){
  return nombre_capteur;
}

int Capteur::lire_etat(){
  return etat;
}

Capteur& Capteur::operator++(){
  nombre_capteur++;
  return *this;
}

