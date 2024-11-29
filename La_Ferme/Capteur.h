#ifndef CAPTEUR_HPP_
#define CAPTEUR_HPP_
#include <Arduino.h>

class Capteur {
protected:
  bool etat = 0;
  static int nombre_capteur;
public:

/*
@briel: il lit que l'état de capteur
@note: --
@param: --
@return: 0 ou 1(1 pour capateur se déclenche)
example: Serial.println(capteur.lire_etat());
*/
  int lire_etat();


  Capteur& operator++();
  


};


#endif

