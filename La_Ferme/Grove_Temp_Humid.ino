/*
//video on I2C to understand how to communicate with I2C sensors : https://youtu.be/6IAkYpmA1DQ?si=2eVq7p_AGo7YhJZE
// DataSheet : https://sensirion.com/media/documents/213E6A3B/63A5A569/Datasheet_SHT3x_DIS.pdf

#include <Wire.h>

#define SENSOR_ADRESS 0x44 //adress I2C par défaut

//capteur ou on accède pas aux registre directement, on y accède via des commandes
//principales commandes après lecture de la datasheet :
#define SINGLE_MESURE_MSB 0x24 // 1 mesure de haute qualité avec clock stretching disabled
#define SINGLE_MESURE_LSB 0x00
#define PERIODIC_MESURE_MSB 0x20 // mesures périodiques de haute qualités (0,5mps mesure per sec)
#define PERIODIC_MESURE_LSB 0x32

int tempRaw=0;
int humidRaw=0;

float temperature=0;
float humidity=0;

void setup(){
  
  delay(3000);
  Wire.begin();   //initialise la bibliothèque
  Serial.begin(9600);
  Serial.println("Bibliothèque Wire initialisée");
  delay(1000);
  
  //On s'address au bon capteur (écriture sur SDA)
  Wire.beginTransmission(SENSOR_ADRESS);
  Serial.println("Sensor connecté");
  delay(1000);
  
  //Lancement d'une mesure (écriture sur SDA)
  Wire.write(SINGLE_MESURE_MSB);
  Wire.write(SINGLE_MESURE_LSB);
  Serial.println("Commande de mesure envoyée");
  delay(1000);
  
  //Cloture de la transmission
  Wire.endTransmission();
  Serial.println("Communication cloturée");
  delay(1000);
  
  Wire.requestFrom(SENSOR_ADRESS, 6); //On demande nos 6 octets de données (cf datasheet 2 octets Temp + 1 octet CRC et pareil pour humid)
  
  if (Wire.available()<=6){
    tempRaw=Wire.read()<<8|Wire.read(); //Température scindée en 2 octet (xxxxxxxxxx <<8 = xxxxxxxx00000000, |wire.read() : xxxxxxxxxxxxxxxx)
    Wire.read(); //CRC Température
    humidRaw=Wire.read()<<8|Wire.read(); //Humidité pareil
    Wire.read(); //CRC Température
    Serial.println("Mesures récupérées");
    delay(1000);
  }
  
  Serial.print("Raw temperature : ");
  Serial.println(tempRaw);
  Serial.print("Raw humidity : ");
  Serial.println(humidRaw);
  Serial.println("");
  delay(1000);
  
  temperature = -45 + (175.0 * tempRaw / 65535.0);  //cf datasheet
  humidity = 100.0 * humidRaw / 65535.0;
  
  Serial.print("  --- Temperature : ");
  Serial.print(temperature);
  Serial.println(" °C");
  Serial.print("  --- Humidity : ");
  Serial.print(humidity);
  Serial.println(" %");
}

void loop(){
  
  
}
*/