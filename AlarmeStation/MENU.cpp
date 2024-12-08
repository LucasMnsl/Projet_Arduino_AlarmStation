/*********************************************************************
 * @file  LED.cpp
 * @author <MANSILHA Lucas mansilha@insa-toulouse.fr>
 * @brief Fichier source de la classe
 *********************************************************************/
#include <Arduino.h>
#include "Menu.h"
#include "CapteurSon.h"
#include "CapteurRanger.h"
#include <Ultrasonic.h>

MENU::MENU(){
  
};

MENU::MENU(int pin1, int pin2){
  pinB1=pin1;
  pinB2=pin2;
  etat=1;
  monLCD.begin(16, 2);
  couleurLCD="Blanc";
  setRGBLCD(couleurLCD);
  pinMode(pinB1, INPUT);
  pinMode(pinB2, INPUT);
  Serial.println("*** Objet Menu créé, pin écran=I2C, pin bouton 1="+String(pinB1)+", pin bouton 2="+String(pinB2)+" ***");
}

MENU::~MENU(){
  Serial.println("*** Objet Menu détruit, pin écran=I2C, pin bouton 1="+String(pinB1)+", pin bouton 2="+String(pinB2)+" ***");
}

void MENU::setRGBLCD(std::string couleur){
  bool trouve=false;
  int i=0;
  while (not(trouve) and i<colors.size()){
    if (colors[i].first==couleur){
      trouve=true;
      monLCD.setRGB(int(colors[i].second[0]*Luminosity), int(colors[i].second[1]*Luminosity), int(colors[i].second[2]*Luminosity));
      couleurLCD=couleur;
    }
    i++;
  }
}

void MENU::afficherMenu(BUZZER *leBUZZER, LED *laLED, CapteurSon *cpt_son, CapteurRanger *cpt_r){
  switch (etat){
    case 1 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Station alarme");
      monLCD.setCursor(0, 1);
      monLCD.print("->Reglages");
      break;
    case 10 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Reglages");
      monLCD.setCursor(0, 1);
      monLCD.print("->Reglages BUZER");
      break;
    case 100 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Reglages BUZZER");
      monLCD.setCursor(0, 1);
      monLCD.print("->Frequence 1");
      break;
    case 1000 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Frequence 1 :");
      monLCD.setCursor(3, 1);
      monLCD.print(String(leBUZZER->getFreq1())+" Hz");
      break;
    case 101 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Reglages BUZZER");
      monLCD.setCursor(0, 1);
      monLCD.print("->Frenquence 2");
      break;
    case 1010 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Freqence 2 :");
      monLCD.setCursor(3, 1);
      monLCD.print(String(leBUZZER->getFreq2())+" Hz");
      break;
    case 102 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Reglages BUZZER");
      monLCD.setCursor(0, 1);
      monLCD.print("->Delai");
      break;
    case 1020 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Delai :");
      monLCD.setCursor(3, 1);
      monLCD.print(String(leBUZZER->getDelai())+" ms");
      break;
    case 11 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Reglages");
      monLCD.setCursor(0, 1);
      monLCD.print("->Reglages LED");
      break;
    case 110 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Reglages LED");
      monLCD.setCursor(0, 1);
      monLCD.print("->Delai");
      break;
    case 1100 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Delai :");
      monLCD.setCursor(3, 1);
      monLCD.print(String(laLED->getDelai())+" ms");
      break;
    case 12 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Reglages");
      monLCD.setCursor(0, 1);
      monLCD.print("->Reglages LCD");
      break;
    case 120 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Reglages LCD");
      monLCD.setCursor(0, 1);
      monLCD.print("->Couleur");
      break;
    case 1200 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Couleur :");
      monLCD.setCursor(3, 1);
      monLCD.print(coulAffich.c_str());
      break;
    case 121 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Reglages LCD");
      monLCD.setCursor(0, 1);
      monLCD.print("->Luminosite");
      break;
    case 1210 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Luminosite :");
      monLCD.setCursor(3, 1);
      monLCD.print(LumAffich.c_str());
      break;
    case 2 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Station alarme");
      monLCD.setCursor(0, 1);
      monLCD.print("->Test alarme");
      break;
    case 20 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Test alarme");
      monLCD.setCursor(0, 1);
      monLCD.print("->Test LED");
      break;
    case 21 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Test alarme");
      monLCD.setCursor(0, 1);
      monLCD.print("->Test BUZZER");
      break;

    //test Capteur son
    case 3 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Station alarme");
      monLCD.setCursor(0, 1);
      monLCD.print("->Test capteur");
      break;

    case 30 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Test capteur");
      monLCD.setCursor(0, 1);
      monLCD.print("->Test sound");
      break;

    case 300 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Test sound");
      monLCD.setCursor(0, 1);
      monLCD.print(cpt_son->lire_sound());
      break;

    case 31 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Test capteur");
      monLCD.setCursor(0, 1);
      monLCD.print("->Test distance");
      break;

    case 310 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Test distance");
      monLCD.setCursor(0, 1);
      monLCD.print(cpt_r->lire_distance());
      break;

    case 32 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Test capteur");
      monLCD.setCursor(0, 1);
      monLCD.print("->nombre capteur");
      break;

    case 320:
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("nombre capteur :");
      monLCD.setCursor(0, 1);
      monLCD.print(cpt_r->lire_nombre_capteur());
      break;

    case 4 :
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Station alarme");
      monLCD.setCursor(0, 1);
      monLCD.print("->demarrer");
      break;

    case 40:
      monLCD.clear();
      monLCD.setCursor(0, 0);
      monLCD.print("Station fonctione");
      monLCD.setCursor(0, 1);
      monLCD.print("------");
      break;

  }
}

