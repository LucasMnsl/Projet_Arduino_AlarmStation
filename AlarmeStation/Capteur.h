/*********************************************************************
 * @file  Capteur.h
 * @author <Haokai LIN>
 * @brief Fichier include de la classe
 *********************************************************************/
#ifndef CAPTEUR_HPP_
#define CAPTEUR_HPP_
#include <Arduino.h>

class Capteur {
protected:
  bool etat = 0; // Indique l'état du capteur (0 ou 1).
  static int nombre_capteur; // Nombre total de capteurs créés.
public:

/*
  @brief: Lit l'état du capteur.
  @note: --
  @param: --
  @return: 0 ou 1 (1 signifie que le capteur est activé).
  Exemple: Serial.println(capteur.lire_etat());
  */
  int lire_etat();

  /*
  @brief: Surcharge l'opérateur ++ pour une future utilisation.
  @note: on n'a pas utilisé cette fonction
  */
  Capteur& operator++();

  /*
  @brief: Retourne le nombre total de capteurs créés.
  @note: La variable est statique et partagée.
  @param: --
  @return: Nombre total de capteurs (int).
  */
  int lire_nombre_capteur();

  /*
  @brief: Réinitialise l'état du capteur.
  @note: Met l'état à 0.
  @param: --
  @return: --
  */
  void reset();
};


#endif
