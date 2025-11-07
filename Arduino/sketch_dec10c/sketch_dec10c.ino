#include <Servo.h>
Servo srv;
void setup() {
 srv.attach(9); 

}

void loop() {
int x = analogRead(A0);
int ang = map(x,0,1023,0,180);
srv.write(ang);
delay(20);
}
