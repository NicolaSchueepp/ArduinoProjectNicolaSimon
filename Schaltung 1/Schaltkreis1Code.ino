#include <LiquidCrystal.h>
#include <Keypad.h>

//LCD Display Konstante
const int rs = A0;
const int en = A1;
const int d4 = A2;
const int d5 = A3;
const int d6 = A4;
const int d7 = A5;

//Numpad konstante
const byte ROWS = 4; 
const byte COLS = 4; 
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2};

String ersteZahl = "";
String zweiteZahl = "";
String funktion = "";

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  lcd.begin(16, 2);
}
  
void loop(){
  resetLCD();
  lcd.print("Erste Zahl: ");
  String tmpZahl = "";
  while (ersteZahl == "") {
    char customKey = customKeypad.getKey();
    if(customKey == '1' || customKey == '2' || 
      customKey == '3' || customKey == '4' || 
      customKey == '5' || customKey == '6' || 
      customKey == '7' || customKey == '8' || 
      customKey == '9' || customKey == '0') {
  	  tmpZahl += customKey;
      resetLCD();
      lcd.print("Erste Zahl: ");
      lcd.setCursor(0,1);
      lcd.print(tmpZahl.toInt());
    } else if(customKey == 'D'){
      ersteZahl = tmpZahl;
    }
  }
  
  resetLCD();
  lcd.print("Funktion:");
  while (funktion == "") {
    char customKey = customKeypad.getKey();
    if(customKey == 'A'){
      funktion += "+";
    } else if(customKey == 'B'){
      funktion += "-";
    }
  }
  
  tmpZahl = "";
  resetLCD();
  lcd.print("Zweite Zahl: ");
  while (zweiteZahl == "") {
    char customKey = customKeypad.getKey();
    if(customKey == '1' || customKey == '2' || 
      customKey == '3' || customKey == '4' || 
      customKey == '5' || customKey == '6' || 
      customKey == '7' || customKey == '8' || 
      customKey == '9' || customKey == '0') {
  	  tmpZahl += customKey;
      resetLCD();
      lcd.print("Zweite Zahl: ");
      lcd.setCursor(0,1);
      lcd.print(tmpZahl.toInt());
    } else if(customKey == 'D'){
      zweiteZahl = tmpZahl;
    }
  }
  resetLCD();
  rechnenUndAnzeigen();
  delay(5000);
  ersteZahl = "";
  zweiteZahl = "";
  funktion = "";
}

void rechnenUndAnzeigen(){
  int ersteZahlInt = ersteZahl.toInt();
  int zweiteZahlInt = zweiteZahl.toInt();
  
  int ergebnis;
  if(funktion == "+") {
    ergebnis = ersteZahlInt + zweiteZahlInt;
  } else if(funktion == "-") {
    ergebnis = ersteZahlInt - zweiteZahlInt;
  }
  
  lcd.print("Ergebnis: ");
  lcd.setCursor(0, 1);
  lcd.print(ergebnis);
}

void resetLCD() {
	lcd.clear();
    lcd.setCursor(0,0);
}
