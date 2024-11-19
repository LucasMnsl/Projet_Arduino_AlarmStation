/*
const int LED_EXT=12; //grove led on D6 => GPIO 12 file jaune !
const int LED_BUILTIN2=16; //2nd built in led

void setup(){
  
  //Two leds built in : 2 and 16 we can choose LED_BUILTIN to be either 2 or 16
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_BUILTIN2, OUTPUT);
  pinMode(LED_EXT, OUTPUT);
  
}

void loop(){

  digitalWrite(LED_EXT, LOW);
  digitalWrite(LED_BUILTIN2, LOW);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LED_EXT, LOW);
  digitalWrite(LED_BUILTIN2, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LED_BUILTIN2, LOW);
  digitalWrite(LED_EXT, HIGH); //quand on allume la 14 les led BuiltIn s'allument
  delay(1000);
  
}*/
