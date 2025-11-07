#include <TimerOne.h>
void setup() {
  pinMode(8,OUTPUT);
  Timer1.initialize(200000);
  Timer1.attachInterrupt(blnk_led);

}
bool st = false;
void loop() {
 
}

void blnk_led(){
  if(st== false){
    st=true;
    digitalWrite(8,HIGH);
  }else{
     st=false;
    digitalWrite(8,LOW);
  }
}
