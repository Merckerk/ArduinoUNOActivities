//Decimal Calculator
//Group 7

//Wait for display text to finish before you type
//Use number keys as usual 
//A, B, C, D for addition, subtraction, multiplication, division
//Press * to clear all values
//Press # to display the answer


//Libraries needed
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4;
const byte COLS = 4;

char keyMap[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};

Keypad keypad1 = Keypad(makeKeymap(keyMap), rowPins, colPins, ROWS, COLS);

bool presentValue = false;
bool nextValue = false;
bool finalValue = false;
String num1, num2;
long longNum1, longNum2;
long answer;
char operation;

void setup()
{
  lcd.init();
  lcd.clear();
  lcd.backlight();
  
  lcd.setCursor(0,0);
  lcd.print("Group 7 Presents");
  delay(2000);
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("Decimal");
  lcd.setCursor(3, 1);
  lcd.print("Calculator");
  delay(3000);
  lcd.clear();
}

void loop()
{
  char key = keypad1.getKey();
  
  if(key != NO_KEY && (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0')){
    if(presentValue != true){
        num1 = num1 + key;
        longNum1 = num1.toInt();
        int numLength = num1.length();
        lcd.setCursor(15 - numLength, 0); //adjusts one space for operator
        lcd.print(num1);
    }

    else{
        num2 = num2 + key;
        longNum2 = num2.toInt();
        int numLength = num2.length();
        lcd.setCursor(15 - numLength, 1);
        lcd.print(num2);
        finalValue = true;
    }
  }

  else if(presentValue == false && key != NO_KEY && (key == 'A' || key == 'B' || key == 'C' || key == 'D')){
    if(presentValue == false && key == 'A'){
      presentValue = true;
      operation = '+';
      lcd.setCursor(15, 0);
      lcd.print(operation);
    }
    else if(presentValue == false && key == 'B'){
      presentValue = true;
      operation = '-';
      lcd.setCursor(15, 0);
      lcd.print(operation);
    }
    else if(presentValue == false && key == 'C'){
      presentValue = true;
      operation = '*';
      lcd.setCursor(15, 0);
      lcd.print(operation);
    }
    else if(presentValue == false && key == 'D'){
      presentValue = true;
      operation = '/';
      lcd.setCursor(15, 0);
      lcd.print(operation);
    }
    else{
      lcd.setCursor(0,0);
      lcd.print("Press key A-D");
      lcd.setCursor(0,1);
      lcd.print("for operations.");
      delay(2000);
      lcd.clear();
      num1 = "0";
      num2 = "0";
    }
  }

  else if (finalValue == true && key != NO_KEY && key == '#'){
    if(operation == '+'){
      answer = longNum1 + longNum2;
      lcd.clear();
      lcd.setCursor(16,0);
      lcd.autoscroll();
      lcd.print(longNum1);
      lcd.print(operation);
      lcd.print(longNum2);
      lcd.print('=');
      lcd.setCursor(16,1);
      lcd.print(answer);
      lcd.noAutoscroll();
    }
    else if(operation == '-'){
      answer = longNum1 - longNum2;
      lcd.clear();
      lcd.setCursor(16,0);
      lcd.autoscroll();
      lcd.print(longNum1);
      lcd.print(operation);
      lcd.print(longNum2);
      lcd.print('=');
      lcd.setCursor(16,1);
      lcd.print(answer);
      lcd.noAutoscroll();
    }
    else if(operation == '*'){
      answer = longNum1 * longNum2;
      lcd.clear();
      lcd.setCursor(16,0);
      lcd.autoscroll();
      lcd.print(longNum1);
      lcd.print(operation);
      lcd.print(longNum2);
      lcd.print('=');
      lcd.setCursor(16,1);
      lcd.print(answer);
      lcd.noAutoscroll();
    }
    else if(operation == '/'){
      if(longNum2 == 0){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Cannot divide by");
        lcd.setCursor(8, 1);
        lcd.print("0.");
      }

      else if (longNum2 != 0){
        answer = longNum1 / longNum2;
        lcd.clear();
        lcd.setCursor(16,0);
        lcd.autoscroll();
        lcd.print(longNum1);
        lcd.print(operation);
        lcd.print(longNum2);
        lcd.print('=');
        lcd.setCursor(16,1);
        lcd.print(answer);
        lcd.noAutoscroll();
      }
      
    }
    
  }

  else if(key != NO_KEY && key == '*'){
    lcd.clear();
    presentValue = false;
    finalValue = false;
    num1 = "";
    num2 = "";
    answer = 0;
    operation = ' ';
    
    lcd.setCursor(3, 0);
    lcd.print("All values");
    lcd.setCursor(4, 1);
    lcd.print("cleared.");
    delay(2000);
    lcd.clear();
  }
}