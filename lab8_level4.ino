// C++ code
// 20.07.2021
// Emre YILMAZ

#include <LiquidCrystal.h>
// initialise the Serial LCD
LiquidCrystal lcd(12,11,5,4,3,2); // These pin numbers are hard coded in on the serial backpack board
int button1 = 8; // button1 is set to pin 8
int button2 = 9; // button2 is set to pin 9

// Question Array
String question[] = {"like pizza?", "is Arduino hard?", "like winter?", "older than 25?"};
// Answers
int yesAnswers = 0;;
int noAnswers = 0;;
// while loop
boolean start = true;
boolean start1 = true;
boolean start2 = true;

void setup()
{
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  lcd.begin(16,2);
}

void loop()
{
   
  while(start1){
    for(int i=0; i<=3; i++){ // it will loop the questions 
      start = true;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(question[i]);
      delay(500);
      while(start){
        if(digitalRead(button1) == HIGH){ // if we press button1 the answer yes will be stored
          yesAnswers += 1 ;
          start = false;
        }else if(digitalRead(button2) == HIGH){ // if we press button2 the answer no will be stored
          noAnswers += 1;
          start = false;
        }
      }
    }
    start1 = false;
    start2 = false;
  }
  

  if(digitalRead(button1) == HIGH ){ // At the end if we press the button1 again it will display the results
    start2 = true;
    while(start2){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Yes : ");
      lcd.setCursor(6,0);
      lcd.print(yesAnswers);
      delay(1000);
      lcd.setCursor(0,1);
      lcd.print("No : ");
      lcd.setCursor(5,1);
      lcd.print(noAnswers);
      delay(1000);
      start2 = false;
   
    }
  }

  if(digitalRead(button1) == HIGH){ // And the previous answers will be reset
    yesAnswers = 0;
    noAnswers = 0;
    start1 = true;
  }
  
}
























