int th_value;
int t = 0;
int rp_value;
int r = 0;

#include <BeeLineSensorPro.h>
#define M1 7
#define M1pwm 6
#define M2 8
#define M2pwm 5

BeeLineSensorPro sensor = BeeLineSensorPro((unsigned char[]) {
  A0, A1, A2, A3, A4, A5
}, LINE_BLACK);



void setup() {
  Serial.begin(115200);

  pinMode(M1, OUTPUT);
  pinMode(M1pwm, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M2pwm, OUTPUT);
  //pinMode(9,INPUT);

  mdrive(120, -120);
  delay(1300);
  mdrive(120, 120);
  delay(1000);
  mdrive(0, 0);








  /*for (int i = 0; i < 100; i++) {
    sensor.calibrate();
    mdrive(120, -120);
  }
  mdrive(0, 0);
  delay(150);

  for (int i = 0; i < 200; i++) {
    sensor.calibrate();
    mdrive(-120, 120);
  }
  mdrive(0, 0);
  delay(150);

  for (int i = 0; i < 100; i++) {
    sensor.calibrate();
    mdrive(120, -120);
  }*/
 // mdrive(0, 0);
  //delay(50);

}

float kp = 0.04;
float kd = 0.2;
float ki = 0.002;
int last_value ;
int total_value ;
void loop() {
  /*hexjun();
  delay(5);

  propjun();
  delay(5);*/
  



  int err = sensor.readSensor();
  //Serial.println(err);
  delay(100);
  int m1 = 120;
  int m2 = 120;
  int dff = err * kp + (err - last_value) * kd    + total_value * ki;
  last_value = err;
  

 

  mdrive(m1 + dff, m2 - dff);
  /*hexjun();
  delay(10);

  propjun();
  delay(10);
  mdrive(m1 + dff, m2 - dff);*/
}

void mdrive(int m1, int m2) {
  if (m1 > 0) {
    if (m1 > 255) {
      m1 = 255;
    }
    digitalWrite(M1, HIGH);
    analogWrite(M1pwm, 255 - m1);
  }
  else {
    if (m1 < -255) {
      m1 = -255;
    }
    digitalWrite(M1, LOW);
    analogWrite(M1pwm, m1 * -1);
  }

  if (m2 > 0) {
    if (m2 > 255) {
      m2 = 255;
    }
    digitalWrite(M2, HIGH);
    analogWrite(M2pwm, 255 - m2);
  }
  else {
    if (m2 < -255) {
      m2 = -255;
    }
    digitalWrite(M2, LOW);
    analogWrite(M2pwm, m2 * -1);
  }

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

  if (th_value > 4000 ) {
    t = t + 1;
    Serial.println(t);


    if (t == 3 || t == 5 || t == 7 || t == 9 || t == 11 || t == 15 ) {
      //Serial.println("turn");
      mdrive(0, 0);
      delay(50);
      mdrive(130, 0);
      delay(1350);
      //mdrive(120, 120);


    }
    /*else {
      //Serial.println("forword");
      mdrive(120, 120);
    }*/
  }

}
void propjun() {


  int value_a4 = analogRead(A4);
  int value_a5 = analogRead(A5);

  rp_value =  value_a4 + value_a5;
  //Serial.println(rp_value);

  if (rp_value > 1200) {
    r = r + 1;

    //Serial.println(r);
    if (r == 5) {
      //Serial.println("turn");
      mdrive(0, 0);
      delay(50);
      mdrive(130, 0);
      delay(1350);
      //mdrive(120, 120);

    }
    /*else {
      //Serial.println("foword");
      mdrive(120, 120);
    }*/

  }

}
 
