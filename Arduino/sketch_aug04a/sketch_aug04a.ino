void setup() {
  Serial.begin(115200); // Set to the baud rate you need
}

void loop() {
  if (Serial.available()) {
    Serial.write(Serial.read());
  }
}
