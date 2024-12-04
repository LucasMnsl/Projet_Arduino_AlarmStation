/*********************************************************************
 * @file  LED.h
 * @author <MANSILHA Lucas mansilha@insa-toulouse.fr>
 * @brief Fichier include de la classe
 *********************************************************************/
#ifndef LED_H_
#define LED_H_

/**
 * @class LED
 * @brief Classe pour gérer une LED, permettant de l'allumer, l'éteindre
 *        et configurer des paramètres comme un délai à l'état haut.
 */
class LED {
  private :
  
    bool etat;                        /**< État actuel de la LED (true = activée, false = désactviée). */
    int pinLED;                       /**< Numéro de la broche à laquelle la LED est connectée. */
    int delai;                        /**< Délai (en millisecondes) à l'état haut de la LED. */
    bool isHigh;                      /**< Indique si la LED est à l'état HAUT (HIGH). */
    unsigned long lastMillis = 0;     /**< Dernière valeur enregistrée de millis() pour le timing. */
    unsigned long currentMillis = 0;  /**< Valeur actuelle de millis() utilisée pour le timing. */
    
  public :

     /**
     * @brief Constructeur par défaut de la classe LED.
     * Initialise les paramètres de la LED sans spécifier de broche.
     * La led alors utilisée est la led builtin.
     * Le delai par défaut est 300ms.
     * isHigh est initialisé à l'état bas.
     */
    LED();

     /**
     * @brief Constructeur avec initialisation de la broche de la LED.
     * @param pin Numéro de la broche à laquelle la LED est connectée.
     * Le delai par défaut est 300ms.
     * isHigh est initialisé à l'état bas.
     */
    LED(int pin);

     /**
     * @brief Destructeur de la classe LED.
     */
    ~LED();

     /**
     * @brief Permet de récupérer l'état actuel de la LED.
     * @return true si la LED est activée, false si elle est désactivée.
     */
    bool getEtat();

     /**
     * @brief Permet de récupérer le délai actuel configuré pour la LED.
     * @return Le délai (en millisecondes).
     */
    int getDelai();

    /**
     * @brief Définit un nouveau délai pour la LED.
     * @param t Le nouveau délai (en millisecondes).
     */
    void setDelai(int t);

     /**
     * @brief Fait clignoter la LED en fonction du delai.
     */
    void turnOn();

     /**
     * @brief Éteint la LED.
     */
    void turnOff();
};

#endif
