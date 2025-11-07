int th_value;
int t = 0;

void setup() {
  Serial.begin(115200);
}





void loop() {
  hexjun();
  delay(800);

}


void hexjun() {
  int value_a0 = analogRead(A0);
  int value_a1 = analogRead(A1);
  int value_a2 = analogRead(A2);
  int value_a3 = analogRead(A3);
  int value_a4 = analogRead(A4);
  int value_a5 = analogRead(A5);
  
  th_value = value_a0 + value_a1 + value_a2 + value_a3 + value_a4 + value_a5;
  //Serial.println(th_value);

  if (th_value > 5500) {
    t = t + 1;
       //Serial.println(t);
    
    if(t==3 ||t==5 ||t==7 ||t==9 ||t==11 ||t==15 ){
     
    }
    else{
      Serial.println("forword");
    }
  }
    
}
