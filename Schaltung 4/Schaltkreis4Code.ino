#include <LiquidCrystal.h>
#include <Keypad.h>

//LCD Display Konstanten
const int rs = A0;
const int en = A1;
const int d4 = A2;
const int d5 = A3;
const int d6 = A4;
const int d7 = A5;

//Numpad konstanten
const byte ROWS = 4; 
const byte COLS = 4; 
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

//Variabeln deklarierung
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2};
String passwort = "ABC123";
String vorherigeEingabe = "";
String eingabe = "";

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  lcd.begin(16, 2);
  resetLCD();
}
  
void loop(){
  //gedrückter Key wird ausgelesen
  char customKey = customKeypad.getKey();
  String tmpString;
  
  if(customKey == '#') {
    //Resetz der Eingabe
  	eingabe = "";
  } else if (customKey == '*') {
    //Passwort prüfen
    if (passwort == eingabe) {
      lcd.clear();
      lcd.print("KORREKT!");
    } else {
      lcd.clear();
      lcd.print("FALSCH!");
      delay(2000);
      resetLCD();
    }
  } else if (customKey != '\0') {
  	eingabe += customKey;
  }
  //Eingabe Beim Display anzeigen
  if(eingabe != vorherigeEingabe) {
    resetLCD();
    lcd.print(eingabe);
    vorherigeEingabe = eingabe;
  }
}

//Display zurücksetzen
void resetLCD() {
	lcd.clear();
    lcd.print("Enter Password:");
    lcd.setCursor(0,1);
}
