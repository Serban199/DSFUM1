unsigned long brightness = 0; //0-255
unsigned long fade = 8; //pasul de modif a luminozitatii
unsigned long lastFadeTime = 0;
unsigned long fadeInterval = 20; //cat de des schimbam luminozitatea
unsigned long pwmPeriod = 5; //durata unui ciclu PWM

void setup() {
  pinMode(13,OUTPUT);

}

void loop() {
  unsigned long t = millis();
  

  if(t-lastFadeTime >= fadeInterval)
  {
    lastFadeTime = t;
    brightness += fade;
    if(brightness <= 0 || brightness >= 255)
      fade = -fade; //inversam directia
  }

  unsigned long pwmTime = t % pwmPeriod;

  unsigned long onTime = (brightness * pwmPeriod)/255;
  
  if(pwmTime < onTime)
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);
}