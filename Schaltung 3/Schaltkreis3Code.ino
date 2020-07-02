#include <LiquidCrystal.h>

//deklarierungen der Variabeln
const int rs = 12;
const int en = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int led1 = 10;
const int led2 = 9;
const int led3 = 8;
const int led4 = 7;
String previousString = "";

void setup() {
  lcd.begin(16, 2);
  pinMode(led1, INPUT);
}

void loop() {
  String finalString = " ";
  
  //Erste Lampe wird ausgelesen
  if (digitalRead(led1) == HIGH) {
    finalString += "X";
  } else {
  	finalString += "O";
  }
  finalString += "  ";
  
  //Zweite Lampe wird ausgelesen
  if (digitalRead(led2) == HIGH) {
    finalString += "X";
  } else {
  	finalString += "O";
  }
  finalString += "  ";
  
  //Dritte Lampe wird ausgelesen
  if (digitalRead(led3) == HIGH) {
    finalString += "X";
  } else {
  	finalString += "O";
  }
  finalString += "  ";
  
  //Vierte Lampe wird ausgelesen
  if (digitalRead(led4) == HIGH) {
    finalString += "X";
  } else {
  	finalString += "O";
  }
  finalString += "  ";
  
  //Anzeige beim Display
  if(finalString != previousString) {
    lcd.clear();
    lcd.print(" L1 L2 L3 L4\n");
	lcd.setCursor(0, 1);
  	lcd.print(finalString);
	previousString = finalString;
  }
}