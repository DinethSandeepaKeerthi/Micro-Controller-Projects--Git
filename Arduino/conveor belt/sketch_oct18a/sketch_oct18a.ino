#define heet 2
#define on_but 6
#define off_but 7
#define mot 8
#define sens_01 13
#define sens_02 4
#define sens_03 12
 


int x=0;
int y=0;

int st_1=0;
int st_2=0;
int st_3=0;
int st_4=0;

int i=0;
int d=0;

void setup() {
 pinMode(heet,OUTPUT);
 pinMode(mot,OUTPUT);
 pinMode(on_but,INPUT);
 pinMode(off_but,INPUT);
 pinMode(sens_01,INPUT);
 pinMode(sens_02,INPUT);
 pinMode(sens_03,INPUT);
}

void loop() {
  
  if((st_1==0)&&( digitalRead(on_but) == HIGH)){
    x=x+1;
    digitalWrite(mot,HIGH);
    st_1=1;
  }

  if( digitalRead(on_but) == HIGH){
    st_1 =0;
  }

  
  
  if((st_2==0)&&(digitalRead(off_but) == HIGH)){
    y=y+1;
    digitalWrite(mot,LOW);
    st_2=1;
    
  }

  if(digitalRead(off_but)== HIGH){
    st_2 =0;
  }

  
 if((i==7)||(d==-7)){
  digitalWrite(mot,LOW); 
  
}


if((st_3==0)&&( digitalRead(sens_01)==HIGH)){
  i=i+1;
  st_3==1;
}
 if(digitalRead(sens_01)==HIGH){
    st_3 =0;
  }


if((st_4==0)&&( digitalRead(sens_03)==HIGH)){
  d=d-1;
  st_4==1;
}
if(digitalRead(sens_03)==HIGH){
    st_4 =0;
  }


if(digitalRead(sens_02) ==HIGH){
  digitalWrite(mot,LOW); digitalWrite(heet,HIGH);
  delay(5000);
  digitalWrite(heet,LOW); digitalWrite(mot,HIGH);
  
}




  
  

}
