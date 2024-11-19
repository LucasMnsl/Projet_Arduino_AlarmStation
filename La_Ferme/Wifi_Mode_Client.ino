/*
  Pour utiliser le module wifi comme CLIENT il faut :
    0. Initialiser la communaction avec un BaudRate de 115200
    1. Faire un partage de connection ou utiliser un réseau wifi
    2. Utiliser la fonciton Wifi.begin(ssid, password) initialise la connection wifi duquel on fourni le ssid et le password
    3. Attendre de la fonction Wifi.status() retourn WL_CONNECTED
    4. On peut ensuite afficher l'@IP assignée
*/
/*
#include <ESP8266WiFi.h> //<>=bibliotèques ""=fichiers
//doc : https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/readme.html

const char* ssid="Nono"; //type string en plus propre = chaine de char = char* ou char[] (taille fixe)
const char* password="nonowifi";

void setup(){
  delay(3000); //délai qui laisse le temps d'ouvrir le Serial Monitor et d'observer tout les messages
  Serial.begin(115200);
  
  //Connection au wifi
  WiFi.begin(ssid, password);
  Serial.println("Connexion au Wifi");

  //Tand que le statut n'est pas WL_CONNECTED
  while (WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println(" Connecté !");
  Serial.println("Adresse IP : ");
  Serial.println(WiFi.localIP());
}

void loop(){
  
}*/
