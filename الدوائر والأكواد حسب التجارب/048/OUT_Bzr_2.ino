#define Piezo 11           //connect the piezo buzzer to pin 11 Arduino
void setup()
{
  pinMode(Piezo, OUTPUT);  //piezo pin is an output port
}
void loop()
{
  for (int x = 50; x < 1500; x += 100)
  {
    tone(Piezo, x);         //generate a tone with 10 Hz frequency
    delay(300);
    noTone(Piezo);
    delay(300);
  }
  for (int x = 1500; x > 50; x -= 100)
  {
    tone(Piezo, x);         //generate a tone with 10 Hz frequency
    delay(100);
    noTone(Piezo);
    delay(100);
  }
}

