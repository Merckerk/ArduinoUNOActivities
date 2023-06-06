int piezo = 11;

int buttons[8] = {2,3,4,5,6,7,8,9};

int notesArr[8] = {523, 587, 659, 698, 784, 880, 988, 1047};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(piezo, OUTPUT);
  for(int i = 0; i < 8; i++){
    pinMode(buttons[i], INPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 8; i++){
    if(digitalRead(buttons[i]) == HIGH){
      Serial.print("button: ");
      Serial.print(i);
      Serial.println(digitalRead(buttons[i]));
      tone(piezo, notesArr[i]);
      while(digitalRead(buttons[i]));
    }else{
      noTone(piezo);
    }
  }
}
