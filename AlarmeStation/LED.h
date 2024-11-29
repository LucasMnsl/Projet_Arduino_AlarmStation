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
    int delai;
    bool isHigh;
    unsigned long lastMillis=0;
    unsigned long currentMillis=0;
  public :
    LED();
    LED(int pin);
    ~LED();
    bool getEtat();
    int getDelai();
    void setDelai(int t);
    void turnOn();
    void turnOff();
};

#endif
