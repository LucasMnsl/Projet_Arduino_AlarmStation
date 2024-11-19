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
    void config(int pin);
    void turnOn();
    void turnOff();
};

#endif