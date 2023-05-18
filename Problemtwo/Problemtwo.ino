void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  String color1, color2;

  Serial.println("Enter two primary colors: ");

  while(Serial.available() == 0);

  color1 = Serial.readStringUntil(' ');
  color2 = Serial.readStringUntil('\n');

  if (!(color1.equals("red") || color1.equals("blue") || color1.equals("yellow"))|| 
  !(color2.equals("red") || color2.equals("blue") || color2.equals("yellow"))){
    Serial.println("Error!");

  }

  else{
    if((color1.equals("red") && color2.equals("blue")) ||
    (color1.equals("blue") && color2.equals("red"))){
      Serial.println("purple");
    }

    else if((color1.equals("red") && color2.equals("yellow")) ||
    (color1.equals("yellow") && color2.equals("red"))){
      Serial.println("orange");
    }

    else if((color1.equals("blue") && color2.equals("yellow")) ||
    (color1.equals("yellow") && color2.equals("blue"))){
      Serial.println("green");
    }

    else{
      Serial.println("Error!");
    }
  }




}
