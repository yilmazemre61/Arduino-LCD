// C++ code
// 20.07.2021
// Emre YILMAZ

#include <LiquidCrystal.h>
// Initialise the Serial LCD
LiquidCrystal lcd(12,11,5,4,3,2); // These pin numbers are hard code in on the serial backpack board
int button = 8; // button is set to pin 8
boolean start = true;
boolean btn = true;
int btnt = 0; // to create a toggle button 

void setup()
{
  pinMode(button, INPUT);
  lcd.begin(16,2);
}

void loop()
{
  while(start){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("EMRE");
    delay(500);
    start = false;
  }
  
  if(btn){
    if(digitalRead(button) == HIGH){    
      btnt =(btnt + 1) % 3; // toggle button
      // the first iteration's result will be 1 and it will check the condition (btnt == 1)
      // the second iteration's result will be 2 and it will check the condition (btnt == 2)
      // the third iteration's result will be 0 and it will check the condition (btnt == 0)
      btn = false;
    }
  }else{
    if(digitalRead(button) == LOW){
      btn = true; // btn is set to true when the button is released so it can run the if statement for second, third, fourth iteration so on
    }
  }
  
  
 // The text condition for what it should print 
  
 if(btnt == 1){ // It will display "Basketball"
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Basketball");
   delay(500); 
 }else if(btnt == 2){ // It will display "Pizza"
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Pizza");
   delay(500);
 }else if(btnt == 0){ // It will set the start to true 
   start = true; 
 }
  
  
}













