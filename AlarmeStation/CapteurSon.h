#ifndef CAPTEURSON_HPP_
#define CAPTEURSON_HPP_
#include <Arduino.h>
#include "Capteur.h"

class CapteurSon :public Capteur{
protected:
  long sound;
  int limit;
  int pinson;
public:


  /*
  @briel: Il initiale le limit de sound dont le capteur se déclenche
  @note: le limit par defaut est 14
  @param: int limit
  @return: --
  example: CapteurSon S(15)
  */
  CapteurSon(int l , int pin );

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

  void set_limit(int new_limit);

  int lire_limit();

};



#endif

