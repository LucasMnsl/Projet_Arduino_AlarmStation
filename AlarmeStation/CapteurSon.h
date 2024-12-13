/*********************************************************************
 * @file  CapteurSon.h
 * @author <Haokai LIN>
 * @brief Fichier include de la classe
 *********************************************************************/
#ifndef CAPTEURSON_HPP_
#define CAPTEURSON_HPP_
#include <Arduino.h>
#include "Capteur.h"

class CapteurSon : public Capteur {
protected:
  long sound;  // Valeur sonore mesurée.
  int limit;   // Limite sonore pour déclencher le capteur.
  int pinson;  // Pin associé au capteur sonore.
public:

  /*
  @brief: Initialise le capteur sonore avec une limite et un pin.
  @note: Par défaut, la limite est 14.
  @param: int l - Limite sonore.
          int pin - Pin du capteur.
  @return: --
  Exemple: CapteurSon son(20, A0);
  */
  CapteurSon(int l, int pin);

  /*
  @brief: Retourne la valeur sonore mesurée.
  @note: --
  @param: --
  @return: Valeur sonore (long).
  Exemple: Serial.println(son.lire_sound());
  */
  long lire_sound();

  /*
  @brief: Vérifie et met à jour l'état en fonction de la valeur sonore.
  @note: Si la valeur est supérieure ou égale à la limite, l'état passe à 1.
  @param: --
  @return: --
  Exemple: son.check_etat();
  */
  void check_etat();

  /*
  @brief: Modifie la limite sonore du capteur.
  @note: --
  @param: int new_limit - Nouvelle limite.
  @return: --
  */
  void set_limit(int new_limit);

  /*
  @brief: Retourne la limite actuelle du capteur sonore.
  @note: --
  @param: --
  @return: Limite (int).
  */
  int lire_limit();
};

#endif