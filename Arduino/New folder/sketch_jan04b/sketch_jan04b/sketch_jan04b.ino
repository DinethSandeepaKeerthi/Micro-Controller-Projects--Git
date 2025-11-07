int rp_value;
int r = 0;

void setup() {
  Serial.begin(115200);
}





void loop() {
  propjun();
  delay(800);

}


void propjun() {
  //int value_a0 = analogRead(A0);
  //int value_a1 = analogRead(A1);
  //int value_a2 = analogRead(A2);
  //int value_a3 = analogRead(A3);
  int value_a4 = analogRead(A4);
  int value_a5 = analogRead(A5);
  
  rp_value =  value_a4 + value_a5;
  //Serial.println(rp_value);

  if (rp_value > 1900) {
    r = r + 1;
      
  Serial.println(r);
    if(r==5){
     //Serial.println("turn"); 
    }
    else{
      //Serial.println("foword");
    }
    
  }
    
}
