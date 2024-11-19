
/*
  Pour utiliser le module wifi comme ACCESS POINT il faut :
    0. Initialiser la communaction avec un BaudRate de 115200
    1. Lancer le point d'accès avec la fonction WiFi.softAP(ssid, password) password and 3 more parametter are optionnal
    2. Vérifier que le point d'accès s'est lancé (si la fonction retourne true) 
    3. Eventuellement WiFi.softAPConfig(localIP, gateway, subnet)
    4. On peut ensuite afficher l'@IP assignée à l'access point
    -rmq : c'est un point d'accès sans accès internet il sert uniquement à la communication des appareils entre eux
*/
/*
#include <ESP8266WiFi.h> //<>=bibliotèques ""=fichiers
//doc : https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/soft-access-point-class.html

const char* ssid="ESP8266_AccessPoint"; //type string en plus propre = chaine de char = char* ou char[] (taille fixe)
const char* password="password";

void setup(){
  delay(3000);
  Serial.begin(115200);
  
  //Lancement du point d'accès
  if (WiFi.softAP(ssid, password)){
    Serial.println("Access Point READY");
    Serial.println("Adresse IP : ");
    Serial.println(WiFi.softAPIP());
  }
  else{
    Serial.println("Access Point FAILED");
  }
  
}

void loop(){
  
}
*/
