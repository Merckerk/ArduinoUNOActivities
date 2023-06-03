// C++ code
//
int sevenSegs[7] = {2, 3, 4, 5, 6, 7, 8};
int selector[4] = {12, 11, 10, 9};
int light1;
int light2;

int letters[9][7] = {
  {1, 1, 1, 1, 1, 1, 0}, //0 0
  {0, 0, 0, 1, 1, 1, 0}, //L 1
  {0, 0, 0, 1, 1, 1, 0}, //L 2
  {1, 0, 0, 1, 1, 1, 1}, //E 3
  {0, 1, 1, 0, 1, 1, 1}, //H 4
  
  {1, 0, 0, 1, 1, 1, 1}, //E 5
  {0, 1, 1, 1, 0, 1, 1}, //Y 6
  {1, 1, 1, 1, 1, 1, 1}, //B 7
  
  {0, 0, 0, 0, 0, 0, 0}  //off all 8 
};
void setup()
{
  Serial.begin(9600);
  for(int i = 0; i < 7; i++){
    pinMode(sevenSegs[i], OUTPUT);
  }
  for(int k = 0; k < 4; k++){
    pinMode(selector[k], OUTPUT);
  }
}

void loop()
{
  light1 = analogRead(A0);
  light2 = analogRead(A1);
  Serial.println(light1);
  Serial.println(light2);
  if(light1 > light2){	//left photores. LDR1
    lightUp0(0);
    delay(500);
    lightUp1(0);
    lightUp0(8);
    delay(500);
  }
  // else{
  //   for(int s = 10; s > 3; s--){
  //     for(int k = 3; k >= 0; k--){
  //       if((s - k) > 4 && (s - k) < 8){
  //         lightUp(k, s - k);
  //       }else{
  //         lightUp(k, 8);
  //       }
  //     }
  //     delay(750);
  //   }
  //   //sayonaraHAHAHAHAHAHAXD
  // }
}

void lightUp0(int let){ //seg = seg no. let = letter idx
  								//seg inputs: 0-3. indxs 
  								//of selector
  //Serial.println(seg);
  // digitalWrite(selector[0], HIGH);
  // digitalWrite(selector[1], HIGH);
  // digitalWrite(selector[2], HIGH);
  // digitalWrite(selector[3], HIGH);

  digitalWrite(12, LOW);	//selects seg
  for(int i = 0; i < 7; i++){	//lights up selected seg. accdng
    							//to letter
    digitalWrite(sevenSegs[i], letters[let][i]);
  }
}

void lightUp1(int let){ //seg = seg no. let = letter idx
  								//seg inputs: 0-3. indxs 
  								//of selector
  //Serial.println(seg);
  // digitalWrite(selector[0], HIGH);
  // digitalWrite(selector[1], HIGH);
  // digitalWrite(selector[2], HIGH);
  // digitalWrite(selector[3], HIGH);

  digitalWrite(11, LOW);	//selects seg
  for(int i = 0; i < 7; i++){	//lights up selected seg. accdng
    							//to letter
    digitalWrite(sevenSegs[i], letters[let][i]);
  }
}

void lightUp2(int let){ //seg = seg no. let = letter idx
  								//seg inputs: 0-3. indxs 
  								//of selector
  //Serial.println(seg);
  // digitalWrite(selector[0], HIGH);
  // digitalWrite(selector[1], HIGH);
  // digitalWrite(selector[2], HIGH);
  // digitalWrite(selector[3], HIGH);

  digitalWrite(10, LOW);	//selects seg
  for(int i = 0; i < 7; i++){	//lights up selected seg. accdng
    							//to letter
    digitalWrite(sevenSegs[i], letters[let][i]);
  }
}

void lightUp3(int let){ //seg = seg no. let = letter idx
  								//seg inputs: 0-3. indxs 
  								//of selector
  //Serial.println(seg);
  // digitalWrite(selector[0], HIGH);
  // digitalWrite(selector[1], HIGH);
  // digitalWrite(selector[2], HIGH);
  // digitalWrite(selector[3], HIGH);

  digitalWrite(9, LOW);	//selects seg
  for(int i = 0; i < 7; i++){	//lights up selected seg. accdng
    							//to letter
    digitalWrite(sevenSegs[i], letters[let][i]);
  }
}


