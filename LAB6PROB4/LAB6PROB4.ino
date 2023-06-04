//Pins 2-4 (RED LED)
//Pins 5-7 (WHITE LED)
//Pins 8-10 (BLUE LED)
//Analog Pin A0 - A4 (Push Buttons)

int lowerLED = 2;
int higherLED = 10;
int piezo = 11;
const int button1 = 14;
const int button2 = 15;
const int button3 = 16;
const int button4 = 17;
const int button5 = 18;


int input = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 2; i <= 10; i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 2; i <= 10; i++){
    digitalWrite(i, LOW);

    if(digitalRead(button1) == 1){
      setTone(1);
    }

    else if(digitalRead(button2) == 1){
      setTone(2);
    }

    else if(digitalRead(button3) == 1){
      setTone(3);
    }

    else if(digitalRead(button4) == 1){
      setTone(4);
    }

    else if(digitalRead(button5) == 1){
      setTone(5);
    }
    
  }
}

//-----------------------------------------  Set buzzer tone ----------------------------------------- 
void setTone(int input){
  if(input == 1){
    firstSiren();
  }
  else if (input == 2){
    firstSirenTransition();
  }

  else if(input == 3){
    secondSiren();
  }

  else if(input == 4){
    thirdSiren();
  }

  else if(input == 5){
    fourthSiren();
  }
}

//------------------------------------------ Sirens + LEDs ----------------------------------------- 
void firstSiren() {
  //Whoop up sound + LED

  for(int i = 2; i <= 6; i++){
      digitalWrite(i, HIGH);
    }

  for(int freq = 440; freq < 1000; freq+=25){
    tone(piezo, freq, 50);
    delay(5);

  }
  
  for(int i = 2; i <= 6; i++){
      digitalWrite(i, LOW);
    }

  for(int i = 7; i <= 10; i++){
      digitalWrite(i, HIGH);
    }

  //Whoop down sound + LED
  for(int freq = 1000; freq > 440; freq -=25){
    tone(piezo, freq, 50);
    delay(5);
    
  }

  for(int i = 6; i <= 10; i++){
      digitalWrite(i, LOW);
    }
}

void firstSirenTransition() {
  for(int freq = 440; freq < 1000; freq += 25){
    tone(piezo, freq, 50);
    delay(5);
  }

  if(lowerLED >= 2){
    digitalWrite(lowerLED, HIGH);
    lowerLED = lowerLED + 1;
    digitalWrite(higherLED, HIGH);
    higherLED = higherLED - 1;

    if(lowerLED == 8){
      lowerLED = 2;
    }

    if(higherLED == 7){
      higherLED = 10;
    }
  }

  for(int freq = 1000; freq > 440; freq -= 25){
    tone(piezo, freq, 50);
    delay(5);
  }
}

void secondSiren(){
  for(int freq = 440; freq < 1000; freq += 25){
    tone(piezo, freq, 50);
    delay(5);
  }

  loopForward(2, 10, 20);
  loopBackward(10, 2, 20);

  for(int freq = 1000; freq > 440; freq -= 25){
    tone(piezo, freq, 50);
    delay(5);
  }
}

void thirdSiren(){
  tone(piezo, 440, 200);
  delay(300);

  for(int i = 2; i <= 6; i++){
    digitalWrite(i, HIGH);
    noTone(piezo);
    tone(piezo, 494, 500);
    delay(300);
  }

  for(int i = 2; i <= 6; i++){
    digitalWrite(i, LOW);
    digitalWrite(i + 6, HIGH);
  }

  noTone(piezo);
  tone(piezo, 523, 300);
  delay(200);
  digitalWrite(7, HIGH);
  delay(50);
  digitalWrite(8, HIGH);
  delay(50);
  noTone(piezo);
}

void fourthSiren(){
  for(int i = 2; i <= 9; i +=2){
    digitalWrite(i, HIGH);
  }

  for(int freq = 440; freq < 1000; freq ++){
      tone(piezo, freq, 50);
      delay(5);
    }

  for(int i = 2; i <= 9; i += 2){
    digitalWrite(i, LOW);
  }

  for(int i = 3; i <= 10; i += 2){
    digitalWrite(i, HIGH);
  }

  for(int freq = 1000; freq > 440; freq--){
    tone(piezo, freq, 50);
    delay(5);
  }
}

//--------------------------------- Loop Forward and Backward for LEDs ----------------------------------------------
void loopForward(int startPin, int endPin, int del){
  for(int i = startPin; i <= endPin; i++){
    digitalWrite(i, HIGH);
    delay(del);
    turnLEDOff();
  }

  if(startPin == endPin){
    startPin = 2;
    endPin = 10;
  }
}

void loopBackward(int startPin, int endPin, int dela){
  for(int i = endPin; i >= startPin; i--){
    digitalWrite(i, HIGH);
    delay(dela);
    turnLEDOff();
  }
  
  if(startPin == endPin){
    startPin = 2;
    endPin = 10;
  }
}

//---------------------------------------------------- Turn off all LEDs ---------------------------------------------------------------
void turnLEDOff(){
  for(int i = 2; i <= 10; i++){
    digitalWrite(i, LOW);
  }
}
