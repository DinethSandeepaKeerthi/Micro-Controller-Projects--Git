
int count=0;
int states=0;
void setup() {
  pinMode(2,INPUT_PULLUP);
  Serial.begin(9600);

  
}

void loop() {
  
int x = digitalRead(2);
  if((x==0)&&(states==0)){
    
    count= count+1;

    Serial.println(count);
    states=1;
  }

  if((x==1)){
    states=0;
    
  }
  delay(100);

}
