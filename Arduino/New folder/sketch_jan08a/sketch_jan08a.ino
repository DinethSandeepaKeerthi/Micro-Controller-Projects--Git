void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

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
