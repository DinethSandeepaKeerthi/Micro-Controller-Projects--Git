#define TRIG 12
#define ECO 13
#define in1 2
#define in2 3
#define in3 4
#define in4 5
#define serv 9
#include<Servo.h>
Servo rot;
int D, T;
void setup() {
  pinMode(ECO, INPUT);
  pinMode(TRIG, OUTPUT);
  rot.attach(9);

}
int a = 1;
void loop() {
  if (a == 1) {
    rot.write(90);
    delay(2000);
    a = 2;
  }

  if (a == 2) {
    chd();
    a = 3;
  }
  if (a == 3) {
    if (D < 20) {
      a = 31;
    } else {
      forward();
      a = 2;
    }
  }

  if (a == 31) {
    Stop();
    rot.write(90);
    delay(500);
    chd();
    a = 33;
  }

  if (a == 33) {
    if (D < 20) {
      a = 331;
    } else {
      rot.write(90);
      delay(500);
      right();
      delay(350);
      a = 2;
    }
  }

  if (a == 331) {
    rot.write(160);
    delay(1000);
    chd();
    a = 332;
  }

  if (a == 332) {
    if (D < 20) {
      a = 3321;
    } else {
      rot.write(90);
      delay(500);
      left();
      delay(350);
      a = 2;
    }
  }

  if (a == 3321) {
    rot.write(90);
    delay(500);
    backward();
    delay(700);
    left();
    delay(800);
    a = 2;

  }




}







void chd() {
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  T = pulseIn(ECO, HIGH);

  D = (T / 2) * (1 / 29.1);
  delay(50);
}


void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in4, LOW);
}

void backward() {
  digitalWrite(in2, HIGH);
  digitalWrite(in4, HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in3, LOW);
}

void Stop() {
  digitalWrite(in2, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void right() {
  digitalWrite(in1, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
}

void left() {
  digitalWrite(in1, HIGH);
  digitalWrite(in4, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
}
