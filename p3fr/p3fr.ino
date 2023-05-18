
void setup() {
 Serial.begin(9600);
 while (!Serial);
}
void loop(){
  String dept;
  float purchaseAmt;
  float discountAmt;

  Serial.println("Welcome.");
  Serial.println("Enter department (C - children, L - Ladies, M - Men): ");
  while(Serial.available() == 0);
  
  dept = Serial.readStringUntil('\n');

  if(!(dept.equals("C") || dept.equals("c") || dept.equals("L") || dept.equals("l") || dept.equals("M") || dept.equals("m"))){
    Serial.println("Error");
  }else{
    Serial.println("Enter user purchase amount: ");
    while(Serial.available() == 0);

    purchaseAmt = Serial.parseFloat();
    if(dept.equals("C") || dept.equals("c")){
      if (purchaseAmt >= 0 && purchaseAmt <= 100){
        discountAmt = 0.02;
      } else if(purchaseAmt >= 101 && purchaseAmt <= 200){
        discountAmt = 0.05;
      } else if(purchaseAmt >= 201 && purchaseAmt <= 300){
        discountAmt = 0.075;
      } else if(purchaseAmt > 300){
        discountAmt = 0.10;
      }else{
        Serial.println("Error");
      }
    }else if (dept.equals("L") || dept.equals("l")){
      if (purchaseAmt >= 0 && purchaseAmt <= 100){
        discountAmt = 0.025;
      } else if(purchaseAmt >= 101 && purchaseAmt <= 200){
        discountAmt = 0.075;
      } else if(purchaseAmt >= 201 && purchaseAmt <= 300){
        discountAmt = 0.10;
      } else if(purchaseAmt > 300){
        discountAmt = 0.125;
      }else{
        Serial.println("Error");
      }
    }else if (dept.equals("M") || dept.equals("m")){
      if (purchaseAmt >= 0 && purchaseAmt <= 100){
        discountAmt = 0.05;
      } else if(purchaseAmt >= 101 && purchaseAmt <= 200){
        discountAmt = 0.1;
      } else if(purchaseAmt >= 201 && purchaseAmt <= 300){
        discountAmt = 0.125;
      } else if(purchaseAmt > 300){
        discountAmt = 0.15;
      }else{
        Serial.println("Error");
      }
    }


    float disAmt = purchaseAmt * discountAmt;
    float total = purchaseAmt - disAmt;
    Serial.print("This user will get: ");
    Serial.print(discountAmt);
    Serial.println("% discount.");
    Serial.print("Discount  amount: PHP ");
    Serial.println(disAmt);
    Serial.print("Net amount to pay: PHP");
    Serial.println(total);
  }
}