#include <LiquidCrystal.h>
#define rs 12
#define en 8 
#define d4 2
#define d5 3
#define d6 4
#define d7 5
#define BUZZER 10
#define DOT 6
#define DASH 9
#define SWITCH 7
#define LED 13

#define A3 220
#define B3 247
#define C4 261
#define CS4 277
#define D4 294
#define E4 330
#define F4 349
#define FS4 369.99
#define G4 392
#define A4 440
#define B4 494
#define C5 523
#define D5 587
#define E5 659
#define F5 698

#define S1 1
#define S2 2
#define S3 3
#define TE 0
#define ENG 0
#define JAP 1

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int mode = 0;
int sv;
float tv;
int lang = ENG;
const char* tit[] = {"WELCOME         ", "\xD6\xB3\xBA\xBF              "};

const char tree[] = {0, 'E', 'T', 'I', 'A', 'N', 'M',
                     'S', 'U', 'R', 'W', 'D', 'K', 'G', 'O',
                     'H', 'V', 'F', 0, 'L', 0, 'P', 'J',
                     'B', 'X', 'C', 'Y', 'Z', 'Q', 0, 0};
const char jtree[] = {'\x00', '\xCD', '\xD1', '\xDE', '\xB2', '\xC0', '\xD6', '\xD7', '\xB3', '\xC5', '\xD4',
                      '\xCE', '\xDC', '\xD8', '\xDA', '\xC7', '\xB8', '\xC1', '\xC9', '\xB6', '\xDB',
                      '\xC2', '\xA6', '\xCA', '\xCF', '\xC6', '\xB9', '\xCC', '\xC8', '\xBF', '\xBA',
                      '\x00', '\x00', '\x00', '\x00', '\xC4', '\xD0', '\xDF', '\x00', '\xB5', '\x00',
                      '\xDD', '\xC3', '\x00', '\xB0', '\xBE', '\x00', '\x00', '\xD2', '\xD3', '\xD5',
                      '\xB7', '\xBB', '\xD9', '\xA4', '\x00', '\xCB', '\xBC', '\xB1', '\x00', '\xBD', '\x00', '\x00'};
                     
const int PROGMEM song[] = {G4, B4, D5, D5,
                            E5, D5,
                            B4, G4, D5, D5, D5,
                            B4, G4,
                            D4, D4, D4, D4, D4, D4,
                            G4, 0, D4,
                            G4, G4,
                            G4, G4, D4, E4, F4,
                            G4, G4,
                            0, B4, G4, A4, B4,
                            D5, D5,
                            B4, B4, G4, B4,
                            D5, B4, A4,
                            A4,
                            E5, D5,
                            A4, B4,
                            D5, B4, 0, D5,
                            B4, A4, B4, G4,
                            B4, 0,
                            D4, E4, G4, G4,
                            B4, B4, D5, D5,
                            A4, A4, A4, E4,
                            A4, D4,
                            G4, G4,
                            B4, B4,
                            D5,
                            G4, B4, D5, D5,
                            E5, D5,
                            B4, G4, D5, D5, D5,
                            B4, 0, G4, 0,
                            D4, G4,
                            B4, G4, D5, D5, D5,
                            B4, 0, G4, 0,
                            D4, G4,
                            D4, G4,
                            D4, G4,
                            G4, 0};
                            
const float PROGMEM t[] = {0.75f, 0.25f, 0.5f, 0.5f,
                           1.0f, 1.0f,
                           0.75f, 0.25f, 0.5f, 0.5f, 0.5f,
                           1.0f, 1.0f,
                           0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f,
                           1.0f, 0.5f, 0.5f,
                           1.5f, 0.5f,
                           0.75f, 0.25f, 0.5f, 0.25f, 0.25f,
                           1.0f, 1.0f,
                           0.5f, 0.5f, 0.5f, 0.25f, 0.25f,
                           1.0f, 1.0f,
                           0.75f, 0.25f, 0.75f, 0.25f,
                           0.75f, 0.25f, 1.0f,
                           2.0f,
                           1.0f, 1.0f,
                           1.0f, 1.0f,
                           0.5f, 0.5f, 0.5f, 0.5f,
                           0.5f, 0.25f, 0.25f, 1.0f,
                           1.0f, 1.0f,
                           0.75f, 0.25f, 0.5f, 0.5f,
                           0.75f, 0.25f, 0.5f, 0.5f,
                           0.5f, 0.25f, 0.25f, 1.0f,
                           1.5f, 0.5f,
                           1.5f, 0.5f,
                           1.5f, 0.5f,
                           2.0f,
                           0.75f, 0.25f, 0.5f, 0.5f,
                           1.0f, 1.0f,
                           0.75f, 0.25f, 0.5f, 0.5f, 0.5f,
                           0.5f, 0.5f, 0.5f, 0.5f,
                           1.0f, 1.0f,
                           0.75f, 0.25f, 0.5f, 0.5f, 0.5f,
                           0.5f, 0.5f, 0.5f, 0.5f,
                           1.0f, 1.0f,
                           1.0f, 1.0f,
                           1.0f, 1.0f,
                           1.0f, 1.0f};
                           
