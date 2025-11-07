
#include <BeeLineSensorPro.h>
#define M1p 7
#define M1n 6
#define M1pwm 5
#define M2p 9
#define M2n 8
#define M2pwm 10


BeeLineSensorPro sensor = BeeLineSensorPro((unsigned char[]) {
  A0, A1, A2, A3, A4
}, LINE_BLACK);

int M1sp = 155;
int M2sp = 155;


void setup() {
  Serial.begin(115200);

  pinMode(M1p, OUTPUT);
  pinMode(M1n, OUTPUT);
  pinMode(M1pwm, OUTPUT);
  pinMode(M2p, OUTPUT);
  pinMode(M2n, OUTPUT);
  pinMode(M2pwm, OUTPUT);
 






}


int err = sensor.readSensor();
float kp = 0.85;
float kd = 0.7;
float ki = 0.5;
int last_value ;
int total_value ;

void mdrive(int m1, int m2, int p, int n) {
  digitalWrite(M1n, p);             //fowoad(sp1,sp2,HIGH,LOW)
  digitalWrite(M1p, n);               //backwoad(sp1,sp2,LOW,HIGH)
  digitalWrite(M2n, p);
  digitalWrite(M2p, n);
  analogWrite(M1pwm, m1);
  analogWrite(M2pwm, m2);
}


void linef() {
  int err = sensor.readSensor();
  int dff = err * kp + (err - last_value) * kd + total_value * ki;
  last_value = err;
  total_value = err;

  if (dff > 0) {
    if (dff > 85) {
      dff = 85;
    }
  }

  else {
    if (dff < -85) {
      dff = -85;
    }
  }

  

  mdrive(M1sp + dff , M2sp - dff, HIGH, LOW);


}

void loop() {
 
linef();

}
