int led = 2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, LOW);
  Serial.println("lo");
  delay(500);
  digitalWrite(led, HIGH);
  Serial.println("hi");
  delay(500);
}
