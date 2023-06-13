// C++ code
//
int led[8] = {2,3,4,5,6,7,8,9};
int selectors[3] = {14,15,16};
int playButton = 12;
int piezo = 11;
//DEFINE NOTES
#define G4 392
#define GS4 415
#define A4 440
#define AS4 466
#define B4 494
#define C5 523
#define CS5 554
#define D5 587
#define DS5 622
#define E5 659
#define F5 698
#define FS5 740
#define G5 784
#define GS5 831
#define A5 880
#define AS5 932
#define B5 988
#define C6 1047
#define CS6 1109
#define D6 1175
#define DS6 1245
#define E6 1319
#define rest 0

int bpm = 120; 
//for rr: dq, q, 16, 8, h
int quarterDuration;
int half;
int dHalf;
int dQuarter;
int quarter;
int eight;
int sixteenth;
void setup()
{
  Serial.begin(9600);
  for(int i = 0; i < 8; i++){
    pinMode(led[i], OUTPUT);
    digitalWrite(led[i], HIGH);
    delay(100);
    digitalWrite(led[i], LOW);
  }
  for(int j = 0; j < 3; j++){
    pinMode(selectors[j], INPUT);
  }
  pinMode(playButton, INPUT);
  pinMode(piezo, OUTPUT);
}

void loop()
{
  int choice = switchInput();
  if(digitalRead(playButton) == HIGH){
    switch (choice) {
      case 1:
        twinkle();
        break;
      case 2:
        blackSheep();
        break;
      case 3:
        londonBridge();
        break;
      case 4:
        ducks();
        break;
      case 5:
        happy();
        break;
      case 6:
        rain();
        break;
      default:
        break; 
    }
  }
}
int switchInput(){
  int choice = 0;

  for(int i = 0; i < 3; i++){
    if(digitalRead(selectors[i]) == HIGH){
      choice += (1 << i);
      Serial.print("i: ");
      Serial.println(digitalRead(selectors[i]));
    }
  }
  Serial.print("Menu choice: ");
  Serial.println(choice);
  return choice;
}
void setTimings(int newBPM){
  bpm = newBPM;
  quarterDuration = (60000)/bpm;
  quarter = quarterDuration;
  Serial.println(quarterDuration);
  
  half = quarter * 2;
  Serial.println(half);

  dHalf = half + (half / 2);
  Serial.println(dHalf);
  
  dQuarter = quarter + (quarter / 2);
  Serial.println(dQuarter);
  
  eight = quarter / 2;
  Serial.println(eight);
  
  sixteenth = quarter / 4;
  Serial.println(sixteenth);
}

void play(int note, int duration)
{
  tone(piezo, note);
  delay(duration);
  noTone(piezo);
  delay(50);
}

void playMelody(int noteProg[], int dur[], int size) {
  for (int i = 0; i < size; i++) {
    onLight(noteProg[i]);
    play(noteProg[i], dur[i]);
    offLight(noteProg[i]);
  }
}

void onLight(int note){
  if(note == AS4 || note == CS5 || note == DS5 || note == FS5 ||
     note == GS5 || note == AS5 || note == CS6 || note == DS6 || note == GS4){
    digitalWrite(led[7], HIGH);
  }
  if(note == C5 || note == C6 || note == CS6 || note == CS5){
    digitalWrite(led[6], HIGH);
  }else if(note == D5 || note == D6 || note == DS5 || note == DS6){
    digitalWrite(led[5], HIGH);
  }else if(note == E5 || note == E6){
    digitalWrite(led[4], HIGH);
  }else if(note == F5 || note == FS5){
    digitalWrite(led[3], HIGH);
  }else if(note == G4 || note == G5 || note == GS4 || note == GS5){
    digitalWrite(led[2], HIGH);
  }else if(note == A4 || note == A5 || note == AS4 || note == AS5){
    digitalWrite(led[1], HIGH);
  }else if(note == B4 || note == B5){
    digitalWrite(led[0], HIGH);
  }
}
void offLight(int note){
  if(note == AS4 || note == CS5 || note == DS5 || note == FS5 ||
     note == GS5 || note == AS5 || note == CS6 || note == DS6 || note == GS4){
    digitalWrite(led[7], LOW);
  }
  if(note == C5 || note == C6 || note == CS6 || note == CS5){
    digitalWrite(led[6], LOW);
  }else if(note == D5 || note == D6 || note == DS5 || note == DS6){
    digitalWrite(led[5], LOW);
  }else if(note == E5 || note == E6){
    digitalWrite(led[4], LOW);
  }else if(note == F5 || note == FS5){
    digitalWrite(led[3], LOW);
  }else if(note == G4 || note == G5 || note == GS4 || note == GS5){
    digitalWrite(led[2], LOW);
  }else if(note == A4 || note == A5 || note == AS4 || note == AS5){
    digitalWrite(led[1], LOW);
  }else if(note == B4 || note == B5){
    digitalWrite(led[0], LOW);
  }
}

