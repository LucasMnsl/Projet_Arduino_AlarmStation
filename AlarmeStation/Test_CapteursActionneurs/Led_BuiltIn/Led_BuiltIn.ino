
//Executed one time
void setup(){
  
  //Two leds built in : 2 and 16 we can choose LED_BUILTIN to be either 2 or 16
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(16, OUTPUT);
  
}

//Executed in loop
void loop(){

  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(16, LOW);
  delay(1000); 
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(16, HIGH);
  delay(1000);

}
