void setup() {
  attachInterrupt(0,detect,RISING);
  Serial.begin(9600);
}
long p=0;
bool st = false;

void loop() {
 if( st==true){
  
  st=false;
  Serial.println(p);
 }

  
}

void detect(){
  p=p+1;
  st= true;
}
