#include <LiquidCrystal.h>
#include "pitches.h"
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

#define S1 1
#define S2 2
#define S3 3
#define GA 4
#define TE 0
#define ENG 0
#define JAP 1

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int mode = 0;
int sv;
float tv;
int lang = ENG;
const char* tit[] = {"WELCOME         ", "\xD6\xB3\xBA\xBF              "};
const char* w[] = {"WIN             ", "\xB6\xC1              "};
const char* l[] = {"LOSE            ", "\xCF\xB9              "};
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
                     
const int PROGMEM song[] = {NOTE_G4, NOTE_B4, NOTE_D5, NOTE_D5,
                            NOTE_E5, NOTE_D5,
                            NOTE_B4, NOTE_G4, NOTE_D5, NOTE_D5, NOTE_D5,
                            NOTE_B4, NOTE_G4,
                            NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4,
                            NOTE_G4, 0, NOTE_D4,
                            NOTE_G4, NOTE_G4,
                            NOTE_G4, NOTE_G4, NOTE_D4, NOTE_E4, NOTE_F4,
                            NOTE_G4, NOTE_G4,
                            0, NOTE_B4, NOTE_G4, NOTE_A4, NOTE_B4,
                            NOTE_D5, NOTE_D5,
                            NOTE_B4, NOTE_B4, NOTE_G4, NOTE_B4,
                            NOTE_D5, NOTE_B4, NOTE_A4,
                            NOTE_A4,
                            NOTE_E5, NOTE_D5,
                            NOTE_A4, NOTE_B4,
                            NOTE_D5, NOTE_B4, 0, NOTE_D5,
                            NOTE_B4, NOTE_A4, NOTE_B4, NOTE_G4,
                            NOTE_B4, 0,
                            NOTE_D4, NOTE_E4, NOTE_G4, NOTE_G4,
                            NOTE_B4, NOTE_B4, NOTE_D5, NOTE_D5,
                            NOTE_A4, NOTE_A4, NOTE_A4, NOTE_E4,
                            NOTE_A4, NOTE_D4,
                            NOTE_G4, NOTE_G4,
                            NOTE_B4, NOTE_B4,
                            NOTE_D5,
                            NOTE_G4, NOTE_B4, NOTE_D5, NOTE_D5,
                            NOTE_E5, NOTE_D5,
                            NOTE_B4, NOTE_G4, NOTE_D5, NOTE_D5, NOTE_D5,
                            NOTE_B4, 0, NOTE_G4, 0,
                            NOTE_D4, NOTE_G4,
                            NOTE_B4, NOTE_G4, NOTE_D5, NOTE_D5, NOTE_D5,
                            NOTE_B4, 0, NOTE_G4, 0,
                            NOTE_D4, NOTE_G4,
                            NOTE_D4, NOTE_G4,
                            NOTE_D4, NOTE_G4,
                            NOTE_G4, 0};
                            
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
                           
const int PROGMEM song1[] = {NOTE_G5, NOTE_E5, NOTE_F5, NOTE_G5,
                             NOTE_A5, NOTE_A5, NOTE_A5,
                             NOTE_G5, NOTE_G5, NOTE_G5, NOTE_F5,
                             NOTE_E5,
                             NOTE_A4, NOTE_B4, NOTE_C5, NOTE_CS5,
                             NOTE_D5, NOTE_A4, NOTE_E5,
                             NOTE_D5,
                             NOTE_G4, NOTE_E5, NOTE_F5, NOTE_G5,
                             NOTE_A5, NOTE_A5, NOTE_A5,
                             NOTE_G5, NOTE_E5, NOTE_D5,
                             NOTE_C5, NOTE_C5,
                             NOTE_D5, NOTE_A5,
                             NOTE_G5, NOTE_D5, NOTE_E5,
                             NOTE_C5};

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
                            
