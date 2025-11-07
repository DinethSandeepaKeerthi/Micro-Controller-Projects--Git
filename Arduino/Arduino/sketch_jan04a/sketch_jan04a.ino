int t_value;
int t = 0;

void setup() {
  Serial.begin(115200);
}





void loop() {
  sread();
  delay(250);

}


void sread() {
  int value_a0 = analogRead(A0);
  int value_a1 = analogRead(A1);
  int value_a2 = analogRead(A2);
  int value_a3 = analogRead(A3);
  int value_a4 = analogRead(A4);
  int value_a5 = analogRead(A5);
  t_value = value_a0 + value_a1 + value_a2 + value_a3 + value_a4 + value_a5;
  Serial.println(t_value);

  if (t_value > 5000) {
    t = t + 1;

    if (t == 5) {
      Serial.println("left");
    }
    if (t == 7) {
      Serial.println("forwod");
    }
  }
}
