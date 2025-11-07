#include "Wire.h"


byte second =0x00;
byte minute =0x40;
byte hours =0x13;
byte day =0x06;
byte date =0x21;
byte month =0x01;
byte year =0x23;

byte decTobcd (byte val){
  return (((val/10)*16)+(val%10));
}

byte bcdTodec (byte val){
  return (((val/16)*10)+(val%10));
}

void setup() {
  Wire.begin();
  Serial.begin(9600);
  setRtc();
  

}



void setRtc(){
  Wire.beginTransmission(0x68);
  Wire.write(0);
  Wire.write(second);
  Wire.write(minute);
  Wire.write(hours);
  Wire.write(day);
  Wire.write(date);
  Wire.write(month);
  Wire.write(year);
  Wire.endTransmission();
  
   
}

void ReadRtc(){
  Wire.beginTransmission(0x68);
  Wire.write(0);
  Wire.endTransmission();
  Wire.requestFrom(0x68,7);

  second = bcdTodec(Wire.read());
  minute = bcdTodec(Wire.read());
  hours = bcdTodec(Wire.read());
  day = bcdTodec(Wire.read());
  date = bcdTodec(Wire.read());
  month = bcdTodec(Wire.read());
  year = bcdTodec(Wire.read());
  
}


void loop() {
  ReadRtc();
  Serial.println();
  delay(1000);
}
