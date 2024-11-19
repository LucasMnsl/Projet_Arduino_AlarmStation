/*********************************************************************
 * @file  Apllication.cpp
 * @author <MANSILHA Lucas mansilha@insa-toulouse.fr, LIN Hoakai halin@insa-toulouse.fr>
 * @brief Fichier source de l'application
 *********************************************************************/
#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "LED.h"
#include "BUZZER.h"

/**
  * @class Application
  * @brief Classe qui gère l'ensemble des composants de l'alarme 
*/    
class Application
{
  private :
    int maPinLED;
    LED *maLED;         //pointeur sur un objet LED permet a ce que toute la classe puisse accéder à l'objet mais sans le créer maintenant
    int maPinBUZZER;
    BUZZER *monBUZZER;
  public :
  
    /**
     * @fn Application();
     * @brief Constructeur par defaut
    */  
    Application();

    /**
      * @fn Application(int pinPourLED, int pinPourBUZZER);
      * @brief Constructeur principal qui affecte les variables dédiée au pins et initialise les pointeurs d'objets
    */  
    Application(int pinPourLED, int pinPourBUZZER);
    
    /**
     * @fn ~Application();
     * @brief Destructeur, il détruit les pointeurs utilisés précédememnt
    */    
    ~Application();
        
    /**
     * @fn void init(void)
     * @brief Fonction d'initialisation de l'application
    */
    void init(void);
    
    /**
     * @fn void run(void)
     * @brief Fonction de lancement de l'application
    */
    void run(void);
};
#endif
