void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, OUTPUT);
  pinMode(8, OUTPUT);

}

int x = 0;
bool st = false;

void loop() {

  if (digitalRead(2) == 0) {
    digitalWrite(3, HIGH);
  }

  if (x == 20) {
    x = 0;

    if (st == false) {
      digitalWrite(8, HIGH);
      st = true;
    } else {
      digitalWrite(8, LOW);
      st = false;
    }
  }
  x = x + 1;
  delayMicroseconds(100);
}