void MENU::checkButtons(BUZZER *leBUZZER, LED *laLED, CapteurSon *cpt_son, CapteurRanger *cpt_r ){
    
    if (leBUZZER->getEtat()){
      leBUZZER->turnOn();
    }
    if (laLED->getEtat()){
      laLED->turnOn();
    }
    currentValueB1=digitalRead(pinB1);
    currentValueB2=digitalRead(pinB2);
    if (currentValueB1==1 and pastValueB1==0 and currentValueB2==0) {
      Serial.println("Etat du Menu : "+String(etat));
      pastValueB1=1;
      if(etat==1 or etat==10 or etat==11 or etat==20 or etat==100 or etat==101 or etat==120) etat++;
      else if (etat==2) etat=3;
      else if (etat==3) etat=4;
      else if (etat==4) etat=1;
      else if (etat==21) etat=20;
      else if (etat==12) etat=10;
      else if (etat==102) etat=100;
      else if (etat==121) etat=120;
      else if (etat==1000) leBUZZER->setFreq1((leBUZZER->getFreq1())-10);
      else if (etat==1010) leBUZZER->setFreq2((leBUZZER->getFreq2())-10);
      else if (etat==1020) leBUZZER->setDelai((leBUZZER->getDelai())-10);
      else if (etat==1100) laLED->setDelai((laLED->getDelai())-10);
      else if (etat==1200) {
        if (numCoul<(colors.size()-1)) numCoul++;
        else numCoul=0;
        coulAffich=colors[numCoul].first;
      }
      else if (etat==1210) {
        if (numLum<(Luminosities.size()-1)) numLum++;
        else numLum=0;
        LumAffich=Luminosities[numLum].first;
      }
      else if (etat == 30) etat=31;
      else if (etat == 31) etat=32;
      else if (etat == 32) etat=30;
    }
    else if (currentValueB1==0){
      pastValueB1=0;
    }

    if (currentValueB2==1 and pastValueB2==0 and currentValueB1==0) {
      Serial.println("Etat du Menu : "+String(etat));
      pastValueB2=1;
      if(etat==1) etat=10;
      else if (etat==10) etat=100;
      else if (etat==100) etat=1000;
      else if (etat==101) etat=1010;
      else if (etat==102) etat=1020;
      else if (etat==1000) leBUZZER->setFreq1((leBUZZER->getFreq1())+10);
      else if (etat==1010) leBUZZER->setFreq2((leBUZZER->getFreq2())+10);
      else if (etat==1020) leBUZZER->setDelai((leBUZZER->getDelai())+10);
      else if (etat==11) etat=110;
      else if (etat==110) etat=1100;
      else if (etat==1100) laLED->setDelai((laLED->getDelai())+10);
      else if (etat==12) etat=120;
      else if (etat==120) {
        numCoul=0;
        etat=1200;
      }
      else if (etat==121) etat=1210;
      else if (etat==1200) setRGBLCD(coulAffich);
      else if (etat==1210) {
        Luminosity=Luminosities[numLum].second;
        setRGBLCD(couleurLCD);
      }
      else if (etat==2) etat=20;
      else if (etat==20){
        if (not(laLED->getEtat())) laLED->turnOn();
        else laLED->turnOff();
      }
      else if (etat==21){
        if (not(leBUZZER->getEtat())) leBUZZER->turnOn();
        else leBUZZER->turnOff();
      }


      else if (etat == 3) etat = 30;          //test pour les capteur
      else if (etat == 30) etat = 300;
      else if (etat == 31) etat = 310;
      else if (etat == 32) etat = 320;

      //Station alarme fonctione
      else if (etat == 4) etat = 40;
      

    }
    else if (currentValueB2==0){
        pastValueB2=0;
    }

    if (currentValueB1==1 and currentValueB2==1 and pastValueB2==0){
      Serial.println("Etat du Menu : "+String(etat));
      etat=1;
      pastValueB2=1;
      pastValueB1=1;
      cpt_son->reset();
      cpt_r->reset();
      laLED->turnOff();
      leBUZZER->turnOff();
    }

    if (etat == 40){
        if((cpt_son->lire_etat() & cpt_r->lire_etat() ) ==1){
            leBUZZER->turnOn();
            laLED->turnOn();
        }  
      }

}
