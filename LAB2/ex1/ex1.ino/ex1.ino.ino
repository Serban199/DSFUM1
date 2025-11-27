//13 -fade la 1s
unsigned long brightness13 = 0; //0-255
unsigned long fade13 = 5; //pasul de modif a luminozitatii
unsigned long lastFadeTime13 = 0;
unsigned long fadeInterval13 = 20; //cat de des schimbam luminozitatea


//12 -fade la 2.5s
unsigned long brightness12 = 0; //0-255
unsigned long fade12 = 3; //pasul de modif a luminozitatii
unsigned long lastFadeTime12 = 0;
unsigned long fadeInterval12 = 30; //cat de des schimbam luminozitatea

unsigned long pwmPeriod13 = 5; //durata unui ciclu PWM
unsigned long pwmPeriod12 = 5; //durata unui ciclu PWM

void setup() {
  pinMode(13,OUTPUT); 
  pinMode(12,OUTPUT);
}

void loop() {
  unsigned long t = millis();
  
  //13
  if(t-lastFadeTime13 >= fadeInterval13)
  {
    lastFadeTime13 = t;
    brightness13 += fade13;
    if(brightness13 <= 0 || brightness13 >= 255)
      fade13 = -fade13; //inversam directia
  }

  unsigned long pwmTime13 = t % pwmPeriod13;

  unsigned long onTime13 = (brightness13 * pwmPeriod13)/255;
  
  if(pwmTime13 < onTime13)
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);


  //12
  if(t-lastFadeTime12 >= fadeInterval12)
  {
    lastFadeTime12 = t;
    brightness12 += fade12;
    if(brightness12 <= 0 || brightness12 >= 255)
      fade12 = -fade12; //inversam directia
  }

  unsigned long pwmTime12 = t % pwmPeriod12;

  unsigned long onTime12 = (brightness12 * pwmPeriod12)/255;
  
  if(pwmTime12 < onTime12)
    digitalWrite(12, HIGH);
  else
    digitalWrite(12, LOW);
}
