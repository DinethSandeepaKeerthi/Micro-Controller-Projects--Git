

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

  /*mdrive(120, -120);
    delay(1300);
    mdrive(120, 120);
    delay(1000);
    mdrive(0, 0);

    for (int i = 0; i < 100; i++) {
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
    }
    mdrive(0, 0);
    delay(1000);*/

}

float kp = 0.06;
float kd = 0.04;
float ki = 0.01;
int last_value;
int total_value;




void loop() {
  


  int err = sensor.readSensor();
  Serial.println(err);
  delay(100);
  int m1 = 120;
  int m2 = 120;
  int dff = err * kp + (err - last_value) * kd + total_value * ki;
  last_value = err;
  total_value = err;

  mdrive(m1 - dff, m2 + dff);





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
