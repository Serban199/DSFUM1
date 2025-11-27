
void setup() {
  // setez pinii 8-13 ca output
  for(int i = 8; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }
}

int curent = 8;

void loop() {

  // aprind ledul curent
  digitalWrite(curent, HIGH);
  delay(250);   // putin mai scurt ca sa se deosebeasca

  // sting ledul curent
  digitalWrite(curent, LOW);
  delay(250);

  // trec la urmatorul pin
  curent++;

  // daca am depasit pinul 13, reiau de la 8
  if (curent > 13) {
    curent = 8;
  }
}