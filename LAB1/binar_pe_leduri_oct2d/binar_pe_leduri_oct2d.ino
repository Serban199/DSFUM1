
void setup() {
  // configuram pinii 8 - 13 
  for (int i = 8; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
}

// afiseaza numarul k in format binar pe ledurile 8 13
void afiseazaBinar(int k) {
  for (int bit = 0; bit < 6; bit++) {
    int stare = (k >> bit) & 1;   // extragem bitul bit
    digitalWrite(8 + bit, stare); // aprindem ledul 
  }
}

void loop() {
  int valoare = (millis() % 6400) / 100;  // numar intre 0 si 63
  afiseazaBinar(valoare);                // afisam pe led