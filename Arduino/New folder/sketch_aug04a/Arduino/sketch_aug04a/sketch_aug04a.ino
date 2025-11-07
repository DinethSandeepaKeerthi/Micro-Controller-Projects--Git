char val;

void setup() {
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(6,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT);
 pinMode(11,OUTPUT);

 Serial.begin(9600);
}

void loop() {
  int t=300;
  int p=200;

  if(Serial.available()){
   val= Serial.read();
   Serial. println(val);
  }
  if(val=='1'){
  
  digitalWrite(2,HIGH); digitalWrite(11,HIGH);
  delay(t);
  digitalWrite(2,LOW); digitalWrite(11,LOW);
  delay(t);

  digitalWrite(3,HIGH); digitalWrite(10,HIGH);
  delay(t);
  digitalWrite(3,LOW); digitalWrite(10,LOW);
  delay(t);

  digitalWrite(4,HIGH); digitalWrite(9,HIGH);
  delay(t);
  digitalWrite(4,LOW); digitalWrite(9,LOW);
  delay(t);

  digitalWrite(5,HIGH); digitalWrite(8,HIGH);
  delay(t);
  digitalWrite(5,LOW); digitalWrite(8,LOW);
  delay(t);

  digitalWrite(6,HIGH); digitalWrite(7,HIGH);
  delay(t);
  digitalWrite(6,LOW); digitalWrite(7,LOW);
  delay(t);

  digitalWrite(5,HIGH); digitalWrite(8,HIGH);
  delay(t);
  digitalWrite(5,LOW); digitalWrite(8,LOW);
  delay(t);

  digitalWrite(4,HIGH); digitalWrite(9,HIGH);
  delay(t);
  digitalWrite(4,LOW); digitalWrite(9,LOW);
  delay(t);

  digitalWrite(3,HIGH); digitalWrite(10,HIGH);
  delay(t);
  digitalWrite(3,LOW); digitalWrite(10,LOW);
  delay(t);
  }

  if(val=='2'){
    for(int i=2; i<12; i=i+1){
      digitalWrite(i,HIGH);
      delay(t);
      digitalWrite(i,LOW);
      
    }
    for(int q=11; q>3; q=q-1){
       digitalWrite(q,HIGH);
      delay(t);
      digitalWrite(q,LOW);
      
    }
  }
  if(val=='3'){
 digitalWrite(2,HIGH); digitalWrite(11,HIGH);
 delay(t);
 digitalWrite(2,LOW); digitalWrite(11,LOW);

  digitalWrite(3,HIGH); digitalWrite(10,HIGH);
 delay(t);
 digitalWrite(3,LOW); digitalWrite(10,LOW);

  digitalWrite(4,HIGH); digitalWrite(9,HIGH);
 delay(t);
 digitalWrite(4,LOW); digitalWrite(9,LOW);

  digitalWrite(5,HIGH); digitalWrite(8,HIGH);
 delay(t);
 digitalWrite(5,LOW); digitalWrite(8,LOW);

  digitalWrite(6,HIGH); digitalWrite(7,HIGH);
 delay(t);
 digitalWrite(6,LOW); digitalWrite(7,LOW);


 digitalWrite(2,HIGH); digitalWrite(11,HIGH);
  delay(p);
  digitalWrite(2,LOW); digitalWrite(11,LOW);
  delay(p);

  digitalWrite(3,HIGH); digitalWrite(10,HIGH);
  delay(p);
  digitalWrite(3,LOW); digitalWrite(10,LOW);
  delay(p);

  digitalWrite(4,HIGH); digitalWrite(9,HIGH);
  delay(p);
  digitalWrite(4,LOW); digitalWrite(9,LOW);
  delay(p);

  digitalWrite(5,HIGH); digitalWrite(8,HIGH);
  delay(p);
  digitalWrite(5,LOW); digitalWrite(8,LOW);
  delay(p);

  digitalWrite(6,HIGH); digitalWrite(7,HIGH);
  delay(p);
  digitalWrite(6,LOW); digitalWrite(7,LOW);
  delay(p);

  digitalWrite(5,HIGH); digitalWrite(8,HIGH);
  delay(p);
  digitalWrite(5,LOW); digitalWrite(8,LOW);
  delay(p);

  digitalWrite(4,HIGH); digitalWrite(9,HIGH);
  delay(p);
  digitalWrite(4,LOW); digitalWrite(9,LOW);
  delay(p);

  digitalWrite(3,HIGH); digitalWrite(10,HIGH);
  delay(p);
  digitalWrite(3,LOW); digitalWrite(10,LOW);
  delay(t);
  }

  if(val=='4'){
    for(int i=2; i<12; i=i+1){
      digitalWrite(i,HIGH);
      delay(p);
      digitalWrite(i,LOW);
      
    }
    for(int q=11; q>3; q=q-1){
       digitalWrite(q,HIGH);
      delay(p);
      digitalWrite(q,LOW);
      
    }
  }
  if(val=='5'){

 digitalWrite(2,HIGH); digitalWrite(11,HIGH);
 delay(p);
 digitalWrite(2,LOW); digitalWrite(11,LOW);

  digitalWrite(3,HIGH); digitalWrite(10,HIGH);
 delay(p);
 digitalWrite(3,LOW); digitalWrite(10,LOW);

  digitalWrite(4,HIGH); digitalWrite(9,HIGH);
 delay(p);
 digitalWrite(4,LOW); digitalWrite(9,LOW);

  digitalWrite(5,HIGH); digitalWrite(8,HIGH);
 delay(p);
 digitalWrite(5,LOW); digitalWrite(8,LOW);

  digitalWrite(6,HIGH); digitalWrite(7,HIGH);
 delay(p);
 digitalWrite(6,LOW); digitalWrite(7,LOW);
    
}
}
