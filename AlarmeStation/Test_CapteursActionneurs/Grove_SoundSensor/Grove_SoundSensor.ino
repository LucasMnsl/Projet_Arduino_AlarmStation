
const int sensorPin=A0;
int rawSensor=0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  rawSensor=analogRead(sensorPin);
  Serial.println("Valeur du capteur : "+String(rawSensor));
}
