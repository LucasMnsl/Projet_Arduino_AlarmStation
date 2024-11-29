/*********************************************************************
 * @file  LED.h
 * @author <MANSILHA Lucas mansilha@insa-toulouse.fr>
 * @brief Fichier include de la classe
 *********************************************************************/
#ifndef MENU_H_
#define MENU_H_
#include <Wire.h>
#include "rgb_lcd.h"
#include "BUZZER.h"
#include "LED.h"

class MENU {
  private :
    rgb_lcd monLCD;
    int pinB1;
    int pinB2;
    int etat;
  public :
    int currentValueB1=0;
    int pastValueB1=0;
    int currentValueB2=0;
    int pastValueB2=0;
    MENU();
    MENU(int pin1, int pin2);
    ~MENU();
    void afficherMenu(BUZZER *leBUZZER, LED *laLED);
    void checkButtons(BUZZER *leBUZZER, LED *laLED);
};

#endif
