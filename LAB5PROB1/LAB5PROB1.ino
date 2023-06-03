int ledPin[] = {2,3,4,5,6,7,8};
const int numPin = 7;
// para sa 7 segment

int buttonPin = 9;
int buttonState;
int lastButtonState = LOW;
float lastDebounceTime = 0;
float debounceDelay = 50;
int endingState=0;
// para sa debounce

int counter = 0;
byte ledDigits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}, // 9
};

void setup() {
  Serial.begin(9600);
  for(int i=0; i < numPin; i++){
    pinMode(ledPin[i], OUTPUT);
  }
  Serial.println();
  pinMode(buttonPin, INPUT);
  for(int i=0; i < numPin; i++){
    digitalWrite(ledPin[i], ledDigits[0][i]);
  }
}

void loop() {
  readButton();

  if(buttonState == HIGH && endingState == 0){
    counter++;
    for(int i = 0; i < 7; i++){
      digitalWrite(ledPin[i], ledDigits[counter % 10][i]);
    }

  }
 Serial.print("Your count is ");
 Serial.println(counter);
 delay(250);
 endingState=1;
}

void readButton(){
  int reading = digitalRead(buttonPin);
  Serial.println("button read.");
  Serial.println(reading);
  
  if (reading != lastButtonState){
    lastDebounceTime = millis();
    Serial.println("Debounce time updated");
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if(reading != buttonState){
      buttonState = reading;
      if(buttonState == HIGH){
      	counter++;
    		for(int i = 0; i < 7; i++){
  				digitalWrite(ledPin[i], ledDigits[counter % 10][i]);
  			}
      		delay(150);
      }
      	
    }
  }
  lastButtonState = reading;
}