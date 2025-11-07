#define conv 46
#define led 5
#define clndr 4
#define sen_1 2
#define sen_2 3
#define sen_3 18
int x = 1;
void setup() {
  pinMode(conv, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(clndr, OUTPUT);
  pinMode(sen_1, INPUT_PULLUP);
  pinMode(sen_2, INPUT_PULLUP);
  pinMode(sen_3, INPUT_PULLUP);


}

void loop() {


  if (x == 1) {
    digitalWrite(conv, LOW);
    digitalWrite(led, LOW);
    digitalWrite(clndr, LOW);
    x = 2;
  }
  if (x == 2) {
    if (digitalRead(sen_1) == HIGH) {
      x = 3;
    }
  }

  if (x == 3 ) {
    digitalWrite(led, HIGH);
    delay(2000);
    digitalWrite(conv, HIGH);
    x = 4;

  }
  if (x == 4) {
    if (digitalRead(sen_2) == HIGH) {
      x = 5;
    }

  }
  if (x == 5 ) {
    digitalWrite(clndr, HIGH);
    delay(4000);
    digitalWrite(clndr, LOW);
    x = 1;
  } 
  
  if (digitalRead(sen_3) == HIGH) {
    digitalWrite(conv, LOW);
    digitalWrite(led, LOW);
    x = 1;
  } else {
    x = 4;
  }



}
