
//DEFINE NOTES
#define F2 87
#define FS2 93
#define G2 98
#define GS2 104
#define A2 110
#define AS2 117
#define B2 123
#define C3 131
#define CS3 139
#define D3 147
#define DS3 156
#define E3 165
#define F3 175
#define FS3 185
#define G3 196
#define GS3 208
#define A3 220
#define AS3 233
#define B3 247
#define C4 262
#define CS4 277
#define D4 294
#define DS4 311
#define E4 330
#define F4 349
#define FS4 370
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
#define F6 1397
#define FS6 1480
#define G6 1568
#define GS6 1661
#define A6 1760
#define AS6 1865
#define B6 1976
#define C7 2093
#define CS7 2217
#define D7 2349
#define DS7 2489
#define E7 2637
#define F7 2794
#define FS7 2960
#define G7 3136
#define GS7 3322
#define A7 3520
#define AS7 3729
#define B7 3951
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

int piezo = 12;

int guizhong[] = {};
void setup()
{
  pinMode(piezo, OUTPUT);
  setTimings(72);
}

void loop()
{
  int noteProg[38] = {
    B4,CS5, DS5, B5,
    AS5, GS5, 
    FS5, GS4, AS4, B4, GS5,
    FS5, E5,
    DS5, B4, CS5, DS5, B5,
    AS5, GS5,
    FS5, GS4, AS4, B4, GS5,
    FS5, E5,
    DS5, DS5, GS5, DS5, 
    CS5, GS4,
    FS2, GS3, B3, CS4, FS4 
  };
  int noteDur [38] = {
    eight, eight, eight, eight,
    dHalf, quarter,
    half, eight, eight, eight, eight,
    dHalf, quarter,
    half, eight, eight, eight, eight,
    dHalf, quarter,
    half, eight, eight, eight, eight,
    dHalf, quarter,
    half, eight, quarter, eight,
    half, half,
    sixteenth, sixteenth, sixteenth, sixteenth, half
  };
  
  int size = sizeof(noteProg) / sizeof(noteProg[0]);
  playMelody(noteProg, noteDur, size);
  delay(1000);
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
    play(noteProg[i], dur[i]);
  }
}
