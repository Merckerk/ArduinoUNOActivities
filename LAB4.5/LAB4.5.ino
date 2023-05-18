int RED1 = 2;
int RED2 = 3;
int RED3 = 4;
int RED4 = 5;

int GREEN1 = 6;
int GREEN2 = 7;
int GREEN3 = 8;
int GREEN4 = 9;

int SW1 = 10;
int SW2 = 11;
int SW3 = 12;

void offAll(){
  digitalWrite(RED1, LOW);
  digitalWrite(RED2, LOW);
  digitalWrite(RED3, LOW);
  digitalWrite(RED4, LOW);

  digitalWrite(GREEN1, LOW);
  digitalWrite(GREEN2, LOW);
  digitalWrite(GREEN3, LOW);
  digitalWrite(GREEN4, LOW);
}

void Menu(){
  Serial.println("<<<<RUNNING LIGHTS EFFECTS MENU>>>>");
  Serial.println("1. Light Sequence Mode 1");
  Serial.println("2. Light Sequence Mode 2");
  Serial.println("3. Light Sequence Mode 3");
  Serial.println("4. Light Sequence Mode 4");
  Serial.println("5. Light Sequence DIY Mode.");
  Serial.println("Pick an Option: ___________");

  offAll();
  while(digitalRead(SW1) == LOW && digitalRead(SW2) == LOW && digitalRead(SW3) == LOW){}  
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RED1, OUTPUT);
  pinMode(RED2, OUTPUT);
  pinMode(RED3, OUTPUT);
  pinMode(RED4, OUTPUT);

  pinMode(GREEN1, OUTPUT);
  pinMode(GREEN2, OUTPUT);
  pinMode(GREEN3, OUTPUT);
  pinMode(GREEN4, OUTPUT);

  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(SW1) == LOW && digitalRead(SW2) == LOW && digitalRead(SW3) == HIGH){
    Serial.println("OPT1");
    digitalWrite(RED1, HIGH);
    delay(1000);
    digitalWrite(RED1, LOW);
    digitalWrite(RED3, HIGH);
    delay(1000);
    digitalWrite(RED3, LOW);
    digitalWrite(GREEN1, HIGH);
    delay(1000);
    digitalWrite(GREEN1, LOW);
    digitalWrite(GREEN3, HIGH);
    delay(1000);
    digitalWrite(GREEN3, LOW);
    digitalWrite(GREEN4, HIGH);
    delay(1000);
    digitalWrite(GREEN4, LOW);
    digitalWrite(GREEN2, HIGH);
    delay(1000);
    digitalWrite(GREEN2, LOW);
    digitalWrite(RED4, HIGH);
    delay(1000);
    digitalWrite(RED4, LOW);
    digitalWrite(RED2, HIGH);
    delay(1000);
    digitalWrite(RED2, LOW);
    delay(2000);
  }
  
  else if(digitalRead(SW1) == LOW && digitalRead(SW2) == HIGH && digitalRead(SW3) == LOW){
    Serial.println("OPT2");
    digitalWrite(GREEN1, HIGH);
    digitalWrite(RED4, HIGH);
    delay(1000);
    digitalWrite(GREEN2, HIGH);
    digitalWrite(RED3, HIGH);
    delay(1000);
    digitalWrite(GREEN3, HIGH);
    digitalWrite(RED2, HIGH);
    delay(1000);
    digitalWrite(GREEN4, HIGH);
    digitalWrite(RED1, HIGH);
    delay(1000);
    offAll();
    delay(2000);
  }
  
  else if(digitalRead(SW1) == LOW && digitalRead(SW2) == HIGH && digitalRead(SW3) == HIGH){
    Serial.println("OPT3");
    digitalWrite(GREEN4, HIGH);
    digitalWrite(RED1, HIGH);
    delay(1000);
    digitalWrite(GREEN3, HIGH);
    digitalWrite(RED2, HIGH);
    delay(1000);
    digitalWrite(GREEN2, HIGH);
    digitalWrite(RED3, HIGH);
    delay(1000);
    digitalWrite(GREEN1, HIGH);
    digitalWrite(RED4, HIGH);
    delay(1000);
    offAll();
    delay(2000);
  }
  
  else if(digitalRead(SW1) == HIGH && digitalRead(SW2) == LOW && digitalRead(SW3) == LOW){
    Serial.println("OPT4");
    digitalWrite(RED2, HIGH);
    digitalWrite(RED1, HIGH);
    delay(1000);
    digitalWrite(RED3, HIGH);
    digitalWrite(RED4, HIGH);
    delay(1000);
    digitalWrite(GREEN1, HIGH);
    digitalWrite(GREEN2, HIGH);
    delay(1000);
    digitalWrite(GREEN3, HIGH);
    digitalWrite(GREEN4, HIGH);
    delay(1000);

    digitalWrite(GREEN3, LOW);
    digitalWrite(GREEN4, LOW);
    delay(1000);
    digitalWrite(GREEN1, LOW);
    digitalWrite(GREEN2, LOW);
    delay(1000);
    digitalWrite(RED3, LOW);
    digitalWrite(RED4, LOW);
    delay(1000);
    digitalWrite(RED1, LOW);
    digitalWrite(RED2, LOW);
    delay(1000);
    offAll();

  }
  
  else if(digitalRead(SW1) == HIGH && digitalRead(SW2) == LOW && digitalRead(SW3) == HIGH){
    Serial.println("OPT5");
    digitalWrite(GREEN3, HIGH);
    digitalWrite(GREEN4, HIGH);
    delay(1000);
    digitalWrite(GREEN1, HIGH);
    digitalWrite(GREEN2, HIGH);
    delay(1000);
    digitalWrite(RED1, HIGH);
    digitalWrite(RED2, HIGH);
    delay(1000);
    digitalWrite(RED3, HIGH);
    digitalWrite(RED4, HIGH);
    delay(1000);
    offAll();
  }
  
  else{
    Menu();
  }
}
