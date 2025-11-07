
char code[8];
int n = 0;

bool sts;
void setup() {

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  Serial.begin(9600);

}

void loop() {

  if (Serial.available() > 0) {
    code[n] = Serial.read();
    n = n + 1;
  }
  if (n == 8&&(code[1] == '8'||code[1] == '9')) {
    if (code[0] == '#' && code[1] == '9' && code[2] == '1' && code[3] == '2' && code[4] == '3' && code[5] == '4' && code[6] == '5' && code[7] == '*') {
      Serial.println("activate");
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      sts = true;

    }

    if (code[0] == '#' && code[1] == '8' && code[2] == '5' && code[3] == '4' && code[4] == '3' && code[5] == '2' && code[6] == '1' && code[7] == '*') {
      Serial.println("deactivate");
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      sts = false;


    }
    n = 0;
  }

  if (n == 6 && code[1] == '7' && sts == true) {
    if (code[0] == '#' && code[1] == '7' && code[2] == '0' && code[3] == '1' && code[4] == '1' && code[5] == '*') {
      Serial.println("device_01_ON");
      digitalWrite(2, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(9, LOW);

    }

    if (code[0] == '#' && code[1] == '7' && code[2] == '0' && code[3] == '1' && code[4] == '0' && code[5] == '*') {
      Serial.println("device_01_OFF");
      digitalWrite(8, LOW);
      digitalWrite(2, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(9, LOW);

    }

    if (n == 6 && code[1] == '7' && sts == true) {
      if (code[0] == '#' && code[1] == '7' && code[2] == '0' && code[3] == '2' && code[4] == '1' && code[5] == '*') {
        Serial.println("device_02_ON");
        digitalWrite(2, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(3, LOW);
        digitalWrite(9, HIGH);

      }

      if (code[0] == '#' && code[1] == '7' && code[2] == '0' && code[3] == '2' && code[4] == '0' && code[5] == '*') {
        Serial.println("device_02_OFF");
        digitalWrite(8, LOW);
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        digitalWrite(9, LOW);

      }

n=0;
    }
  }

if(n==8&& code[1] == '6'&& sts == true){
  Serial.println("enter the time");
}


  
}
