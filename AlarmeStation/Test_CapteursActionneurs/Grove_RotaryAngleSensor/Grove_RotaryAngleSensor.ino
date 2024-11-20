
const int sensorPin=A0;
int rawSensor=0;
int angle=0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  rawSensor=analogRead(sensorPin);
  angle=map(rawSensor, 0, 1023, 0, 300);
  Serial.println("Valeur du capteur : "+String(rawSensor)+" ; angle : "+String(angle));
}
