#define pump_1 4
#define pump_2 5
#define start 2
#define Stop 3
#define lese_1 19
#define lese_2 18
#define d_1 16
#define d_2 17
#define d_3 20
#define mini_pump 8
#define red 46
#define green 6
#define heter 9
#define motor 7

void setup() {
  pinMode(pump_1, OUTPUT);
  pinMode(pump_2, OUTPUT);
  pinMode(mini_pump, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(heter, OUTPUT);
  pinMode(motor, OUTPUT);

  pinMode(start, INPUT);
  pinMode(Stop, INPUT);
  pinMode(lese_1, INPUT);
  pinMode(lese_2, INPUT);
  pinMode(d_1, INPUT);
  pinMode(d_2, INPUT);
  pinMode(d_3, INPUT); 

}
int b=1;
void loop() {

  if(b==1){
    digitalWrite(pump_1,LOW);
    digitalWrite(pump_2,LOW);
    digitalWrite(mini_pump,LOW);
    digitalWrite(motor,LOW);
    digitalWrite(heter,LOW);
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);

   b=2;
  }

  if(b==2){
    if((digitalRead(start)==LOW)&&(digitalRead(lese_1)==HIGH)){
      b=3;
    }
  }

  if(b==3){
    digitalWrite(pump_1,HIGH);
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    b=4;
  }

  if(b==4){
    if((digitalRead(lese_2)==HIGH)){
      b=5;
    }
  }

  if(b==5){
    digitalWrite(pump_1,LOW);
    digitalWrite(heter,HIGH);
    delay(5000);
    digitalWrite(heter,LOW);
    digitalWrite(pump_2,HIGH);

    b=6;
    
  }
if(b==6){
  if(digitalRead(lese_1)==HIGH){
   b=7; 
  }
  

}

if(b==7){
  if(digitalRead(d_1)==LOW){
    b=8;
  }
}

if(b==8){
  digitalWrite(pump_2,LOW);
  digitalWrite(motor,HIGH);
  
  b=9;
}

if(b==9){
  if(digitalRead(d_2)==LOW){
    b=10;
  }
}

if(b==10){
  digitalWrite(motor,LOW);
  digitalWrite(mini_pump,HIGH);
  delay(15000);
  digitalWrite(mini_pump,LOW);
  digitalWrite(motor,HIGH);
  b=11;
  
  
}

if(b==11){
  if(digitalRead(d_3)==LOW){
    b=1;
  }
}



















  

}
