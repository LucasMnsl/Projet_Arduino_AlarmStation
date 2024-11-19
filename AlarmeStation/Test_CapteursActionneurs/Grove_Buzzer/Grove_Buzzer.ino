
/*
  2 types de BUZZER :
    1. Buzzer passif : fonctionne avec une tension continue (on peut lui passe une tension ~ pour essayer de lui faire faire des notes mais c'est très mauvais)
    2. Buzzer actuf : fonctionne avec une tension ~ -> on peutb faire des notes différentes
*/
unsigned long currentMillis=0;
unsigned long lastMillis=0;
const int deltaMillis=300;
bool change=false;


const int BUZZER=12;

void setup(){
  
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
  
  digitalWrite(BUZZER, LOW);
  delay(5000);
  
}

void loop(){

  //digitalWrite(BUZZER, HIGH); //utilisation buzzer en mode numérique (2300Hz) buzzer passif

  //Marche bien uniquement avec buzzer actif (pas celui du BE)
  //tone(BUZZER, 440);
  /*
  for (int f=0; f<20000; f+=10){
    Serial.println(f);
    tone(BUZZER, f);
    delay(100);
  }*/

  /* //Allarme bloquante
  tone(BUZZER, 800);
  delay(300);
  tone(BUZZER, 1200);
  delay(300);
  */


   //Allarme non bloquante
  currentMillis=millis();
  Serial.println(currentMillis);
  
  if (currentMillis-lastMillis>=deltaMillis){
      if (change){
        tone(BUZZER, 800);
      }
      else if (!change){
        tone(BUZZER, 1200);
      } 
      lastMillis=currentMillis;
      change=!change;
  }
  
    
    
    
    
  
}
