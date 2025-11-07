void setup() {
  // put your setup code here, to run once:

}

float kp = 0.02;
float kd = 0.04;
float ki = 0.01;
int last_value;
int total_value;




void loop() {
  


  int err = sensor.readSensor();
  //Serial.println(err);
  delay(100);
  int m1 = 120;
  int m2 = 120;
  int dff = err * kp + (err - last_value) * kd + total_value * ki;
  last_value = err;
  total_value = err;

  mdrive(m1 + dff, m2 - dff);





}
