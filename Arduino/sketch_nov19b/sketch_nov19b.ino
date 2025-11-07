void setup() {
 attachInterrupt(0,red_led,FALLING);
 
 pinMode(3,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(2,INPUT_PULLUP);
 
 
}

void loop() {
  digitalWrite(8,HIGH);
  delay(2000);
  digitalWrite(8,LOW);
  delay(2000);
}

void red_led(){
  digitalWrite(3,HIGH);
}