void twinkle()
{
  setTimings(80);
  int noteProg1[14] = {
    G4, G4, D5, D5, E5, E5, D5,
    C5, C5, B4, B4, A4, A4, G4
  };
  int noteProg2[7] = {
    D5, D5, C5, C5, B4, B4, A4
  };
  int noteDur[14] = {
    quarter, quarter, quarter, quarter,
    quarter, quarter, half,
    quarter, quarter, quarter, quarter,
    quarter, quarter, half
  };
  int size = sizeof(noteProg1) / sizeof(noteProg1[0]);
  playMelody(noteProg1, noteDur, size);
  
  for(int j = 0; j < 2; j++){
    size = sizeof(noteProg2) / sizeof(noteProg2[0]);
    playMelody(noteProg2, noteDur, size);
  }
  size = sizeof(noteProg1) / sizeof(noteProg1[0]);
  playMelody(noteProg1, noteDur, size);

  delay(1000);
}

void blackSheep()
{
  setTimings(120);
  int noteProg[38] = {
    D5, D5, A5, A5,
    B5, CS6, D6, B5, A5,
    G5, G5, FS5, FS5,
    E5, E5, D5,
    A5, A5, A5, G5, G5, G5,
    FS5, FS5, FS5, E5, E5,
    A5, A5, A5, G5, A5, B5, G5,
    FS5, E5, E5, D5
  };
  int dur[38] = {
    quarter, quarter, quarter, quarter,
    eight, eight, eight, eight, half,
    quarter, quarter, quarter, quarter,
    quarter, quarter, half,
    quarter, eight, eight, quarter, eight, eight,
    quarter, eight, eight, quarter, quarter,
    quarter, eight, eight, eight, eight, eight, eight,
    quarter, eight, eight, half
  };
  int size = sizeof(noteProg) / sizeof(noteProg[0]);
  playMelody(noteProg, dur, size);
  delay(1000);
}

void londonBridge()
{
  setTimings(150);
  int noteProg[24] = {
    C6, D6, C6, AS5,
    A5, AS5, C6,
    G5, A5, AS5,
    A5, AS5, C6,
    C6, D6, C6, AS5,
    A5, AS5, C6,
    G5, C6, A5, F5
  };
  int noteDur[24] = {
    quarter, quarter, quarter, quarter,
    quarter, quarter, half,
    quarter, quarter, half,
    quarter, quarter, half,
    quarter, quarter, quarter, quarter,
    quarter, quarter, half,
    half, half, quarter, half
  };
  int size = sizeof(noteProg) / sizeof(noteProg[0]);
  playMelody(noteProg, noteDur, size);
  delay(1000);
}

void ducks(){
  setTimings(120);
  int noteProg[36] = {
    E5, D5, D5, C5, C6,
    B5, A5, G5, rest,
    G5, C5, C5, F5, E5,
    E5, D5, D5, rest,
    E5, E5, D5, C5, C6,
    B5, A5, G5, G5,
    G5, C5, F5, E5, E5,
    D5, D5, C5, rest,
  };
  int noteDur[36] = {
    quarter, eight, eight, quarter, quarter,
    quarter, quarter, quarter, quarter,
    quarter, eight, eight, quarter, quarter,
    quarter, quarter, quarter, quarter,
    eight, eight, quarter, quarter, quarter,
    quarter, quarter, quarter, quarter,
    quarter, quarter, quarter, eight, eight,
    quarter, quarter, quarter, quarter
  };
  int size = sizeof(noteProg) / sizeof(noteProg[0]);
  playMelody(noteProg, noteDur, size);
  delay(1000);
}

void happy(){
  setTimings(120);
  int noteProg[49] = {
    G4, G4,
    C5, C5, C5, C5, C5, C5, B4, C5,
    D5, G4, G4,
    D5, D5, D5, D5, D5, D5, C5, D5,
    E5, E5, E5,
    F5, F5, F5, F5, A4, A4, F5, F5,
    E5, E5, E5, D5, C5, C5, E5, E5,
    D5, D5, D5, C5, B4, B4, A4, B4,
    C5
  };
  int noteDur[49] = {
    eight, eight,
    eight, eight, eight, eight, eight, eight, eight, eight,
    dHalf, eight, eight,
    eight, eight, eight, eight, eight, eight, eight, eight,
    dHalf, eight, eight,
    eight, eight, eight, eight, eight, eight, eight, eight,
    eight, eight, eight, eight, eight, eight, eight, eight,
    eight, eight, eight, eight, eight, eight, eight, eight,
    dHalf
  };
  int size = sizeof(noteProg) / sizeof(noteProg[0]);
  playMelody(noteProg, noteDur, size);
  delay(1000);
}

void rain(){
  setTimings(60);
  int noteProg[12] = {
    G5, E5,
    G5, G5, E5,
    G5, G5, E5, A5,
    G5, G5, E5
  };
  int noteDur [12] = {
    quarter, quarter,
    eight, eight, quarter,
    eight, eight, eight, eight,
    eight, eight, quarter
  };
  int size = sizeof(noteProg) / sizeof(noteProg[0]);
  playMelody(noteProg, noteDur, size);
  delay(1000);
}