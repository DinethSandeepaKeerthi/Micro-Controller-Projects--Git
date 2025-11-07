#define sen_1 2
#define sen_2 3
#define sen_3 18

#define sen_4 19
#define sen_5 16
#define sen_6 17
#define sen_7 20

#define gcy01_sen_1 21
#define gcy01_sen_2 23
#define gcy02_sen_1 25
#define gcy02_sen_2 27

#define conv_1 4
#define conv_2 6
#define conv_3 10

#define green 28
#define red 26
#define yellow 30

#define cyl_1 5
#define cyl_2 7
#define suc_1 8

#define cyl_3 24

#define gr_cyl_1 9
#define gr_cyl_2 46
#define gr 22





int c11;
int c12;
int c21;
int c22;


int a=1;


void setup() {
  pinMode(conv_1, OUTPUT);
  pinMode(conv_2, OUTPUT);
  pinMode(conv_3, OUTPUT);

  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);

  pinMode(cyl_1, OUTPUT);
  pinMode(cyl_2, OUTPUT);
  pinMode(suc_1, OUTPUT);

  pinMode(gr_cyl_1, OUTPUT);
  pinMode(gr_cyl_2, OUTPUT);
  pinMode(gr, OUTPUT);

  pinMode(cyl_3, OUTPUT);
 
  

  pinMode(sen_1,INPUT);
  pinMode(sen_2,INPUT);
  pinMode(sen_3,INPUT);

  pinMode(sen_4,INPUT);
  pinMode(sen_5,INPUT);
  pinMode(sen_6,INPUT);
   pinMode(sen_7,INPUT);

  pinMode(gcy01_sen_1,INPUT);
  pinMode(gcy01_sen_2,INPUT);
  pinMode(gcy02_sen_1,INPUT);
  pinMode(gcy02_sen_2,INPUT);

  
  
}

void loop() {

if(a==1){
  digitalWrite(green,LOW);//ON
  digitalWrite(red,HIGH);//OFF
  digitalWrite(yellow,HIGH);//OFF

  analogWrite(conv_1,0);
  analogWrite(conv_2,0);
  analogWrite(conv_3,0);

  digitalWrite(cyl_1,HIGH);
  digitalWrite(cyl_2,HIGH);
  digitalWrite(suc_1,HIGH);
  
  digitalWrite(gr_cyl_1,HIGH);
  digitalWrite(gr_cyl_2,HIGH);
  digitalWrite(gr,HIGH);
  digitalWrite(cyl_3,HIGH);

  a=2;  
}

if(a==2){
  if(digitalRead(sen_1)==LOW){
    a=3;
  }
}

if(a==3){
  digitalWrite(green,HIGH);//off
  digitalWrite(yellow,LOW);//on
  delay(200);
  analogWrite(conv_1,127);
  a=4;
  
}

if(a==4){
  if(digitalRead(sen_2)==HIGH){
    a=5;
  }
}

if(a==5){
   analogWrite(conv_1,0);
   //digitalWrite(yellow,LOW);//on
   digitalWrite(red,LOW);//on
   delay(5000);
   digitalWrite(red,HIGH);//oFF
   analogWrite(conv_1,127);
   a=6;
   
}

if(a==6){
  if(digitalRead(sen_3)==LOW){
    a=7;
  }
}

if(a==7){
  analogWrite(conv_1,0);
  digitalWrite(cyl_1,LOW);
  delay(2000);
  digitalWrite(cyl_2,LOW);
  delay(2000);
  digitalWrite(suc_1,LOW);
  delay(2000);
  digitalWrite(cyl_2,HIGH);
  delay(2000);
  digitalWrite(cyl_1,HIGH);
  delay(2000);
  digitalWrite(cyl_2,LOW);
  delay(2000);
  digitalWrite(suc_1,HIGH);
  delay(2000);
  digitalWrite(cyl_2,HIGH);
  delay(2000);
  a=8;  
}

if(a==8){
  if(digitalRead(sen_4)==LOW){
    a=9;
  }
}

if(a==9){
  analogWrite(conv_2,127);
  a=10;
}

if(a==10){
  if(digitalRead(sen_5)==LOW){
    delay(400);
    a=11;
  }
}

if(a==11){
  analogWrite(conv_2,0);
  a=12;
}

if(a==12){
  c11 = digitalRead(gcy01_sen_1);
  c12 = digitalRead(gcy01_sen_2);
  c21 = digitalRead(gcy02_sen_1);
  c22 = digitalRead(gcy02_sen_2);

  if(c11==0&&c12==1&&c21==0&&c22==1){
  a=13;
  }
}

if(a==13){
  digitalWrite(gr_cyl_2,LOW);
  delay(2000);
  digitalWrite(gr,LOW);
  delay(2000);
  digitalWrite(gr_cyl_2,HIGH);
  delay(2000);
  digitalWrite(gr_cyl_1,LOW);
  delay(2000);
  digitalWrite(gr_cyl_2,LOW);
  delay(2000);
  digitalWrite(gr,HIGH);
  delay(2000);
  digitalWrite(gr_cyl_2,HIGH);
  delay(5000);
  digitalWrite(gr_cyl_2,LOW);
  delay(2000);
  digitalWrite(gr,LOW);
  delay(2000);
  digitalWrite(gr_cyl_2,HIGH);
  delay(2000);
  digitalWrite(gr_cyl_1,HIGH);
  delay(2000);
  digitalWrite(gr_cyl_2,LOW);
  delay(2000);
  digitalWrite(gr,HIGH);
  delay(2000);
  digitalWrite(gr_cyl_2,HIGH);
  delay(2000);
  analogWrite(conv_1,127);
  a=14;
    
}

if(a==14){
  if(digitalRead(sen_6)==HIGH){
    a=15;
  }
}

if(a==15){
  analogWrite(conv_2,0);
  digitalWrite(cyl_3,LOW);
  delay(2000);
  digitalWrite(cyl_3,HIGH);
  delay(2000);
  analogWrite(conv_3,127);
  a=16;
  
}

if(a==16){
  if(digitalRead(sen_7)==HIGH){
    a=17;
  }
}

if(a==17){
  analogWrite(conv_3,0);
  digitalWrite(green,HIGH);//On
  digitalWrite(yellow,HIGH);//OFF
  a=18;
}

if(a==18){
  a=1;
}



























  

}
