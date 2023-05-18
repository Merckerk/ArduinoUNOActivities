void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Enter Score: ");
  while(!Serial.available()){}

  int score = Serial.parseInt();

  switch(score){
    case 1: 
    case 2:
    case 3:
      score *= 10;
      Serial.println(score);
      break;
    
    case 4: 
    case 5:
    case 6:
      score *= 100;
      Serial.println(score);
      break;
    
    case 7: 
    case 8:
    case 9:
      score *= 1000;
      Serial.println(score);
      break;
    
    default:
      Serial.println("Error!");
  }
}
