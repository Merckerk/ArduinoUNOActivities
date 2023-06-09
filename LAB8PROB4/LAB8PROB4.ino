#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int ROW_NUM = 4; // Four rows
const int COLUMN_NUM = 4; // Four columns
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte pin_rows[ROW_NUM] = {9, 8, 7, 6}; 
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2}; 
const int buzzerPin = A0;
int ledPins[4] = {10, 11, 12, 13}; //for for loop operations

//password
const char password[] = "1234";

//keypad
Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

char enteredPassword[5]; 
int passwordIndex = 0;
bool passwordCorrect = false;
int remainingTrials = 3; 

LiquidCrystal_I2C lcd(32, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  clearPW();
  for(int i = 0; i < 4; i++){ //stored led pins into an array for for loop operation
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buzzerPin, OUTPUT);
  pinMode(A1, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  if(remainingTrials <= 0){
    auth("KEYPAD LOCK", 10);
  }
  while(remainingTrials <= 0){  //ADDED: handler for 0 tries. blinking LEDS and disabled keypad.
    for(int i = 0; i < 4; i++){
      digitalWrite(ledPins[i], HIGH);
    }
    delay(200);
    offAll();
    delay(200);
  }

  if (key) {
    playButtonSound();
    
    if (key == '#') 
    {
      Serial.print("Entered: ");
      Serial.println(enteredPassword);
      //password checking
      enteredPassword[passwordIndex] = '\0';
      Serial.println(enteredPassword);
      if (strcmp(enteredPassword, password) == 0) 
      {
        passwordCorrect = true;
      }

    if (passwordCorrect) { //nilipat ko yung pw checking logic sa if block ng #
    //LED left to right
    for (int i = 0; i < 4; i++) 
    {
      digitalWrite(ledPins[i], HIGH);
      delay(200);
    }
    
    //reset pw and trials
    passwordCorrect = false;
    remainingTrials = 3;
    auth("WELCOME", 2500);
  }else if (!passwordCorrect && remainingTrials >= 0) {//CHANGED: changed into else if since remainingTrials-- was done even if the pw was correct.
    remainingTrials--;
    if (remainingTrials == 1) {
      //disable keypad
      keypad.setDebounceTime(0);
    }
    
    //LED right to left
    for (int i = 3; i >= 0; i--) {
     // Serial.println(i);
      digitalWrite(ledPins[i], HIGH);
      delay(200);
    }
    
    
    memset(enteredPassword, 0, sizeof(enteredPassword));
    passwordIndex = 0;
    
    //remaining trials left
    auth("ACCESS DENIED", 2500);
    
  }
    offAll(); //LED TURNS OFF after password attempt whether it is correct or not.
    Serial.println(remainingTrials);  //diagnostic purposes. can be deleted if desired.
    Serial.println(passwordCorrect);

      
      //reset buffer
      memset(enteredPassword, 0, sizeof(enteredPassword));
      passwordIndex = 0;
      clearPW();
    } else if (key == '*') {
      //clear password
      memset(enteredPassword, 0, sizeof(enteredPassword));
      passwordIndex = 0;
      clearPW();
    } else {
      lcd.print(key);
      enteredPassword[passwordIndex] = key;
      passwordIndex++;
     
      if (passwordIndex >= sizeof(enteredPassword) - 1) {
        passwordIndex = sizeof(enteredPassword) - 1;
      }
    }
  }
}

void clearPW(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
  lcd.setCursor(0, 1);
}

void auth(String mess, int del){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(mess);
  delay(del);
}

void playButtonSound() {
  tone(buzzerPin, 1000, 200); 
    delay(100); 
    noTone(buzzerPin);
}

void offAll(){  //ADDED: a function which turns off LEDS
  for(int i = 0; i < 4; i++){
    digitalWrite(ledPins[i], LOW);
  }
}