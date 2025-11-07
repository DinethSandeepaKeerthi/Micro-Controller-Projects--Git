
#define motor_01 2
#define motor_02 3

#define X01_fl_btn 7
#define X02_fl_btn 8
#define X03_fl_btn 10


#define Y01_fl_sen 4
#define Y02_fl_sen 5
#define Y03_fl_sen 6


int x = 0;
int y = 0;

void setup() {
  pinMode(motor_01, OUTPUT);
  pinMode(motor_02, OUTPUT);

  pinMode(X01_fl_btn, INPUT_PULLUP);
  pinMode(X02_fl_btn, INPUT_PULLUP);
  pinMode(X03_fl_btn, INPUT_PULLUP);


  pinMode(Y01_fl_sen, INPUT_PULLUP);
  pinMode(Y02_fl_sen, INPUT_PULLUP);
  pinMode(Y03_fl_sen, INPUT_PULLUP);


  Serial.begin(9600);




}

void loop() {

  Serial.println(x);
  Serial.println(y);





  if (digitalRead(Y01_fl_sen) == HIGH) {
    x = 1;
  } else if (digitalRead(Y02_fl_sen) == HIGH) {
    x = 2;
  } else if (digitalRead(Y03_fl_sen) == HIGH) {
    x = 3;
  }


  if (digitalRead(X01_fl_btn) == LOW) {
    y = 1;
  } else if (digitalRead(X02_fl_btn) == LOW) {
    y = 2;
  } else if (digitalRead(X03_fl_btn) == LOW) {
    y = 3;
  }


  if (y == 1) {
    if (x == 1) {
      digitalWrite(motor_01, LOW);
      analogWrite(motor_02, 0);
    } else if (x == 2) {
      digitalWrite(motor_01, LOW); //up
      digitalWrite(motor_02, 127);
      if (x == 1) {
        digitalWrite(motor_01, LOW);
        analogWrite(motor_02, 0);
      }
    } else if (x == 3) {
      digitalWrite(motor_01, LOW); //up
      analogWrite(motor_02, 127);
      if (x == 1) {
        digitalWrite(motor_01, LOW);
        analogWrite(motor_02, 0);
      }
    } else if (x == 4) {
      digitalWrite(motor_01, LOW); //up
      analogWrite(motor_02, 127);
      if (x == 1) {
        digitalWrite(motor_01, LOW);
        analogWrite(motor_02, 0);
      }
    }

  }


  if (y == 2) {
    if (x == 2) {
      digitalWrite(motor_01, LOW);
      analogWrite(motor_02, 0);
    } else if (x == 1) {
      digitalWrite(motor_01, HIGH); //down
      analogWrite(motor_02, 127);
      if (x == 2) {
        digitalWrite(motor_01, LOW);
        analogWrite(motor_02, 0);
      }
    } else if (x == 3) {
      digitalWrite(motor_01, LOW); //up
      analogWrite(motor_02, 127);
      if (x == 2) {
        digitalWrite(motor_01, LOW);
        analogWrite(motor_02, 0);
      }
    } else if (x == 4) {
      digitalWrite(motor_01, LOW); //up
      analogWrite(motor_02, 127);
      if (x == 2) {
        digitalWrite(motor_01, LOW);
        analogWrite(motor_02, 0);
      }
    }

  }

  if (y == 3) {
    if (x == 3) {
      digitalWrite(motor_01, LOW);
      analogWrite(motor_02, 0);
    } else if (x == 1) {
      digitalWrite(motor_01, HIGH); //down
      analogWrite(motor_02, 127);
      if (x == 3) {
        digitalWrite(motor_01, LOW);
        analogWrite(motor_02, 0);
      }
    } else if (x == 2) {
      digitalWrite(motor_01, HIGH); //down
      analogWrite(motor_02, 127);
      if (x == 3) {
        digitalWrite(motor_01, LOW);
        analogWrite(motor_02, 0);
      }
    } else if (x == 4) {
      digitalWrite(motor_01, LOW); //up
      analogWrite(motor_02, 127);
      if (x == 3) {
        digitalWrite(motor_01, LOW);
        analogWrite(motor_02, 0);
      }
    }

  }

  if (y == 4) {
    if (x == 4) {
      digitalWrite(motor_01, LOW);
      digitalWrite(motor_02, 0);
    } else if (x == 2) {
      digitalWrite(motor_01, HIGH); //down
      analogWrite(motor_02, 127);
      if (x == 4) {
        digitalWrite(motor_01, LOW);
        analogWrite(motor_02, 0);
      }
    } else if (x == 3) {
      digitalWrite(motor_01, HIGH); //down
      analogWrite(motor_02, 127);
      if (x == 4) {
        digitalWrite(motor_01, LOW);
        analogWrite(motor_02, 0);
      }
    } else if (x == 1) {
      digitalWrite(motor_01, HIGH); //down
      analogWrite(motor_02, 127);
      if (x == 4) {
        digitalWrite(motor_01, LOW);
        analogWrite(motor_02, 0);
      }
    }

  }
























}
