void setup() {
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);


}

void loop() {
 /* digitalWrite(3,HIGH);
  delayMicroseconds(0.1);
  digitalWrite(3,LOW);
  delayMicroseconds(1999.9);*/
  
  for(int i=0;i<255;i++){
  analogWrite(3,i);
  delay(10);
  analogWrite(4,i);
  delay(10);
  }

  delay(1000);
  for(int i=255;i>0;i--){
  analogWrite(3,i);
  delay(10);
  analogWrite(4,i);
  delay(10);
  }

  

  /*analogWrite(3,255);
  delay(3000);
  analogWrite(3,204);
  delay(3000);
  analogWrite(3,127);
  delay(3000);
  analogWrite(3,64);
  delay(3000);
  analogWrite(3,25.5);
  delay(3000);
  analogWrite(3,3);
  delay(3000);*/
  

}
