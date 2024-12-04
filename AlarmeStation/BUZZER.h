/*********************************************************************
 * @file  BUZZER.h
 * @author <MANSILHA Lucas mansilha@insa-toulouse.fr>
 * @brief Fichier include de la classe
 *********************************************************************/
#ifndef BUZZER_H_
#define BUZZER_H_

/**
 * @class BUZZER
 * @brief Classe pour gérer un buzzer, permettant de configurer et de
 *        les fréquences, les délais et l'état du buzzer.
 */
class BUZZER {
  private :

    bool etat;                        /**< État actuel du buzzer (true = actif, false = inactif). */
    int pinBUZZER;                    /**< Numéro de la broche à laquelle le buzzer est connecté. */
    int freq1;                        /**< Première fréquence pour le buzzer. */
    int freq2;                        /**< Deuxième fréquence pour le buzzer. */
    int delai;                        /**< Délai (en millisecondes) pour alterner entre les fréquences. */
    bool isFreq1;                     /**< Indique si la fréquence actuelle est freq1 (true) ou freq2 (false). */
    unsigned long lastMillis = 0;     /**< Dernière valeur enregistrée de millis() pour le timing. */
    unsigned long currentMillis = 0;  /**< Valeur actuelle de millis() utilisée pour le timing. */
    
  public :

     /**
     * @brief Constructeur par défaut de la classe BUZZER.
     * Suppose que le buzzer est connecté à la broche 14.
     * Affecte des valeurs par défaut à frequence 1 : 800Hz, frequence 2 : 1200Hz, delai : 300ms, isFreq1 : False
     */
    BUZZER();

     /**
     * @brief Constructeur avec initialisation de la broche du buzzer.
     * @param pin Numéro de la broche à laquelle le buzzer est connecté.
     * Affecte des valeurs par défaut à frequence 1 : 800Hz, frequence 2 : 1200Hz, delai : 300ms, isFreq1 : False
     */
    BUZZER(int pin);

     /**
     * @brief Destructeur de la classe BUZZER.
     */
    ~BUZZER();

     /**
     * @brief Permet de récupérer l'état actuel du buzzer.
     * @return true si le buzzer est actif, false s'il est inactif.
     */
    bool getEtat();

     /**
     * @brief Permet de récupérer la première fréquence configurée pour le buzzer.
     * @return La première fréquence (en Hertz).
     */
    int getFreq1();

     /**
     * @brief Permet de récupérer la deuxième fréquence configurée pour le buzzer.
     * @return La deuxième fréquence (en Hertz).
     */
    int getFreq2();

     /**
     * @brief Permet de récupérer le delai configuré pour le buzzer.
     * @return le delai (en millisecondes).
     */
    int getDelai();

     /**
     * @brief Modifie la première fréquence du buzzer.
     * @param f La première fréquence (en Hertz).
     */
    void setFreq1(int f);

     /**
     * @brief Modifie la deuxième fréquence du buzzer.
     * @param f La deuxième fréquence (en Hertz).
     */
    void setFreq2(int f);

     /**
     * @brief Modifie le delai du buzzer.
     * @param t le delai (en milliseconde).
     */
    void setDelai(int t);

     /**
     * @brief Active le buzzer.
     */
    void turnOn();

     /**
     * @brief Désactive le buzzer.
     */
    void turnOff();
};

#endif