const int PROGMEM song1[] = {G4, E4, F4, G4,
                             A4, A4, A4,
                             G4, G4, G4, F4,
                             E4,
                             A3, B3, C4, CS4,
                             D4, A3, E4,
                             D4,
                             G4, E4, F4, G4,
                             A4, A4, A4,
                             G4, E4, D4,
                             C4, C4,
                             D4, A4,
                             G4, D4, E4,
                             C4};

const float PROGMEM t1[] = {1.5f, 0.5f, 0.5f, 0.5f,
                            2.0f, 0.5f, 0.5f,
                            1.5f, 0.5f, 0.5f, 0.5f,
                            3.0f,
                            1.5f, 0.5f, 0.5f, 0.5f,
                            2.0f, 0.5f, 0.5f,
                            6.0f,
                            1.5f, 0.5f, 0.5f, 0.5f,
                            2.0f, 0.5f, 0.5f,
                            2.0f, 0.5f, 0.5f,
                            2.0f, 1.0f,
                            2.0f, 1.0f,
                            2.0f, 0.5f, 0.5f,
                            6.0f};
                            
const int PROGMEM song2[] = {C4, C4,
                             F4, F4, F4, G4,
                             A4, A4, A4, F4,
                             G4, F4, F4, G4,
                             F4, 0, G4,
                             A4, A4, A4, B4,
                             C5, C5, C5, C5,
                             D5, G4, G4, A4,
                             G4, 0, C5,
                             D5, D5, B4, C5,
                             D5, F5, E5, D5,
                             C5, D5, C5, A4,
                             C5, A4, G4,
                             F4, F4, F4, G4,
                             A4, A4, A4, F4,
                             G4, G4, G4, F4, E4,
                             F4, 0};
                             
const float PROGMEM t2[] = {0.25f, 0.25f,
                            1.0f, 0.5f, 1.0f, 0.5f,
                            1.0f, 0.5f, 1.0f, 0.5f,
                            1.0f, 0.5f, 1.0f, 0.5f,
                            2.0f, 0.5f, 0.5f,
                            1.0f, 0.5f, 1.0f, 0.5f,
                            1.0f, 0.5f, 1.0f, 0.5f,
                            1.0f, 0.5f, 1.0f, 0.5f,
                            1.5f, 0.5f, 0.5f,
                            1.0f, 0.5f, 1.0f, 0.5f,
                            0.5f, 1.5f, 0.5f, 0.5f,
                            1.0f, 0.5f, 1.0f, 0.5f,
                            2.0f, 0.5f, 0.5f,
                            1.0f, 0.5f, 1.0f, 0.5f,
                            1.0f, 0.5f, 1.0f, 0.5f,
                            0.5f, 0.5f, 0.5f, 1.0f, 0.5f,
                            1.5f, 0.5f};
                            
void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER, OUTPUT);
  pinMode(DOT, INPUT);
  pinMode(DASH, INPUT);
  pinMode(SWITCH, INPUT);
  Serial.begin(9600);
  //mode = 1;
  lcd.begin(16, 2);
  lcd.print(tit[lang]);
}

void handle_s1(const float tempo) {
  lcd.setCursor(0, 0);
  lcd.print("CHN    ");
  for (int i = 0; i < sizeof(song) / 2; i++) {
    sv = pgm_read_word_near(song + i);
    tv = pgm_read_float_near(t + i);
    tone(10, sv, tv * 60000 / tempo - 1.0f / 100);
    digitalWrite(13, HIGH);
    delay(tv * 60000 / tempo * 2 / 3);
    digitalWrite(13, LOW);
    delay(tv * 60000 / tempo / 3);
    lcd.setCursor(0, 1);
    lcd.print(i);
    lcd.print(' ');
    lcd.print(sv);
    lcd.print(' ');
    lcd.print(tv);
  }
  lcd.setCursor(0, 0);
  lcd.print(tit[lang]);
  lcd.setCursor(0, 1);
  lcd.print("                ");
  mode = TE;
}

