
void setup() {
    // Setez pinii 8-13 ca output
    for (int i = 8; i <= 13; i++) {
        pinMode(i, OUTPUT);
    }
}

void loop() {
    unsigned long t = millis();
    int pozitie     = (t / 300) % 11;  // Numaram 11 pozitii
    int pinAprins;
    if (pozitie < 6) {
        pinAprins = 8 + pozitie;       // De la 8 la 13
    } else {
        pinAprins = 13 - (pozitie - 5); // De la 13 la 8
    }

    // Aprind ledul activ
    digitalWrite(pinAprins, HIGH);

    // Sting restul ledurilor
    for (int p = 8; p <= 13; p++) {
        if (p != pinAprins) {
            digitalWrite(p, LOW);
        }
    }
}
