void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Enter Score: ");
  while(!Serial.available()){}

  int score = Serial.parseInt();

  if((score >= 1) && (score <= 3)){
    score *= 10;
    Serial.println(score);
  }

  else if((score >= 4) && (score <= 6)){
    score *= 100;
    Serial.println(score);
  }

  else if((score >= 7) && (score <= 9)){
    score *= 1000;
    Serial.println(score);
  }

  else {
    Serial.println("Error!");
  }
}
