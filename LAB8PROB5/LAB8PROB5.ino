//Hot or cold but for numbers
//Enter number from 1-100
//then press # to submit your number that you guessed.

#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS); 

int randomNumber;
int inputNumber;
String inputString = "";
int playCount = 0;


void setup()
{
  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  lcd.setCursor(4,0);
  lcd.print("GUESSING");
  lcd.setCursor(6,1);
  lcd.print("GAME");
  delay(1500);
  lcd.clear();
  
  lcd.setCursor(3,0);
  lcd.print("GAME START");
  delay(2000);
  
  randomSeed(analogRead(0));
  randomNumber = random(1,100);
  lcd.clear();
  
  lcd.print("Enter a number");
  lcd.setCursor(0,1);
  lcd.print("Between 1-100");
  Serial.begin(9600);
}

void loop()
{
  char key = keypad.getKey();
  
  
  //Display round number and submit the number
  if(key != NO_KEY && key != '#'){
    Serial.print("Round: ");
    Serial.print(playCount);
    Serial.print("   ");
  }
  
  if(playCount == 0 && key != NO_KEY) {
    randomNumber = random(1,100);
  }
  
  if(key>47 && key<58 && key != NO_KEY) { //A number is entered
    makeNumber(key);
    Serial.print("Number: ");
    Serial.println(inputNumber);
    
    if(key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0'){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Round: ");
      lcd.print(playCount);
      lcd.setCursor(0,1);
      lcd.print("Number: ");
      lcd.print(inputNumber);
    }
  }
  
  else if(key == '#' && key != NO_KEY) { //Check input
    Serial.println("New round");
    evaluateInput();
    playCount++;
  }
  
  if(playCount == 5) {
    playCount = 0;
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("GAME OVER");
    delay(2000);
    
    if(key == '#' && key != NO_KEY){
      randomSeed(analogRead(0));
      randomNumber = random(1,100);
      lcd.clear();
      lcd.print("Enter a number");
      lcd.setCursor(0,1);
      lcd.print("Between 1-100");
    }
  }  
}

void makeNumber(char key) {
  inputString += key;
  inputNumber = inputString.toInt();
}

void evaluateInput(){
  
  if(playCount <= 5){
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print("New round");
    delay(1500);
    lcd.clear();
  }
  
  if(randomNumber > inputNumber){
    lcd.print("Hint: Larger");
    lcd.setCursor(0,1);
    lcd.print("Round: ");
    lcd.print(playCount+1);
  } else if(randomNumber < inputNumber){
    lcd.print("Hint: Smaller");
    lcd.setCursor(0,1);
    lcd.print("Round: ");
    lcd.print(playCount+1);
  } else {
    lcd.setCursor(0,0);
    lcd.print("You guessed");
    lcd.setCursor(0,1);
    lcd.print("the number!");
    delay(2000);
    lcd.clear();
    
    lcd.setCursor(0,0);
    lcd.print("Congratulations!");
    playCount = 0;
  }
  inputString = "";
}