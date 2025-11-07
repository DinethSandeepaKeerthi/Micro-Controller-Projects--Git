//define



//display
#include <Wire.h>

#include <LiquidCrystal_I2C.h>

//keypad
#include <Keypad.h>




//display
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); //as wrong scan that address

//keypad
byte rowp [4]={2,3,4,5};
byte colp [4]={6,7,8,9};

char keys[4][4]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

Keypad dineth = Keypad (makeKeymap(keys),rowp,colp,4,4);

//object
int Tall;
int Short;
int Number;
int Total;
int t=150;





void setup() {
 
 pinMode (12,INPUT); //IR 01
 
 pinMode (11,OUTPUT); //motor

 //start
 
 lcd.begin(16,4);
 
 lcd.setCursor(2,1);
 lcd.print ("Starting...!");
 delay(3000);
 lcd.clear();

 lcd.setCursor(2,1);
 lcd.print ("Please Enter");
 lcd.setCursor(3,2);
 lcd.print ("Number of");
 lcd.setCursor(4,3);
 lcd.print ("Products");
 

 Serial.begin(9600);
 
}

void loop() {

  char key = dineth.getKey();
  Number = key;
  
  if(key != NO_KEY){
  lcd.clear();
  lcd.setCursor(1,1);
  lcd.print ("Products:" + Number );
  delay(3000);

  lcd.setCursor(1,1);
  lcd.print ("Plase enter'*'"  );
  lcd.setCursor(5,2);
  lcd.print ("for");
  lcd.setCursor(0,3);
  lcd.print ("Strt to process" );

  if(key =="*"){
    digitalWrite(11,t);
  }

  
  lcd.clear();
  lcd.setCursor(1,1);
  lcd.print ("Processing....");
  lcd.setCursor(3,2);
  lcd.print ("plase wait");

  if(Total == Number){
    lcd.clear();
    lcd.setCursor(2,1);
    lcd.print ("Process end");
    lcd.setCursor(2,2);
    lcd.print ("Plase enter'#'");
    
  }
  if(key =="#"){
    digitalWrite(11,LOW);
  }
}

  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print ("tall:"+Tall);
  lcd.setCursor(1,2);
  lcd.print ("Short"+Short);
  lcd.setCursor(2,2);
  lcd.print ("Total"+Total);


  
} 
void process(){
  int i=0;
  while(i<Number){

  if(12==HIGH){
    Tall++;
    Total++;
    i++;
  }
  else{
    Short++;
    Total++;
    i++;
    
  }
}
    
}











  
  
