#include<LiquidCrystal.h>

LiquidCrystal  lcd(1,2,4,5,6,7);


void setup() {
  lcd.begin(16,4);

  lcd.setCursor(4,0);
  lcd.print("WELCOME!");
  delay (1000);



  lcd.setCursor(5,1);
  lcd.print("AA2176");
  delay(1000);



  lcd.setCursor(2,2);
  lcd.print("ACTIVITY 002");
  delay(1000);



  lcd.setCursor(0,3);
  lcd.print("PRAXIS BATCH 07A");
  delay(2000);


  lcd.clear();
  delay(200);


  lcd.setCursor(6,0);
  lcd.print("SLTC");

  lcd.setCursor(2,2);
  lcd.print("Machatronics");

  lcd.setCursor(2,3);
  lcd.print("Engineering.");
  
  delay(2000);

  lcd.clear();
  delay(200);

}

void loop() {

  String text01 = "I  LOVE";

  lcd.setCursor(5,1);
  lcd.print(text01);


  String text02 = "MACHATRONICS";

  lcd.setCursor(2,2);
  lcd.print(text02);


  delay(1000);
  
 lcd.clear();
  delay(100);

}
