int led1 = 2;
int led2 = 4;


void Blink(int K, int M) {
  
  for (int i = 0; i < M; i++){
    digitalWrite(K, HIGH);
    delay(500);
    digitalWrite(K, LOW);
    delay(500);
  }

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  Blink(2, 4);
  Blink(4, 6);
  Blink(7, 3);
}

void loop() {
  // put your main code here, to run repeatedly:

}
