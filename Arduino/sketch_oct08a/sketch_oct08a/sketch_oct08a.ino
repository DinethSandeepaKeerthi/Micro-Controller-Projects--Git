//#include <HID.h>

void setup() {
  pinMode(2,OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
  int n = Serial.available();
  
 
  if(n>0){
  char x = Serial.read();
  if(x=='A'){
    digitalWrite(2,HIGH);
    
  }

  if(x=='B'){
    digitalWrite(2,LOW);
  }

 
  }
   
    
  
  }

  
