/*********************************************************************
 * @file  Apllication.cpp
 * @author 
 *        MANSILHA Lucas <mansilha@insa-toulouse.fr> 
 *        LIN Hoakai <halin@insa-toulouse.fr>
 * @brief Fichier source de l'application
 *********************************************************************/
#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "LED.h"
#include "BUZZER.h"
#include "MENU.h"

/**
 * @class Application
 * @brief Classe principale qui orchestre les interactions entre les différents 
 *        composants d'une alarme : LED, buzzer et menu utilisateur.
 */   
class Application
{
  private :
  
    int maPinBUTTON1;       /**< Numéro de la broche associée au bouton 1. */
    int maPinBUTTON2;       /**< Numéro de la broche associée au bouton 2. */
    MENU *monMENU;          /**< Pointeur vers un objet MENU pour gérer l'interface utilisateur. */

    int maPinLED;           /**< Numéro de la broche associée à la LED. */
    LED *maLED;             /**< Pointeur vers un objet LED, pour permettre un accès global à l'objet sans le créer immédiatement. */

    int maPinBUZZER;        /**< Numéro de la broche associée au buzzer. */
    BUZZER *monBUZZER;      /**< Pointeur vers un objet BUZZER, pour permettre un accès global à l'objet sans le créer immédiatement. */
    

    //pointeur sur un objet permet a ce que toute la classe puisse accéder à l'objet mais sans le créer maintenant car le constructeur sera appelé en dehors du setup
    
  public :
  
    /**
     * @brief Constructeur par défaut de la classe Application.
     * Ne fait rien.
     */
    Application();

    /**
     * @brief Constructeur principal qui initialise les broches et les pointeurs pour les composants.
     * @param pinPourLED Numéro de la broche pour la LED.
     * @param pinPourBUZZER Numéro de la broche pour le buzzer.
     * @param pinPourBUTTON1 Numéro de la broche pour le bouton 1.
     * @param pinPourBUTTON2 Numéro de la broche pour le bouton 2.
     * Les pointeurs sont initialisé à NULL pour éviter de créer des objets en dehors du setup du fichier .ino
     */
    Application(int pinPourLED, int pinPourBUZZER, int pinPourBUTTON1, int pinPourBUTTON2);
    
    /**
     * @brief Destructeur de la classe Application.
     * Libère les ressources allouées dynamiquement, notamment les pointeurs des objets LED, BUZZER et MENU.
     */   
    ~Application();
        
    /**
     * @brief Initialise l'application.
     * Configure les composants nécessaires pour leur utilisation notamment 
     *      la création des objets et initialisation de la liaison série.
     */
    void init(void);
    
    /**
     * @brief Démarre l'application.
     * Gère la boucle principale de l'application et coordonne les interactions entre les différents composants.
     */
    void run(void);
};
#endif
