int buttonPin = 9;
int buttonState;
int lastButtonState = LOW;
float lastDebounceTime = 0;
float debounceDelay = 50;
int sevenSegPins[7] = {2, 3, 4, 5, 6, 7, 8};
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
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  //Define input and output pins
  pinMode(buttonPin, INPUT);
  for(int i = 0; i < 7; i++){
  	pinMode(sevenSegPins[i], OUTPUT);
  } //end Define input and output pins
  
  //Set up Serial Communication
  //Display instructions on the computer screen
  //Display initial value (0) on 7-segment display
  display_digit(counter);
  //Display initial value (0) on computer screen

}

void loop() {
  // put your main code here, to run repeatedly:
  //readButton();
    toggleState = digitalRead(toggle);
    Serial.print("Toggle state: ");
    Serial.println(toggleState);
    Serial.print("Counter: ");
    Serial.println(counter);
    if(toggleState == 1){
      counter++;
    	display_digit(counter);
    }else if(toggleState == 0 && counter > 0){
    	counter--;
			display_digit(counter);
    }else{
    	Serial.println("Counter must be non-negative.");
  	}
    delay(750);
  display_digit(counter);
}

void display_digit(int N){
  for(int i; i < 7; i++){
    digitalWrite(sevenSegPins[i], sevenSegDigits[N % 10][i]);
  }
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
  //delay(750);
}