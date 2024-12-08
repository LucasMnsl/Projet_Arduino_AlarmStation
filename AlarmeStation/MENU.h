/*********************************************************************
 * @file  LED.h
 * @author <MANSILHA Lucas mansilha@insa-toulouse.fr>
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
#include "CapteurSon.h"
#include "CapteurRanger.h"
#include <Ultrasonic.h>

class MENU {
  private :
    rgb_lcd monLCD;
    int pinB1;
    int pinB2;
    int etat;
    float Luminosity=1;
    std::string couleurLCD;
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
    const std::array<std::pair<std::string, float>, 3> Luminosities = {{
        {"Basse", 0.2},
        {"Moyenne", 0.5},
        {"Elevee", 1},
    }};
  public :
    int numLum=0;
    std::string LumAffich=Luminosities[numLum].first;
    int numCoul=0;
    std::string coulAffich=colors[numCoul].first;
    int currentValueB1=0;
    int pastValueB1=0;
    int currentValueB2=0;
    int pastValueB2=0;
    MENU();
    MENU(int pin1, int pin2);
    ~MENU();
    void afficherMenu(BUZZER *leBUZZER, LED *laLED, CapteurSon *cpt_son, CapteurRanger *cpt_r);
    void checkButtons(BUZZER *leBUZZER, LED *laLED, CapteurSon *cpt_son, CapteurRanger *cpt_r);
    void setRGBLCD(std::string couleur);
};

#endif
