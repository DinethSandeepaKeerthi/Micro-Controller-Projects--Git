#include <LCD_I2C.h>

#define up_03 4
#define down 5
#define esc_02 3
#define enter_01 2
#define stp_sp 5
#define stp_ang 6
int x;
int y;
LCD_I2C lcd(0x27, 16, 2);


void setup() {
  pinMode(up_03, INPUT_PULLUP);
  pinMode(down, INPUT_PULLUP);
  pinMode(esc_02, INPUT_PULLUP);
  pinMode(enter_01, INPUT_PULLUP);
  pinMode(stp_sp, OUTPUT);
  pinMode(stp_ang, OUTPUT);


  lcd.begin();
  lcd.backlight();



  lcd.setCursor(0, 0);
  lcd.print("01.RUN  02.SPEED");
  lcd.setCursor(4, 1);
  lcd.print("03.REV ");

}
int st = 1;
int ct = 2000;
int rev = 0;
void loop() {

  if (st == 1) {
    lcd.setCursor(4, 0);
    lcd.print("Welcome!!");
    delay(3000);
    lcd.clear();

    st = 2;
  }

  if (st == 2) {
    lcd.setCursor(0, 0);
    lcd.print("01.RUN  02.SPEED");
    lcd.setCursor(4, 1);
    lcd.print("03.REV ");

    st = 3;
  }

  if (st == 3) {
    if (digitalRead(enter_01) == 0) {
      st = 31;
    } else {
      st = 4;
    }

  }

  if (st == 4) {
    if (digitalRead(esc_02) == 0) {
      st = 41;
    } else {
      st = 5;
    }
  }

  if (st == 5) {
    if (digitalRead(up_03) == 0) {
      st = 51;
    } else {
      st = 3;
    }
  }

  //sub parts speed!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  if (st == 41) {

    if (digitalRead(esc_02) == 0) {
      st = 42;
    } else {
      st = 41;
    }
  }

  if (st == 42) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter cyl time");
    lcd.setCursor(0, 1);
    lcd.print(ct);

    st = 43;
  }

  if (st == 43) {
    if (digitalRead(up_03) == 0) {
      st = 431;
    } else {
      st = 44;
    }
  }

  if (st == 44) {
    if (digitalRead(down) == 0) {
      st = 441;
    } else {
      st = 45;
    }
  }

  if (st == 45) {
    if (digitalRead(esc_02) == 0) {
      st = 2;
    } else {
      st = 43;
    }

  }

  if (st == 431) {
    if (ct < 2000) {
      ct = ct + 1;
      delayMicroseconds(200);

      st = 42;
    } else {
      st = 43;
    }

  }

  if (st == 441) {
    if (ct > 800) {
      ct = ct - 1;
      delayMicroseconds(200);

      st = 42;
    } else {
      st = 43;
    }

  }



  //sub parts rev!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  if (st == 51) {

    if (digitalRead(up_03) == 0) {
      st = 52;
    } else {
      st = 51;
    }
  }

  if (st == 52) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Enter rev time");
    lcd.setCursor(0, 1);
    lcd.print(rev);

    st = 53;
  }

  if (st == 53) {
    if (digitalRead(up_03) == 0) {
      st = 531;
    } else {
      st = 54;
    }
  }

  if (st == 54) {
    if (digitalRead(down) == 0) {
      st = 541;
    } else {
      st = 55;
    }
  }

  if (st == 55) {
    if (digitalRead(esc_02) == 0) {
      st = 2;
    } else {
      st = 53;
    }

  }

  if (st == 531) {
    if (rev < 100) {
      rev = rev + 1;
      delayMicroseconds(200);

      st = 52;
    } else {
      st = 53;
    }

  }

  if (st == 541) {
    if (rev > 0) {
      rev = rev - 1;
      delayMicroseconds(200);

      st = 52;
    } else {
      st = 53;
    }

  }






}
