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
    int freq1=800;
    int freq2=1200;
    int deltaMillis=300;
    bool isFreq1;
    unsigned long lastMillis=0;
    unsigned long currentMillis=0;
  public :
    BUZZER();
    BUZZER(int pin);
    ~BUZZER();
    bool getEtat();
    int getFreq1();
    int getFreq2();
    int getDeltaMillis();
    void setFreq1(int f);
    void setFreq2(int f);
    void setDeltaMillis(int t);
    void turnOn();
    void turnOff();
};

#endif
