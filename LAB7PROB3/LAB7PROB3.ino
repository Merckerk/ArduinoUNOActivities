// C++ code
//

//Keypad header for instantiating and calling a Keypad object
#include <Keypad.h>

//Rows and Columns
const byte rows = 4;
const byte columns = 4;

//2d array of rows and columns in the keypad
char keymap[rows][columns] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
 };

//Pin locations of rows and columns on the arduino board
byte rowPins[rows] = {2, 3, 4, 5};
byte columnPins[columns] = {6, 7, 8, 9};

//Instantiate Keypad object
Keypad keypad1 = Keypad(makeKeymap(keymap), rowPins, columnPins, rows, columns);

bool num1Flag = false;
bool num2Flag = false;
bool ansFlag = false;

String num1, num2;
long deciNum1, deciNum2;
String hexNumber1, hexNumber2;
long answer;
char op;

void setup(){
  Serial.begin(9600);
  Serial.println("\n");
  Serial.println("HEXADECIMAL CALCULATOR");
  Serial.println("------------------\n");
  Serial.println("Enter the first number: ");
}

void loop(){
  char key = keypad1.getKey();

  if(key){
    

    if(key != NO_KEY && (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0')){

      if(num1Flag != true){
        Serial.print(key);
        num1 = num1 + key;
        deciNum1 = num1.toInt();
        hexNumber1 = deciToHex(deciNum1);
      }

      else{
        Serial.print(key);
        num2 = num2 + key;
        deciNum2 = num2.toInt();
        hexNumber2 = deciToHex(deciNum2);
        ansFlag = true;
      }
      
    }

    else if (num1Flag == false && key != NO_KEY && (key)){
      

      if(num1 != " " && num1Flag == false){

        if(key == '*'){
          Serial.println("\nOperations:");
          Serial.println("--------------");
          Serial.println("Button A - Addition");
          Serial.println("Button B - Subtraction");
          Serial.println("Button C - Multiplication");
          Serial.println("Button D - Division");
          Serial.println("Choose your operation: ");
        }
        

        if(key == 'A'){
          Serial.print(" Addition");
          Serial.print("\n");
          Serial.println("\nEnter the second Number: ");
          op = '+';
          num1Flag = true;
          num2Flag = true;
        }

        else if(key == 'B'){
          Serial.print(" Subtraction");
          Serial.print("\n");
          Serial.println("\nEnter the second Number: ");
          op = '-';
          num1Flag = true;
          num2Flag = true;
        }

        else if(key == 'C'){
          Serial.print(" Multiplication");
          Serial.print("\n");
          Serial.println("\nEnter the second Number: ");
          op = '*';
          num1Flag = true;
          num2Flag = true;
        }

        else if(key == 'D'){
          Serial.print(" Division");
          Serial.print("\n");
          Serial.println("\nEnter the second Number: ");
          op = '/';
          num1Flag = true;
          num2Flag = true;
        }
      }
  
    }
    
    else if(ansFlag == true && key != NO_KEY && key == '#'){
      if(op == '+'){
        answer = deciNum1 + deciNum2;
        Serial.print('\n');
        Serial.print(hexNumber1);
        Serial.print(' ');
        Serial.print(op);
        Serial.print(' ');
        Serial.print(hexNumber2);
        Serial.print(" = ");
        Serial.print(deciToHex(answer));
      }

      if(op == '-'){
        answer = deciNum1 - deciNum2;
        Serial.print('\n');
        Serial.print(hexNumber1);
        Serial.print(' ');
        Serial.print(op);
        Serial.print(' ');
        Serial.print(hexNumber2);
        Serial.print(" = ");    
        Serial.print(deciToHex(answer));
      }

      if(op == '*'){
        answer = deciNum1 * deciNum2;
        Serial.print('\n');
        Serial.print(hexNumber1);
        Serial.print(' ');
        Serial.print(op);
        Serial.print(' ');
        Serial.print(hexNumber2);
        Serial.print(" = ");
        Serial.print(deciToHex(answer));
      }

      if(op == '/'){
        answer = deciNum1 / deciNum2;
        Serial.print('\n');
        Serial.print(hexNumber1);
        Serial.print(' ');
        Serial.print(op);
        Serial.print(' ');
        Serial.print(hexNumber2);
        Serial.print(" = ");
        Serial.print(deciToHex(answer));
      }
    }

    else if(key != NO_KEY && key == '*'){
      Serial.println("\nAll values cleared");
      num1 = ' ';
      num2 = ' ';
      num1Flag = false;
      num2Flag = false;
      ansFlag = false;
      op = ' ';
    }
  }
}

String deciToHex(long n){
  String hexNum;
  long remainder;

  while (n > 0){
    remainder = n % 16;
    n = n / 16;

    if(remainder < 10){
      hexNum = String(remainder) + hexNum;
    }

    else{
      switch(remainder){
        case 10:
          hexNum = "A" + hexNum;
          break;
        
        case 11:
          hexNum = "B" + hexNum;
          break;
        
        case 12:
          hexNum = 'C' + hexNum;
          break;
        
        case 13: 
          hexNum = "D" + hexNum;
          break;
        
        case 14:
          hexNum = "E" + hexNum;
          break;
        
        case 15:
          hexNum = "F" + hexNum;
          break;

      }
    }
  }

  return hexNum;
}