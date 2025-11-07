#define Red 6 // in 2 Red light
#define Convayor 7 //in 1 motor
#define Start 8
#define stop 9
#define S1 2
#define S2 3
#define S3 4

int counter = 0;
int temp = 0;
int temp2 = 0;
int temp3 = 0;
int str = 0;

void setup() {
  Serial.begin(9600);
  pinMode(Red, OUTPUT);
  pinMode(Convayor, OUTPUT);
  pinMode(S1,INPUT);
  pinMode(S2,INPUT);
  pinMode(S3,INPUT);
  pinMode(Start,INPUT_PULLUP);
  pinMode(stop,INPUT_PULLUP);

  digitalWrite(Convayor,HIGH);
  digitalWrite(Red,HIGH);
}

void loop() {
  Serial.println(counter);
  if((digitalRead(S1) == 0) && (temp == 0)){
    counter = counter + 1;
    digitalWrite(Convayor,LOW);
    temp = 1;
  }

  if((digitalRead(S2) == 0)  && (temp2 == 0)){
    digitalWrite(Convayor,HIGH);
    digitalWrite(Red,LOW);
    delay(5000);
    digitalWrite(Convayor,LOW);
    digitalWrite(Red,HIGH);
    temp2 = 1;
  }

  if(digitalRead(S1) == 1){
    temp = 0;
  }

  if(digitalRead(S2) == 1){
    temp2 =0;
  }

  if((digitalRead(S3) == 0) && (temp3 == 0)){
    counter = counter - 1;
    temp3 = 1;
  }

  if(digitalRead(S3) == 1){
    temp3 = 0;
  }

  if(counter == 7){
    digitalWrite(Convayor,HIGH);
    digitalWrite(Red,HIGH);
    counter = 0;
  }

  if(digitalRead(stop) == 0){
    digitalWrite(Convayor,HIGH);
    digitalWrite(Red,HIGH);
    //counter = 0;
  }

  if(digitalRead(Start) == 0){
    digitalWrite(Convayor,LOW);
    digitalWrite(Red,HIGH);
  }
}
