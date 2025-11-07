#define trig 7
#define echo 8
#define led 11

void setup() {
 pinMode(trig,OUTPUT);
 pinMode(led,OUTPUT);
 pinMode(echo,INPUT);
 Serial.begin(9600);
  

}

void loop() {
 int S,T;
digitalWrite(trig,HIGH);
delay(1);
digitalWrite(trig,LOW);

T= pulseIn(echo,HIGH);

S= (T/2)*(1/29.1);

Serial.println(S);
delay(50);

if(S<20){
  digitalWrite(led,HIGH);
  
}

if(S>20){
  digitalWrite(led,LOW);
  
}




}
