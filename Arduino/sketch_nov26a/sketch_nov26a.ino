#include <QTRSensors.h>
QTRSensors qtr;
#define IN0 A0
#define IN1 A1
#define IN2 A2
#define IN3 A3


const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];

void setup(){
  pinMode(IN0,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);

  
  // configure the sensors
  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){3, 4, 5, 6, 7, 8, 9, 10}, SensorCount);
  qtr.setEmitterPin(2);

  delay(500);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); // turn on Arduino's LED to indicate we are in calibration mode

  // 2.5 ms RC read timeout (default) * 10 reads per calibrate() call
  // = ~25 ms per calibrate() call.
  // Call calibrate() 400 times to make calibration take about 10 seconds.
  for (uint16_t i = 0; i < 400; i++)
  {
    qtr.calibrate();
  }
  digitalWrite(LED_BUILTIN, LOW); // turn off Arduino's LED to indicate we are through with calibration

  // print the calibration minimum values measured when emitters were on
  Serial.begin(9600);
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(qtr.calibrationOn.minimum[i]);
    Serial.print(' ');
  }
  Serial.println();

  // print the calibration maximum values measured when emitters were on
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(qtr.calibrationOn.maximum[i]);
    Serial.print(' ');
  }
  Serial.println();
  Serial.println();
  delay(1000);







  
}

int s[8];

void loop()
{
  
  uint16_t position = qtr.readLineBlack(s);
  updatevalue();

 /* if(s[3]==1 && s[4]==1){
    forward();
    delay(50);
  }else if(s[5]==1 && s[4]==1){
    left();
    delay(30);
    forward();
    delay(50); 
  }else if(s[2]==1 && s[3]==1){
    right();
    delay(30);
    forward();
    delay(50); 
  }else if(s[5]==1 && s[6]==1){
    left();
    delay(50);
    forward();
    delay(50); 
  }else if(s[1]==1 && s[2]==1){
    right();
    delay(50);
    forward();
    delay(50); 
  }else if(s[6]==1 && s[7]==1){
    left();
    delay(70);
    forward();
    delay(50); 
  }else if(s[0]==1 && s[4]==1){
    right();
    delay(70);
    forward();
    delay(50); 
  }else if(s[7]==0 && s[6]==0 && s[5]==0 && s[4]==0 && s[3]==0 && s[2]==0 && s[1]==0 && s[0]==0){
    Stop();
    delay(10);
    backward();
    delay(80);  
  }*/
  
int lw = (s[3] + s[2]*2 + s[1]*3 + s[0]*4)*6;
int rw = (s[4] + s[5]*2 + s[6]*3 + s[7]*4)*6;

if((rw+lw)==0){
  backward();
}else{
  left();
  delay(rw);
  right();
  delay(lw);
  forward();
  delay(lw+rw);
}






  
}

void updatevalue(){
  int i=0;
  while(i<8){
    if(s[i]<400){
      s[i]=0;
    }else{
      s[i]=1;
    }
    i=i+1;
  }
}

void forward(){
digitalWrite(IN0,HIGH);  digitalWrite(IN1,LOW);  digitalWrite(IN2,HIGH);digitalWrite(IN3,LOW);
  
}

void backward(){
digitalWrite(IN1,HIGH);  digitalWrite(IN0,LOW);  digitalWrite(IN3,HIGH);digitalWrite(IN2,LOW);
  
}

void left(){
digitalWrite(IN0,HIGH);  digitalWrite(IN1,LOW);  digitalWrite(IN3,HIGH);digitalWrite(IN2,LOW);
  
}

void right(){
digitalWrite(IN1,HIGH);  digitalWrite(IN0,LOW);  digitalWrite(IN2,HIGH);digitalWrite(IN3,LOW);
  
}

void Stop(){
digitalWrite(IN0,HIGH);  digitalWrite(IN1,HIGH);  digitalWrite(IN2,HIGH);digitalWrite(IN3,HIGH);
  
}
