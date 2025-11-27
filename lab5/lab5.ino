// definitii pini
#define PIN_TIP     8
#define PIN_R1      9
#define PIN_R2      10
#define PIN_SLEEVE  11

// note muzicale
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58

// pauza intre note
const int durata_nota = 250;

// array cu notele
const int melodie[] = {
  NOTE_B0, NOTE_C1, NOTE_CS1, NOTE_D1, NOTE_DS1, NOTE_E1,
  NOTE_F1, NOTE_FS1, NOTE_G1, NOTE_GS1, NOTE_A1, NOTE_AS1
};

void setup() {
  // initializeaza pinii 8 11 ca output
  for (int pin = 8; pin <= 11; pin++) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
}

void loop() {

  // urcare in frecvente
  for (int i = 0; i < 12; i++) {
    tone(PIN_TIP, melodie[i], durata_nota);
    delay(300);
    noTone(PIN_TIP);
  }

  // coborare in frecvente
  for (int i = 11; i >= 0; i--) {
    tone(PIN_TIP, melodie[i], durata_nota);
    delay(300);
    noTone(PIN_TIP);
  }

  delay(1000);
}
