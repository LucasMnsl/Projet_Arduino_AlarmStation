/*
//const int LED_EXT=12; //grove led on D6 => GPIO 12
const int LED_BUILTIN2=16; //2nd built in led
const int BUTTON=14; //grove button, in PULL-DOWN (1 if pressed 0 else)

void setup(){
  
  //Two leds built in : 2 and 16 we can choose LED_BUILTIN to be either 2 or 16
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_BUILTIN2, OUTPUT);
  pinMode(BUTTON, INPUT);
  //pinMode(LED_EXT, OUTPUT);
  
}

void loop(){
  
  if (digitalRead(BUTTON)==HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(LED_BUILTIN2, LOW);
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(LED_BUILTIN2, HIGH);
  }
  
}*/
