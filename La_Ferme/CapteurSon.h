#ifndef CAPTEURSON_HPP_
#define CAPTEURSON_HPP_
#include <Arduino.h>
#include "Capteur.h"

class CapteurSon :public Capteur{
protected:
  long sound;
  int l;
  int pinson = A0;
public:

  CapteurSon(int limit = 14);

  /*
  @briel: Il retoune la valeur de sound
  @note: --
  @param: --
  @return: long (la valeur de capteur sound)
  example: Serial.println(capteur.lire_sound());
  */
  long lire_sound(); 

  /*
  @briel: IL lit le son du capteur et change la valeur de sound et l'état.
  @note: la condition de le capteur change l'état est >= 14
  @param: --
  @return: --
  example: capteurranger.check_etat();
  */
  void check_etat(); 

};



#endif

