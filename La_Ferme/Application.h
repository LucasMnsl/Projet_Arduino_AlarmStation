/*********************************************************************
 * @file  Apllication.h
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier header de l'application
 *********************************************************************/
#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "Capteur.h"
#include "CapteurSon.h"
#include "CapteurRanger.h"
#include "Ultrasonic.h"
/**
  * @class Application
  * @brief Classe Application 
*/    
class Application
{
  private: 
    CapteurSon *S;
    CapteurRanger *R;
    Ultrasonic *U;

  public :
  
    /**
     * @fn Application();
     * @brief Constructeur par defaut
    */    
    Application(int Porte);
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