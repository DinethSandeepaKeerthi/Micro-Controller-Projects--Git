#include <Wire.h>
#include <LiquidCrystal_I2C.h>


#define   CONTRAST_PIN   9
#define   BACKLIGHT_PIN  7

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE)


// Creat a set of new characters

;

void setup()
{
  Serial.begin ( 57600 );

  // Switch on the backlight and LCD contrast levels
  pinMode(CONTRAST_PIN, OUTPUT);
  analogWrite ( CONTRAST_PIN, CONTRAST );

  //lcd.setBacklightPin ( BACKLIGHT_PIN, POSITIVE );
  //lcd.setBacklight ( HIGH );
  lcd.backlight();
    
  lcd.begin(16,2);               // initialize the lcd 


  lcd.home ();                   // go home
  lcd.print(" RESISTANCE IS");  
  lcd.setCursor ( 0, 1 );        // go to the next line
  lcd.print ("     FUTILE     ");   
  delay(20000);
  lcd.home ();
  lcd.print("SUCCESSFUL ");
  lcd.setCursor ( 0, 1 ); 
  lcd.print("HORRAY");
  
     
}

void loop()
{
  
}

