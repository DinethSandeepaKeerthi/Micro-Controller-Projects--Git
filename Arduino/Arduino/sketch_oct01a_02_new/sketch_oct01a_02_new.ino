void setup() {
  pinMode ( 10, OUTPUT);
  pinMode ( 11, OUTPUT);
  pinMode (5, INPUT);
  

}

void loop() {
  int pb = digitalRead (5);
  if(pb == HIGH){
    digitalWrite(10,HIGH);
    delay (100);
    digitalWrite(10,LOW);

     digitalWrite(11,HIGH);
    delay (100);
    digitalWrite(11,LOW);
  }

}
