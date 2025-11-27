#include <LedControl.h>

LedControl m(12, 10, 11, 1);

byte a[8];   // grid curent
byte b[8];   // grid urmator
byte old[8]; // grid anterior

bool cell(byte g[8], int r, int c) {
  if(r < 0 || r > 7 || c < 0 || c > 7) return 0;
  return (g[r] >> c) & 1;
}

byte vecini(byte g[8], int r, int c) {
  byte v = 0;
  for(int dr=-1; dr<=1; dr++)
    for(int dc=-1; dc<=1; dc++)
      if(!(dr==0 && dc==0))
        v += cell(g, r+dr, c+dc);
  return v;
}

void calc() {
  for(int r=0; r<8; r++) {
    b[r] = 0;
    for(int c=0; c<8; c++) {
      byte e = cell(a, r, c);
      byte n = vecini(a, r, c);
      if( (e && (n==2 || n==3)) || (!e && n==3) )
        b[r] |= (1<<c);
    }
  }
}

void afiseaza(byte g[8]) {
  for(int r=0; r<8; r++)
    m.setRow(0, r, g[r]);
}

bool egal(byte x[8], byte y[8]) {
  for(int i=0;i<8;i++)
    if(x[i] != y[i]) return false;
  return true;
}

bool gol(byte g[8]) {
  for(int i=0;i<8;i++)
    if(g[i] != 0) return false;
  return true;
}

void randomGrid() {
  for(int i=0;i<8;i++)
    a[i] = random(0, 256);
  if(gol(a)) randomGrid();
}

void setup() {
  m.shutdown(0,false);
  m.setIntensity(0,8);
  m.clearDisplay(0);

  randomSeed(analogRead(A0));
  randomGrid();
  afiseaza(a);
}

void loop() {
  delay(200);

  for(int i=0;i<8;i++) old[i] = a[i];

  calc();
  afiseaza(b);

  for(int i=0;i<8;i++) a[i] = b[i];

  if(gol(a) || egal(a, old)) {
    delay(300);
    randomGrid();
    afiseaza(a);
  }
}#include <LedControl.h>

LedControl m(12, 10, 11, 1);

byte a[8];   // grid curent
byte b[8];   // grid urmator
byte old[8]; // grid anterior

bool cell(byte g[8], int r, int c) {
  if(r < 0 || r > 7 || c < 0 || c > 7) return 0;
  return (g[r] >> c) & 1;
}

byte vecini(byte g[8], int r, int c) {
  byte v = 0;
  for(int dr=-1; dr<=1; dr++)
    for(int dc=-1; dc<=1; dc++)
      if(!(dr==0 && dc==0))
        v += cell(g, r+dr, c+dc);
  return v;
}

void calc() {
  for(int r=0; r<8; r++) {
    b[r] = 0;
    for(int c=0; c<8; c++) {
      byte e = cell(a, r, c);
      byte n = vecini(a, r, c);
      if( (e && (n==2 || n==3)) || (!e && n==3) )
        b[r] |= (1<<c);
    }
  }
}

void afiseaza(byte g[8]) {
  for(int r=0; r<8; r++)
    m.setRow(0, r, g[r]);
}

bool egal(byte x[8], byte y[8]) {
  for(int i=0;i<8;i++)
    if(x[i] != y[i]) return false;
  return true;
}

bool gol(byte g[8]) {
  for(int i=0;i<8;i++)
    if(g[i] != 0) return false;
  return true;
}

void randomGrid() {
  for(int i=0;i<8;i++)
    a[i] = random(0, 256);
  if(gol(a)) randomGrid();
}

void setup() {
  m.shutdown(0,false);
  m.setIntensity(0,8);
  m.clearDisplay(0);

  randomSeed(analogRead(A0));
  randomGrid();
  afiseaza(a);
}

void loop() {
  delay(200);

  for(int i=0;i<8;i++) old[i] = a[i];

  calc();
  afiseaza(b);

  for(int i=0;i<8;i++) a[i] = b[i];

  if(gol(a) || egal(a, old)) {
    delay(300);
    randomGrid();
    afiseaza(a);
  }
}