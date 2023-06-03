// C++ code
//Global variables for readButton() function
int buttonPin = 9;
int buttonState;
int lastButtonState = LOW;
float lastDebounceTime = 0;
float debounceDelay = 50;
int sevenSegPins[7] = {2, 3, 4, 5, 6, 7, 8};
int dipSwitchIn[4] = {1, 11, 12, 13};
int toggle = 10;
int toggleState = 0;

//end variables for readButton() function

//other global variables
int counter = 0;
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
//end
void setup()
{
  Serial.begin(9600);
  //Define input and output pins
  pinMode(buttonPin, INPUT);
  pinMode(toggle, INPUT);
  for(int i = 0; i < 7; i++){
  	pinMode(sevenSegPins[i], OUTPUT);
  }
  for(int j = 0; j < 4; j++){
    pinMode(dipSwitchIn[j], INPUT);
  }
  //end Define input and output pins
  
  //Set up Serial Communication
  //Display instructions on the computer screen
  //Display initial value (0) on 7-segment display
  for(int i = 0; i < 7; i++){
  	digitalWrite(sevenSegPins[i], sevenSegDigits[0][i]);
  }
  //Display initial value (0) on computer screen
}

void loop()
{
  readButton();
  display_digit(counter);
  //if button is pressed:
  if(buttonState == HIGH){
    if(toggleState == 1){
      counter++;
      
    }else if(toggleState == 0 && counter > 0){
      counter--;
    }
    else{
      Serial.println("Counter must be non-negative.");
    }
    delay(750);
  }else{
    counter = readSwitchInput();
  }
  //Increment Counter
  //Adjust counter for mod-10 operation
  //Display count on computer screen
  //Display count on 7-seg display
}

void readButton(){
  int reading = digitalRead(buttonPin);
  toggleState = digitalRead(toggle);
  
  Serial.print("button read: ");
  Serial.println(reading);
  Serial.print("Counter: ");
  Serial.println(counter);
  Serial.print("toggle state: ");
  Serial.println(digitalRead(toggle));
  
  if (reading != lastButtonState){
    lastDebounceTime = millis();
    Serial.println("Debounce time updated");
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if(reading != buttonState){
      buttonState = reading;
     }
   }
  lastButtonState = reading;
}
void display_digit(int N){
  for(int i = 0; i < 7; i++){
    digitalWrite(sevenSegPins[i], sevenSegDigits[N % 10][i]);
  }
}
int readSwitchInput(){
  int sum = 0;
  for(int i = 0; i < 4; i++){
    if(digitalRead(dipSwitchIn[i]) == HIGH){
      sum += (1 << i);
    }
  }
  return sum;
}