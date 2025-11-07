void setup() {
  pinMode(6,INPUT_PULLUP);
  pinMode(7,OUTPUT);
  

}

void loop() {
  int x= digitalRead(6);
  if(x==0){
    digitalWrite(7,HIGH);
  }

  if(x==1){
    digitalWrite(7,LOW);
  }

}
