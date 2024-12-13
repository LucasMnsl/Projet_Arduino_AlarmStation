/*********************************************************************
 * @file  CapteurRanger.h
 * @author <Haokai LIN>
 * @brief Fichier include de la classe
 *********************************************************************/
#ifndef CAPTEURRANGER_HPP_
#define CAPTEURRANGER_HPP_
#include <Arduino.h>
#include "Capteur.h"
#include "Ultrasonic.h"

class CapteurRanger : public Capteur {
protected:
  long distance; // Distance mesurée par le capteur ultrasonique.
  int limit;     // Limite de distance pour déclencher le capteur.
  int port;      // Port utilisé par le capteur.
public:

  /*
  @brief: Initialise le capteur avec une limite et un port.
  @note: Valide uniquement les ports 2, 12, 14, et 15.
  @param: int l - Limite de distance.
          int p - Port utilisé.
  @return: --
  Exemple: CapteurRanger ranger(60, 12);
  */
  CapteurRanger(int l, int p);

  /*
  @brief: Lit le port utilisé par le capteur.
  @note: --
  @param: --
  @return: Port (int).
  */
  int lire_port();

  /*
  @brief: Retourne la distance mesurée.
  @note: --
  @param: --
  @return: Distance mesurée (long).
  Exemple: Serial.println(ranger.lire_distance());
  */
  long lire_distance();

  /*
  @brief: Vérifie et met à jour l'état en fonction de la distance mesurée.
  @note: Si la distance est inférieure ou égale à la limite, l'état passe à 1.
  @param: Ultrasonic *U - Instance de la classe Ultrasonic.
  @return: --
  Exemple: ranger.check_etat(&ultrasonic);
  */
  void check_etat(Ultrasonic *U);

  /*
  @brief: Modifie la limite de distance du capteur.
  @note: --
  @param: int new_limit - Nouvelle limite.
  @return: --
  */
  void set_limit(int new_limit);

  /*
  @brief: Retourne la limite actuelle du capteur.
  @note: --
  @param: --
  @return: Limite (int).
  */
  int lire_limit();
};

#endif
