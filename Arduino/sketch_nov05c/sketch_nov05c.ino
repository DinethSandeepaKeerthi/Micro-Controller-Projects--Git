void setup() {
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  int x = 2;
  int Y = 10;
  while (x <= 11) {
    digitalWrite(x, HIGH);
    delay(100);
    digitalWrite(x, LOW);
    x = x + 1;
    
  }

  while (Y > 2) {
    digitalWrite(Y, HIGH);
    delay(100);
    //digitalWrite(Y, LOW);
    Y = Y - 1;
    
  }


}
