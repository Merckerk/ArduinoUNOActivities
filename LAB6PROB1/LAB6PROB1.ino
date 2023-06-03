// C++ code
//
int piezo = 11;

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;
int led8 = 9;

// //frequency of notes
// int c[8] = {33,65,131,262,523,1047,2093,4186};
// int cs[8] = {35,69,139,277,554,1109,2217,4434};
// int d[8] = {37,73,147,294,587,1175,2349,4698};
// int ds[8] = {39,78,156,311,622,1245,2489,4978};
// int e[7] = {41,82,165,330,659,1319,2637};
// int f[7] = {44,87,175,349,698,1397,2794};
// int fs[7] = {46,92,185,370,740,1480,2960};
// int g[7] = {49,98,196,392,784,1568,3136};
// int gs[7] = {52,104,208,415,831,1661,3322};
// int a[7] = {55,110,220,440,880,1760,3520};
// int as[7] = {58,117,233,466,932,1865,3729};
// int b[7] = {62,123,247,494,988,1976,3951};

int notesArr[12][7] = {
  {33,65,131,262,523,1047,2093},//C   0
  {35,69,139,277,554,1109,2217},//CS  1
  {37,73,147,294,587,1175,2349},//D   2
  {39,78,156,311,622,1245,2489},//DS  3
  {41,82,165,330,659,1319,2637},//E   4
  {44,87,175,349,698,1397,2794},//F   5
  {46,92,185,370,740,1480,2960},//FS  6
  {49,98,196,392,784,1568,3136},//G   7
  {52,104,208,415,831,1661,3322},//GS 8
  {55,110,220,440,880,1760,3520},//A  9
  {58,117,233,466,932,1865,3729},//AS 10
  {62,123,247,494,988,1976,3951}//B  11
};

//rickroll
int bpm = 114; 
//for rr: dq, q, 16, 8, h
int quarterDuration;
int half;
int dQuarter;
int quarter;
int eight;
int sixteenth;

void setup()
{
  Serial.begin(9600);
  pinMode(piezo, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);

  // for(int i = 0; i < 8; i++)
  // {
  //   pinMode(led[i], OUTPUT);
  //   digitalWrite(led[i], HIGH);
  //   delay(250);
  //   digitalWrite(led[i], LOW);
  // }
  
  //set note duration
  quarterDuration = (60000)/bpm;
  quarter = quarterDuration;
  Serial.println(quarterDuration);
  
  half = quarter * 2;
  Serial.println(half);
  
  dQuarter = quarter + (quarter / 2);
  Serial.println(dQuarter);
  
  eight = quarter / 2;
  Serial.println(eight);
  
  sixteenth = quarter / 4;
  Serial.println(sixteenth);
}

void loop()
{
  //digitalWrite(led[]);

  playSong();
  lightPattern(quarter);
  offLED();

  adjustTempo(0.75);
  playSong();
  lightPattern(quarter);
  offLED();
  returnTempo();
}

void adjustTempo(float multiplier){
  bpm += int(bpm * (multiplier));
  quarterDuration = (60000)/bpm;
  Serial.println(bpm);
  quarter = quarterDuration;
  Serial.println(quarterDuration);
  
  half = quarter * 2;
  Serial.println(half);
  
  dQuarter = quarter + (quarter / 2);
  Serial.println(dQuarter);
  
  eight = quarter / 2;
  Serial.println(eight);
  
  sixteenth = quarter / 4;
  Serial.println(sixteenth);
}

void returnTempo(){
  bpm = 114;
  quarterDuration = (60000)/bpm;
  Serial.println(bpm);
  quarter = quarterDuration;
  Serial.println(quarterDuration);
  
  half = quarter * 2;
  Serial.println(half);
  
  dQuarter = quarter + (quarter / 2);
  Serial.println(dQuarter);
  
  eight = quarter / 2;
  Serial.println(eight);
  
  sixteenth = quarter / 4;
  Serial.println(sixteenth);
}

void playSong(){
    Serial.println("Start Playing");
  //play(note, octave, duration);

  rest(quarter);
  play(2, 2, eight);
  play(4, 2, eight);
  play(5, 2, eight);
  play(5, 2, eight);
  play(7, 2, eight);
  play(4, 2, eight);

  play(4, 2, sixteenth);
  play(2, 2, sixteenth);
  play(0, 2, eight);
  play(0, 2, half);
  rest(quarter);

  rest(eight);
  play(2, 2, eight);
  play(2, 2, eight);
  play(4, 2, eight);
  play(5, 2, eight);
  play(2, 2, quarter);
  play(0, 2, eight);

  play(0, 3, eight);
  rest(quarter);
  play(0, 3, eight);
  play(7, 2, dQuarter);
  rest(quarter);

  play(2, 2, eight);
  play(2, 2, eight);
  play(4, 2, eight);
  play(5, 2, eight);
  play(4, 2, eight);
  play(5, 2, eight);
  play(7, 2, eight);
  rest(eight);

  rest(eight);
  play(4, 2, eight);
  play(2, 2, eight);
  play(0, 2, dQuarter);
  rest(quarter);

  rest(eight);
  play(2, 2, eight);
  play(2, 2, eight);
  play(4, 2, eight);
  play(5, 2, eight);
  play(2, 2, eight);
  play(0, 2, quarter);

  play(7, 2, eight);
  play(7, 2, eight);
  play(7, 2, eight);
  play(9, 2, eight);
  play(7, 2, quarter);
  rest(quarter);
};

void play(int note, int octave, int duration)
{
  tone(piezo, notesArr[note][octave+2]);
  delay(duration);
  noTone(piezo);
}

void rest(int duration){
  noTone(piezo);
  delay(duration);
}

void lightPattern(int duration){
  digitalWrite(led1,HIGH);
  delay(duration);
  digitalWrite(led2,HIGH);
  delay(duration);
  digitalWrite(led3,HIGH);
  delay(duration);
  digitalWrite(led4,HIGH);
  delay(duration);
  digitalWrite(led5,HIGH);
  delay(duration);
  digitalWrite(led6,HIGH);
  delay(duration);
  digitalWrite(led7,HIGH);
  delay(duration);
  digitalWrite(led8,HIGH);
  delay(duration);
}

void offLED(){
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
}
// void playCs(int note, int octave)
// {
//   tone(piezo, cs[2 + octave]);
//   delay(note);

// }
