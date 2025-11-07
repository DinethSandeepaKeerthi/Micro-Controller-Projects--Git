

void setup() {
  pinMode ( 8, OUTPUT);
  pinMode ( 9, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode (11,OUTPUT);
 pinMode (4,INPUT);
}

void loop() {
  if(digitalRead(4)==LOW){
    digitalWrite(8,HIGH),digitalWrite(10,HIGH);
     digitalWrite(9,LOW),digitalWrite(11,LOW);
  }
  else{
    digitalWrite(9,HIGH),digitalWrite(11,HIGH);
    digitalWrite(8,LOW),digitalWrite(10,LOW);
  }
     
    
  

}
