//Pins 2-4 (RED LED)
//Pins 5-7 (WHITE LED)
//Pins 8-10 (BLUE LED)
//Analog Pin A0 - A4 (Push Buttons)

int lowerLED = 2;
int higherLED = 10;
int piezo = 11;
#define button1 A0
#define button2 A1;
#define button3 A2;
#define button4 A3;
#define button5 A4;

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

    if(analogRead(A0) > 0 && 
    analogRead(A1) <= 0 && 
    analogRead(A2) <= 0 &&
    analogRead(A3) <= 0 &&
    analogRead(A4) <= 0){
      setTone(1);
    }
    else if(analogRead(A1) > 0 && 
    analogRead(A0) <= 0 && 
    analogRead(A2) <= 0 &&
    analogRead(A3) <= 0 &&
    analogRead(A4) <= 0){
      setTone(2);
    }
    
  }
}

void setTone(int input){
  if(input == 1){
    firstSiren();
  }
  else if (input == 2){
    firstSirenTransition();
  }
}

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
