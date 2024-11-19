
const int LED_BUILTIN2=16; //2nd built in led
const int LIGHT_SENSOR=A0; //Analog Input
int SensorValue=0;
int MyDelay=1000;

void setup(){
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_BUILTIN2, OUTPUT);
  Serial.begin(9600); //communication BaudRate
}

void loop(){
  
  SensorValue=analogRead(LIGHT_SENSOR);
  MyDelay=map(SensorValue, 0, 800, 500, 10); //En vrai il faudrai 0 1023 mais le capteur monte pas au dessus de 800
  Serial.println("Sensor Value : "+String(SensorValue)+" ; The time delay : "+String(MyDelay)); //print value in the serial monitor
  
  digitalWrite(LED_BUILTIN2, LOW);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(MyDelay);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LED_BUILTIN2, HIGH);
  delay(MyDelay);
  
}
