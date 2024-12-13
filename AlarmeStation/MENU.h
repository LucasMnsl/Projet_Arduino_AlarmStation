/*********************************************************************
 * @file  MENU.h
 * @author <MANSILHA Lucas mansilha@insa-toulouse.fr><Haokai LIN>
 * @brief Fichier include de la classe
 *********************************************************************/
#ifndef MENU_H_
#define MENU_H_
#include <Wire.h>
#include <array>
#include <string>
#include "rgb_lcd.h"
#include "BUZZER.h"
#include "LED.h"
#include "CapteurRanger.h"
#include "CapteurSon.h"

/**
 * @class MENU
 * @brief Gère un menu interactif pour un système Arduino en utilisant 
 *        un écran LCD, des boutons et des périphériques comme un buzzer 
 *        et des LEDs.
 */
class MENU {
  private :
  
    rgb_lcd monLCD;         /**< Instance de la classe rgb_lcd pour contrôler l'écran LCD. */
    int pinB1;              /**< Numéro de pin pour le Bouton 1. */
    int pinB2;              /**< Numéro de pin pour le Bouton 2. */
    int etat;               /**< État interne du menu. */
    float Luminosity = 1;   /**< Niveau de luminosité actuel de l'écran LCD. */
    std::string couleurLCD; /**< Couleur actuelle affichée sur l'écran LCD. */
    
     /**
     * @brief Liste des couleurs prédéfinies avec leurs valeurs RGB.
     * Chaque entrée contient un nom de couleur sous forme de chaîne et un triplet RGB correspondant.
     */
    const std::array<std::pair<std::string, std::array<int, 3>>, 10> colors = {{
        {"Noir", {0, 0, 0}},
        {"Blanc", {255, 255, 255}},
        {"Rouge", {255, 0, 0}},
        {"Vert", {0, 255, 0}},
        {"Bleu", {0, 0, 255}},
        {"Jaune", {255, 255, 0}},
        {"Orange", {255, 165, 0}},
        {"Violet", {128, 0, 128}},
        {"Gris", {128, 128, 128}},
        {"Marron", {165, 42, 42}}
    }};
     /**
     * @brief Liste des niveaux de luminosité prédéfinis.
     * Chaque entrée contient un nom de niveau et une valeur flottante correspondante.
     */
    const std::array<std::pair<std::string, float>, 3> Luminosities = {{
        {"Basse", 0.2},
        {"Moyenne", 0.5},
        {"Elevee", 1},
    }};
    
    int numLum = 0;                                     /**< Index actuel dans le tableau Luminosities. */
    std::string LumAffich = Luminosities[numLum].first; /**< Nom du niveau de luminosité affiché. */
    int numCoul = 0;                                    /**< Index actuel dans le tableau colors. */
    std::string coulAffich = colors[numCoul].first;     /**< Nom de la couleur affichée. */
    int currentValueB1 = 0;                             /**< État actuel du Bouton 1. */
    int pastValueB1 = 0;                                /**< État précédent du Bouton 1. */
    int currentValueB2 = 0;                             /**< État actuel du Bouton 2. */
    int pastValueB2 = 0;                                /**< État précédent du Bouton 2. */
    
  public :
  
     /**
     * @brief Constructeur par défaut de la classe MENU.
     */
    MENU();

     /**
     * @brief Constructeur avec initialisation des pins des boutons.
     * @param pin1 Numéro de pin pour le Bouton 1.
     * @param pin2 Numéro de pin pour le Bouton 2.
     */
    MENU(int pin1, int pin2);

     /**
     * @brief Destructeur de la classe MENU.
     */
    ~MENU();

     /**
     * @brief Affiche le menu actuel sur l'écran LCD.
     * @param leBUZZER Pointeur vers un objet BUZZER pour afficher les paramètres de la classe.
     * @param laLED Pointeur vers un objet LED pour afficher les paramètres de la classe.
     */
    void afficherMenu(BUZZER *leBUZZER, LED *laLED, CapteurSon *cpt_son, CapteurRanger *cpt_r);

     /**
     * @brief Vérifie l'état des boutons et traite les entrées utilisateur.
     * @param leBUZZER Pointeur vers un objet BUZZER pour modifier les paramètres de la classe.
     * @param laLED Pointeur vers un objet LED pour modifier les paramètres de la classe.
     */
    void checkButtons(BUZZER *leBUZZER, LED *laLED, CapteurSon *cpt_son, CapteurRanger *cpt_r);

     /**
     * @brief Met à jour la couleur RGB de l'écran LCD en fonction du nom donné.
     * @param couleur Nom de la couleur à afficher sur l'écran LCD 
     *                (doit correspondre à une entrée dans `colors`).
     */
    void setRGBLCD(std::string couleur);
};

#endif

