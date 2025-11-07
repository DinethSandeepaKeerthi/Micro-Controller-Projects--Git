void setup() {
  attachInterrupt(0, detect, RISING);
  Serial.begin(9600);
  pinMode(3, OUTPUT);

  for (int i = 0; i < 200; i++) {
    digitalWrite(3, HIGH);
    delayMicroseconds(1000);
    digitalWrite(3, LOW);
    delayMicroseconds(1000);
  }

}

long p = 0;
bool st = false;


void loop() {
  if ( st == true) {
    st = false;
    Serial.println(p);
  }

  delay(1000);
}

void detect() {
  p = p + 1;
  st = true;
}
