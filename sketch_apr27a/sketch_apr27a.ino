char AnsKey[10] = {'T', 'F', 'T', 'T', 'F', 'T', 'T', 'F', 'T', 'F'};
  char Response[10] = {};
  int i = 0;
  int correctAnswers = 0;
  int j = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  Serial.print("Number of correct items: ");
  Serial.println(correctAnswers);
  Serial.print("Number of incorrect items: ");
  Serial.println(10 - correctAnswers);

}
  

void loop() {
  // put your main code here, to run repeatedly:

  for (i = 0; i < 10; i++) {
      //String AnsKey = Serial.readString();
      Response[i] = Serial.read();
    }
  for (j = 0; j < 10; j++) {
    if (Response[j] == AnsKey[j]){
      correctAnswers++;
    }
  }
  

  if(correctAnswers >= 6){
    Serial.println("You PASSED");
  }
  else{
    Serial.println("You FAILED");
  }
    
}
