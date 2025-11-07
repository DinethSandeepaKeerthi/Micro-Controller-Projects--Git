void setup() { 
 pinMode(3, OUTPUT);
}

void loop() {
  int x=0;

  while(x<=255){
    analogWrite(3,x);
    delay(10);
    x=x+1;
  }
int y=255;
  while(y>=0){
    analogWrite(3,y);
    delay(10);
    y=y-1;
  }
}
