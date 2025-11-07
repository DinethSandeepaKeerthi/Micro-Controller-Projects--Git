void setup() {
  pinMode(3,OUTPUT);
  Serial.begin(9600);
  
  
}
int dc;
int x;
void loop() {
x =analogRead(A0);
 Serial.println(dc);
  
dc = map(x,0,1023,0,255);
 analogWrite(3,dc);

}
