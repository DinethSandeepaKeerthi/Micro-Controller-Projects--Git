void setup(){
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,INPUT); 


}

void loop() {

  if(digitalRead(12)==LOW){
  analogWrite(9,150); analogWrite(11,150);
  delay (1000);
  digitalWrite(9,LOW);  digitalWrite(11,LOW);
  //delay (1000);
  }
  //else{

  //analogWrite(6,150); analogWrite(10,150);
  //delay (1000);
 // digitalWrite(6,LOW);  digitalWrite(10,LOW);
  //delay (1000);
  //}
  

}
