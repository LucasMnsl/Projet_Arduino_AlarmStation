#include <Ultrasonic.h>
#ifndef CAPTEURRANGER_HPP_
#define CAPTEURRANGER_HPP_
#include <Arduino.h>
#include "Capteur.h"


class CapteurRanger :public Capteur{
protected:
  long distance;
  
public:
  /*
  @briel: Il retoune la valeur de distance
  @note: --
  @param: --
  @return: long (la valeur de capteur ultrasonic)
  example: Serial.println(capteur.lire_distance());
  */
  long lire_distance(); 

  /*
  @briel: IL lit le son du capteur et change la valeur de distance et l'état.
  @note: la condition de le capteur change l'état est <= 10cm
  @param: class ultrasonic
  @return: --
  example: capteurranger.check_etat();
  */
  void check_etat(Ultrasonic *u); // 

};




#endif