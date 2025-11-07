#include<Servo.h>
Servo mys1;
void setup() {
 mys1.attach(9);


}

void loop() {
  
mys1.write(0);
delay(500);
 mys1.write(180);
delay(500); 
}
