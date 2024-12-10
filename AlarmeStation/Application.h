/*********************************************************************
 * @file  Apllication.cpp
 * @author <MANSILHA Lucas mansilha@insa-toulouse.fr, LIN Hoakai halin@insa-toulouse.fr>
 * @brief Fichier source de l'application
 *********************************************************************/
#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "LED.h"
#include "BUZZER.h"
#include "MENU.h"
#include "CapteurSon.h"
#include "CapteurRanger.h"


/**
  * @class Application
  * @brief Classe qui gère l'ensemble des composants de l'alarme 
*/    
class Application
{
  private :
    int maPinLED;
    int maPinBUZZER;
    int maPinBUTTON1;
    int maPinBUTTON2;
    int maPortUltrasonic;
    int maPinson;
    int maLimitSon;
    int maLimitDistance;


    MENU *monMENU;   
    LED *maLED;         //pointeur sur un objet LED permet a ce que toute la classe puisse accéder à l'objet mais sans le créer maintenant
    BUZZER *monBUZZER;
    CapteurSon *maCapteurSon;
    CapteurRanger *maCapteurRanger; 
    Ultrasonic *ultrasonic;
    
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
    Application(int pinPourLED, int pinPourBUZZER, int pinPourBUTTON1, int pinPourBUTTON2, int Port, int pinpourSon, int limit_son, int limit_distance);
    
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
