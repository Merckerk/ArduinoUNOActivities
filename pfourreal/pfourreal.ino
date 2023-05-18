void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
float minGr = 100;
float sum = 0;
float average = 0;
void loop() {
  // put your main code here, to run repeatedly:
  //get scores
  Serial.println("\nFinal exam score calculator:");
  float exam1, exam2, exam3, exam4;
  Serial.println("Enter Exam1 score: ");
  exam1 = readScore();
  Serial.println("Enter Exam2 score: ");
  exam2 = readScore();
  Serial.println("Enter Exam3 score: ");
  exam3 = readScore();
  Serial.println("Enter Exam4 score: ");
  exam4 = readScore();

  //find min score
  float lowest = min(exam1, min(exam2, min(exam3, exam4)));
  Serial.print("Your lowest exam score was: ");
  Serial.println(lowest);

  //average score
  float ave = (exam1 + exam2 + exam3 + exam4 - lowest) / 3;
  Serial.print("Your exam average is: ");
  Serial.println(ave, 2);

  if(ave >= 90.0){
    Serial.print("Your grade in the course is an A");
  }else if(ave >= 80.0){
    Serial.print("Your grade in the course is a B");
  }else if(ave >= 70.0){
    Serial.print("Your grade in the course is a C");
  }else if(ave >= 60.0){
    Serial.print("Your grade in the course is a D");
  }else {
    Serial.print("Your grade in the course is an F");
  }
  Serial.print("\nDo you want to try again (y/n)? ");
  while (!Serial.available()); // Wait for user input
  char choice = Serial.read();
  if (choice != 'y' && choice != 'Y') {
 // Exit program
  Serial.println("\nGoodbye!");
  while (true); // Loop forever
 }

}
float readScore(){
  while (!Serial.available()); // Wait for user input
  String input = Serial.readStringUntil('\n');
  float score = input.toFloat();
  while (score < 0.0 || score > 100.0) {
  Serial.println("Invalid score, please try again.");
  while (!Serial.available()); // Wait for user input
  input = Serial.readStringUntil('\n');
  score = input.toFloat();
  }
  return score;
}