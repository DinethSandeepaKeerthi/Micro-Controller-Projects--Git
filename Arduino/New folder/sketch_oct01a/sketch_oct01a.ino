void setup() {
  pinMode(13,INPUT);
  pinMode(7,OUTPUT);
  

}

void loop() {
  int pushbutton = digitalRead(13);
  if( pushbutton == HIGH){
    digitalWrite(7,HIGH);
    delay (200);
    digitalWrite(7,LOW);

   
  }

}
