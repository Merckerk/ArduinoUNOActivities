#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment object
int LDR_PIN = A0;

void setup() {
  Serial.begin(9600);
  byte numDigits = 4;
  byte digitPins[] = {2,3,4,5};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_ANODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = false; // Use 'true' if your decimal point doesn't exist or isn't connected. Then, you only need to specify 7 segmentPins[]

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
  updateWithDelays, leadingZeros, disableDecPoint);
}
void loop() {
  marquee4(); //program 6
}
void shiftString(String& inputString, int shiftAmount, bool shiftRight) {
  int length = inputString.length();
  shiftAmount = shiftAmount % length; // Ensure shift amount is within range so no reset index needed
  String shiftedString; 

  shiftRight ?
  //shift to Right
  shiftedString = inputString.substring(length - shiftAmount) + inputString.substring(0, length - shiftAmount):
  //shift to left
  shiftedString = inputString.substring(shiftAmount) + inputString.substring(0, shiftAmount);

  inputString = shiftedString;
  //Serial.println(inputString);
  String displayStr = inputString.substring(0,4); // change max to number of pins
  char* mes2 = displayStr.c_str();
  sevseg.setChars(mes2); 
}
void marquee4(){
  int sensorValue = analogRead(LDR_PIN); //get LDR value
  String myStr;
  static int index = 0;
  static unsigned long timer = millis();

  if (millis() - timer >= 1000) {
    timer += 1000;
    sensorValue > 500 ? 
    shiftString(myStr = "hello    ",index,true) : //shift to Right if true
    shiftString(myStr = "bye    ",index,false);  //shift to left if false
    Serial.println(sensorValue);
    index++;
  }
  sevseg.refreshDisplay(); //must run repeatedly
}