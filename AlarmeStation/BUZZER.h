/*********************************************************************
 * @file  BUZZER.h
 * @author <MANSILHA Lucas mansilha@insa-toulouse.fr>
 * @brief Fichier include de la classe
 *********************************************************************/
#ifndef BUZZER_H_
#define BUZZER_H_

class BUZZER {
  private :
    bool etat;
    int pinBUZZER;
    const int freq1=800;
    const int freq2=1200;
    const int deltaMillis=300;
    bool isFreq1;
    unsigned long lastMillis=0;
    unsigned long currentMillis=0;
  public :
    BUZZER();
    BUZZER(int pin);
    ~BUZZER();
    void turnOn();
    void turnOff();
};

#endif
