// C++ code
// 20.07.2021
// Emre YILMAZ

#include <LiquidCrystal.h>
// Initialise the Serial LCD
LiquidCrystal lcd(12,11,5,4,3,2); // These pin numbers are hard coded in on the serial bakpack board

void setup()
{
  lcd.begin(16,2); // Initialise the LCD
}

void loop()
{
  for(int i=0; i<13; i++){ // it will start from the first line and index 0 until index 12
    lcd.clear();
    lcd.setCursor(i,0); 
    lcd.print("EMRE");
    delay(500);

  }
  for(int i=12; i>=0; i--){ // it will continue from the second line and index 12 oppositely until index 0
    lcd.clear();
    lcd.setCursor(i,1);
    lcd.print("EMRE");
    delay(500);
  } 

}