void handle_s2(const float tempo) {
  lcd.setCursor(0, 0);
  lcd.print("\xB7\xAE\xB3\xC9\xCB\xCA\xBB\xD6\xB3\xC5\xD7");
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < sizeof(song1) / 2; i++) {
      sv = pgm_read_word_near(song1 + i);
      tv = pgm_read_float_near(t1 + i);
      tone(10, sv, tv * 60000 / tempo - 1.0f / 100);
      digitalWrite(13, HIGH);
      delay(tv * 60000 / tempo * 2 / 3);
      digitalWrite(13, LOW);
      delay(tv * 60000 / tempo / 3);
      lcd.setCursor(0, 1);
      lcd.print(i);
      lcd.print(' ');
      lcd.print(sv);
      lcd.print(' ');
      lcd.print(tv);
    }
  }
  lcd.setCursor(0, 0);
  lcd.print(tit[lang]);
  lcd.setCursor(0, 1);
  lcd.print("                ");
  mode = TE;
}

void handle_s3(const float tempo) {
  lcd.setCursor(0, 0);
  lcd.print("Ramblin' Wreck  ");
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < sizeof(song2) / 2; i++) {
      sv = pgm_read_word_near(song2 + i);
      tv = pgm_read_float_near(t2 + i);
      tone(10, sv, tv * 60000 / tempo - 1.0f / 100);
      digitalWrite(13, HIGH);
      delay(tv * 60000 / tempo * 2 / 3);
      digitalWrite(13, LOW);
      delay(tv * 60000 / tempo / 3);
      lcd.setCursor(0, 1);
      lcd.print(i);
      lcd.print(' ');
      lcd.print(sv);
      lcd.print(' ');
      lcd.print(tv);
    }
  }
  lcd.setCursor(0, 0);
  lcd.print(tit[lang]);
  lcd.setCursor(0, 1);
  lcd.print("                ");
  mode = TE;
}

char decode(char* buf) {
  int i = 0;
  for (char* c = buf; *c; c++) {
    i <<= 1;
    i += *c == '.' ? 1 : 2; 
  }
  return lang ? (i < sizeof(jtree) ? jtree[i] : 0) : (i < sizeof(tree) ? tree[i] : 0);
}

void handle_te() {
  static int curs = 0;
  static char scr[17];
  int cnt = 0;
  char buf[7] = {0};
  int i = 0;
  while (i < 5 && cnt < 16000) {
    if (digitalRead(SWITCH) == HIGH) {
      lang = !lang;
      lcd.setCursor(0, 0);
      lcd.write(tit[lang]);
      memset(buf, 0, 7);
      memset(scr, 0, 16);
      lcd.setCursor(0, 1);
      lcd.write("                ");
      lcd.setCursor(0, 1);
      curs = 0;
      delay(200);
      return;
    }
    if (digitalRead(DOT) == HIGH) {
      cnt = 0;
      buf[i++] = '.';
      digitalWrite(13, HIGH);
      digitalWrite(LED, HIGH);
      tone(BUZZER, C4, 100);
      delay(200);
      digitalWrite(13, LOW);
    } else if (digitalRead(DASH) == HIGH) {
      cnt = 0;
      buf[i++] = '-';
      tone(BUZZER, C4, 180); 
      digitalWrite(13, HIGH);
      delay(200);
      digitalWrite(13, LOW);
    }
    cnt++;
  }
  buf[i] = 0;
  char out = decode(buf);
  if (out) {
    scr[curs % 16] = out;
    scr[(curs + 1) % 16] = 0; 
    lcd.setCursor(curs++ % 16, 1);
    lcd.write(out);    
  }
  if (!strcmp(scr, "CHN")) {
    mode = S1;
    curs = 0;
    memset(scr, 0, 16); 
  }
  if (!strcmp(scr, "SYNR")) {
    mode = S2;
    curs = 0;
    memset(scr, 0, 16); 
  }
  if (!strcmp(scr, "\xBB\xD6\xB3\xC5\xD7")) {
    mode = S2;
    curs = 0;
    memset(scr, 0, 16); 
  }
  if (!strcmp(scr, "GT")) {
    mode = S3;
    curs = 0;
    memset(scr, 0, 16);
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  switch(mode) {
  case S1:
    handle_s1(100.0f);
    break;
  case S2:
    handle_s2(90.0f);
    break;
  case S3:
    handle_s3(135.0f);
    break;
  case TE: 
    lcd.setCursor(0, 1);
    handle_te();
  }
}
