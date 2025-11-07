 #include <LiquidCrystal.h> 
#include <Keypad.h> )

#define redLED 10
#define greenLED 9

char* password ="145278"; 
int pozisyon = 0; 

const byte rows = 4; 
const byte cols = 4;

char keyMap [rows] [cols] = { 

  {'7', '8', '9', '/'},
  {'4', '5', '6', '*'},
  {'1', '2', '3', '-'},
  {'c', '0', '#', '+'}
};

byte rowPins [rows] = {1, 2, 3, 4}; 
byte colPins [cols] = {5, 6, 7, 8};

Keypad myKeypad = Keypad( makeKeymap(keyMap), rowPins, colPins, rows, cols);

LiquidCrystal lcd (A0, A1, A2, A3, A4, A5); 

void setup(){

  lcd.begin(16, 2);
  pinMode(redLED, OUTPUT);  
  pinMode(greenLED, OUTPUT);
  setLocked (true); 
}

void loop(){

  char whichKey = myKeypad.getKey();
  lcd.setCursor(0, 0);
  lcd.print("    Welcome");
  lcd.setCursor(0, 1);
  lcd.print(" Enter Password");

  if(whichKey == '#'      
  ){

    pozisyon=0;
    setLocked (true);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Door Locked!");
    delay(1000);
    lcd.clear();
  }
  
  if(whichKey == '+'  ||  whichKey == '-'  ||whichKey == '/'  ||whichKey == '*'      
  ){

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Invalid Key!");
    delay(1000);
    lcd.clear();
  }
   if(whichKey == password [pozisyon]){

    pozisyon ++;
  }
  if(pozisyon == 6){
    setLocked (false);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("*** Verified ***");
    delay(3000);
    lcd.clear();
    
  }

}

void setLocked(int locked){
  if(locked){
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    }
    else{
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, HIGH);
    }
  }