const int PROGMEM song2[] = {NOTE_C4, NOTE_C4,
                             NOTE_F4, NOTE_F4, NOTE_F4, NOTE_G4,
                             NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4,
                             NOTE_G4, NOTE_F4, NOTE_F4, NOTE_G4,
                             NOTE_F4, 0, NOTE_G4,
                             NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4,
                             NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5,
                             NOTE_D5, NOTE_G4, NOTE_G4, NOTE_A4,
                             NOTE_G4, 0, NOTE_C5,
                             NOTE_D5, NOTE_D5, NOTE_B4, NOTE_C5,
                             NOTE_D5, NOTE_F5, NOTE_E5, NOTE_D5,
                             NOTE_C5, NOTE_D5, NOTE_C5, NOTE_A4,
                             NOTE_C5, NOTE_A4, NOTE_G4,
                             NOTE_F4, NOTE_F4, NOTE_F4, NOTE_G4,
                             NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4,
                             NOTE_G4, NOTE_G4, NOTE_G4, NOTE_F4, NOTE_E4,
                             NOTE_F4, 0};
                             
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
  randomSeed(analogRead(0));
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

void handle_ga() {
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  char up[16];
  char down[16];
  byte uq[5];
  byte dq[5];
  byte uh, ut, dh, dt;
  uh = ut = dh = dt = 0;
  byte win = 0;
  byte lose = 0;
  bool pos = 0;
  lcd.setCursor(pos, 0);
  lcd.print('>');
  memset(up, ' ', 15);
  memset(down, ' ', 15);
  up[15] = down[15] = 0;
  memset(uq, 15, 5);
  memset(dq, 15, 5);
  unsigned long last_press, last_render, last_gen;
  last_press = last_render = last_gen = millis();
  while (!win && !lose) {
    unsigned long time_now = millis();
    if (time_now - last_press >= 200) {
      last_press = time_now;
      int is_pressed = digitalRead(DASH);
      if (is_pressed) {
        lcd.setCursor(0, pos);
        lcd.print(' ');
        pos = !pos;
        lcd.setCursor(0, pos);
        lcd.print('>');
      }
    } else if (time_now - last_render >= 1000) {
      last_render = time_now;
      tone(BUZZER, 440, 500.0f);
      lose = uh != 5 && uq[uh] == 0 && !pos || dh != 5 && dq[dh] == 0 && pos;
      if (lose) break;
      if (uh < 5 && !uq[uh]) uh++;
      if (dh < 5 && !dq[dh]) dh++;
      win = (uh == 5 && dh == 5);
      if (win) break;
                                                                                                                                                                                                                                                 
      if (uh < 5) for (byte i = uh; i < ut; uq[i++]--);
      memset(up, ' ', 15);
      if (uh < 5) for (byte i = uh; i < ut; up[uq[i++]] = '<');
      lcd.setCursor(1, 0);
      lcd.print(up);
      if (dh < 5) for (byte i = dh; i < dt; dq[i++]--);
      memset(down, ' ', 15);
      if (dh < 5) for (byte i = dh; i < dt; down[dq[i++]] = '<');
      lcd.setCursor(1, 1);
      lcd.print(down);
      
      
      Serial.print("up:   ");
      Serial.print(uh);
      Serial.print(',');
      Serial.print(ut);
      Serial.print(',');
      Serial.println(uq[uh]);
      Serial.print("down: ");
      Serial.print(dh);
      Serial.print(',');
      Serial.print(dt);
      Serial.print(',');
      Serial.println(dq[uh]);
    } else if (time_now - last_gen >= 2000) {
      last_gen = time_now;
      if (ut < 5 && dt < 5) {
        byte p = random(2);
        if (p) {
          ut++;
        } else {
          dt++;
        }
      } else if (ut < 5) {
        ut++;
      } else if (dt < 5) {
        dt++;
      }
    }
    
    
  }
  lcd.setCursor(0, 0);
  lcd.print(win ? w[lang] : l[lang]);
  lcd.setCursor(0, 1);
  lcd.print("                ");
  while (digitalRead(DASH) == LOW);
  delay(200);
  lcd.setCursor(0, 0);
  lcd.print(tit[lang]);
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
      tone(BUZZER, NOTE_C4, 100);
      delay(200);
      digitalWrite(13, LOW);
    } else if (digitalRead(DASH) == HIGH) {
      cnt = 0;
      buf[i++] = '-';
      tone(BUZZER, NOTE_C4, 180); 
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
  if (!strcmp(scr, "GAME")) {
    mode = GA;
    curs = 0;
    memset(scr, 0, 16);
  }
  if (!strcmp(scr, "\xB9\xDE\xB0\xD1")) {
    mode = GA;
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
  case GA:
    handle_ga();
    break;
  case TE: 
    lcd.setCursor(0, 1);
    handle_te();
  }
}
