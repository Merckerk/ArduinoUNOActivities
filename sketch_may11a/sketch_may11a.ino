int x, y, diff;
int R;

void setup() {
  Serial.begin(9600);

 
  while (!Serial) {
    ; 
  }
}

void loop() {
  Serial.println("Enter the value of x:");
  while (!Serial.available()) {
    ; 
  }
  x = Serial.parseInt(); 
  Serial.print("x = ");
  Serial.println(x);

  Serial.println("Enter the value of y:");
  while (!Serial.available()) {
    ; 
  }
  y = Serial.parseInt(); // Read the user input as an integer
  Serial.print("y = ");
  Serial.println(y);

  // Compute the difference between x and y
  diff = x - y;

  // Perform computations based on the difference
  if (diff < 0) {
    R = x + y;
  } else if (diff == 0) {
    R = 2 * x + 2 * y;
  } else {
    R = x * y;
  }

  // Print the value of R
  Serial.print("R = ");
  Serial.println(R);

  // Input a new set of values
  Serial.println("Press any key to enter new values...");
  while (!Serial.available()) {
    ; 
  }
  Serial.read(); 

  Serial.println("\n\n\n\n\n\n\n\n");

  // Delay 
  delay(100);
}
