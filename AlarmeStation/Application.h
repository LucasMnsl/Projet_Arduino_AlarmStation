/*********************************************************************
 * @file  Apllication.h
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier header de l'application
 *********************************************************************/
#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "LED.h"
#include "BUZZER.h"

/**
  * @class Application
  * @brief Classe Application 
*/    
class Application
{
  private :
    int maPinLED;
    LED *maLED;
    int maPinBUZZER;
    BUZZER *monBUZZER;
  public :
    /**
     * @fn Application();
     * @brief Constructeur par defaut
    */    
    Application(int pinPourLED, int pinPourBUZZER);
    /**
     * @fn Application();
     * @brief Destructeur
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
