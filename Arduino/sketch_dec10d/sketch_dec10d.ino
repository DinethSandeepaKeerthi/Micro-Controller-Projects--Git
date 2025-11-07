#include <LiquidCrystal.h>
#include <Servo.h>
Servo srv;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define red A1
#define green A2
#define m_sen A0
#define serv_vl 9

int msrd = 0;
int msrd_pr = 0;


void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(m_sen, INPUT);
  pinMode(serv_vl, OUTPUT);
  srv.attach(9);
  lcd.begin(16, 2);





}

void loop() {
  msrd = analogRead(m_sen);
  msrd_pr = map(msrd, 700, 1015, 100, 0);

  lcd.print("mors = ");
  lcd.print(msrd_pr);
  lcd.print("%");
  lcd.setCursor(1,1);
  delay(500);
  

  if (msrd_pr < 60) {
    int x = map(msrd_pr, 0, 60, 0, 180);
    srv.write(x);
    delay(20);
    lcd.print("watering");
    delay(500);
    
  }else{
    srv.write(180);
    lcd.print("not watering");
    delay(500);
    
  }
   delay(250);




}
