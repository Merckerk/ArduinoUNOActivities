

int sevenSegPins[7] = {2, 3, 4, 5, 6, 7, 8};
byte sevenSegDigits[10][7] =
    {{1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 1, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 1, 1}};

int greenLED = 11;
int yellowLED = 12;
int redLED = 10;

int counter;
void setup()
{
  Serial.begin(9600);
  for(int i = 0; i < 7; i++){
    pinMode(sevenSegPins[i], OUTPUT);
    Serial.print("Pin initialized: ");
    Serial.println(sevenSegPins[i]);
  }
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop()
{
  greenLight();
  yellowLight();
  redLight();
}

void display_digit(int N){
  for(int i = 0; i < 7; i++){
    digitalWrite(sevenSegPins[i], sevenSegDigits[N % 10][i]);
  }
}

void greenLight(){
  digitalWrite(greenLED, HIGH);
  for(int i = 9; i >= 0; i--){
    display_digit(i);
    Serial.println(i);
    delay(1000);
  }
  digitalWrite(greenLED, LOW);
}

void yellowLight(){
  digitalWrite(yellowLED, HIGH);
  for(int i = 1; i >= 0; i--){
    display_digit(i);
    Serial.println(i);
    delay(1000);
  }
  digitalWrite(yellowLED, LOW);
}

void redLight(){
  digitalWrite(redLED, HIGH);
  for(int i = 8; i >= 0; i--){
    display_digit(i);
    Serial.println(i);
    delay(1000);
  }
  digitalWrite(redLED, LOW);
}