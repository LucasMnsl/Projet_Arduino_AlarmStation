/*********************************************************************
 * @file  LED.h
 * @author <MANSILHA Lucas mansilha@insa-toulouse.fr>
 * @brief Fichier include de la classe
 *********************************************************************/
#ifndef LED_H_
#define LED_H_

class LED {
  private :
    bool etat;
    int pinLED;
  public :
    LED();
    LED(int pin);
    ~LED();
    bool getEtat();
    void turnOn();
    void turnOff();
};

#endif
