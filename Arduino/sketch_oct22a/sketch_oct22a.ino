#define pump_1 4
#define pump_2 5
#define start 2
#define Stop 3
#define lese_1 19
#define lese_2 18
#define d_1 16
#define d_2 17
#define d_3 20
#define mini_pump 8
#define red 46
#define green 6
#define heter 9
#define motor 7

int x_st_1 = 0;
int x_st_2 = 0;

int x = 0;

void setup() {

  pinMode(pump_1, OUTPUT);
  pinMode(pump_2, OUTPUT);
  pinMode(mini_pump, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(heter, OUTPUT);
  pinMode(motor, OUTPUT);

  pinMode(start, INPUT);
  pinMode(Stop, INPUT);
  pinMode(lese_1, INPUT);
  pinMode(lese_2, INPUT);
  pinMode(d_1, INPUT);
  pinMode(d_2, INPUT);
  pinMode(d_3, INPUT);





}

void loop() {

  if (digitalRead(start) == LOW && x_st_1 == 0) {
    x=x++;
    digitalWrite(red, HIGH);
    x_st_1 = 1;
  }

  if ((digitalRead(start) == LOW)) {
    x_st_1 = 0;
  }

  
  
  if ((digitalRead(lese_1) == LOW && digitalRead(lese_2) == LOW && (x==1) ) || (digitalRead(lese_1) == HIGH && digitalRead(lese_2) == LOW)&& (x==1) ) {
    digitalWrite(pump_1, HIGH);
  }
  if(digitalRead(lese_2) == HIGH) {
    digitalWrite(pump_1, LOW);
    digitalWrite(heter, HIGH);
    delay(5000);
    digitalWrite(pump_2, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(heter, LOW);

  }

  if (digitalRead(lese_1) == HIGH) {
    digitalWrite(pump_2, LOW);
  }






  if ((digitalRead(Stop) == HIGH) && (x_st_2 == 0)) {
    x = 0;
    digitalWrite(green, LOW);
    x_st_1 = 1;
  }

  if ((digitalRead(Stop) == HIGH)) {
    x_st_2 = 0;
  }




}
