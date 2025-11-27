void setup() {
  for (int i = 8; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
}

// ledul de pe pinul 8 clipeste la fiecare secunda
void blinkLed8() {
  int state = (millis() / 1000) % 2;   // 0 sau 1 la fiecare 1000ms
  digitalWrite(11, stare);
}

// ledul de pe pinul 9 clipeste la fiecare 3 secunde
void blinkLed9() {
  int state = (millis() / 3000) % 2;   // 0 sau 1 la fiecare 3000
  digitalWrite(12, stare);
}

void loop() {
  blinkLed8();
  blinkLed9();
}s