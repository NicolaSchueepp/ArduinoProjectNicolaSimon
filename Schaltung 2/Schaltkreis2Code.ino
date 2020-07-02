//RGB LIGHT
const int redPin = 4;
const int bluePin = 3; 
const int greenPin = 2;

//PlayerLEFT
const int left_redButton = 11;
const int left_greenButton = 10;
const int left_blueButton = 9;
const int left_winnerPin = 13;

//PlayerRIGHT
const int right_redButton = 7;
const int right_greenButton = 6;
const int right_blueButton = 5;
const int right_winnerPin = 12;

void setup()
{
  //PINs werden gesetzt
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(11, INPUT);
  pinMode(10, INPUT);
  pinMode(9, INPUT);
  pinMode(13, INPUT);
  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(5, INPUT);
  pinMode(12, INPUT);
}

void loop()
{
  //Random Nummer bestimmt die Farbe der LED
  const int randomNumber = random(1, 4);
  switch (randomNumber) {
  case 1:
    lightRed();
    winnerListener(left_redButton, right_redButton);
    break;
  case 2:
    lightGreen();
    winnerListener(left_greenButton, right_greenButton);
    break;
  case 3:
    lightBlue();
    winnerListener(left_blueButton, right_blueButton);
    break;
  }
  //Neues Spiel
  delay(3000);
  newGame();
}

void winnerListener(int leftPin, int rightPin) {
  //Holt die Inputs der Buttons
  int leftInput = digitalRead(leftPin);
  int rightInput = digitalRead(rightPin);
  
  while (leftInput != HIGH && rightInput != HIGH) {
    leftInput = digitalRead(leftPin);
  	rightInput = digitalRead(rightPin);
  }
  if (leftInput == HIGH && rightInput == HIGH) {
    leftWinner();
    rightWinner();
    return;
  } else if (leftInput == HIGH) {
   	leftWinner();
  } else if (rightInput == HIGH) {
  	rightWinner();
  }
  
}

void leftWinner() {
	digitalWrite(left_winnerPin, HIGH);
}

void rightWinner() {
  	digitalWrite(right_winnerPin, HIGH);
}

void lightBlue() {
	digitalWrite(redPin, LOW);
  	digitalWrite(bluePin, HIGH);
  	digitalWrite(greenPin, LOW);
}

void lightRed() {
	digitalWrite(redPin, HIGH);
  	digitalWrite(bluePin, LOW);
  	digitalWrite(greenPin, LOW);
}

void lightGreen() {
	digitalWrite(redPin, LOW);
  	digitalWrite(bluePin, LOW);
  	digitalWrite(greenPin, HIGH);
}

void resetLED() {
	digitalWrite(redPin, LOW);
  	digitalWrite(bluePin, LOW);
  	digitalWrite(greenPin, LOW);
  	digitalWrite(left_winnerPin, LOW);
  	digitalWrite(right_winnerPin, LOW);
}

void newGame() {
    resetLED();
    delay(3000);
}