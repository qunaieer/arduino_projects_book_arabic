#define Piezo 5
#define sw_1 10
#define sw_2 9
#define sw_3 8
#define sw_4 7
#define sw_5 6
void setup()
{
  pinMode(Piezo, OUTPUT);
  pinMode(sw_1, INPUT);
  pinMode(sw_2, INPUT);
  pinMode(sw_3, INPUT);
  pinMode(sw_4, INPUT);
  pinMode(sw_5, INPUT);
}
void loop()
{
  while (digitalRead(sw_1) == HIGH)
  {
    tone(Piezo, 100);
  }
  while (digitalRead(sw_2) == HIGH)
  {
    tone(Piezo, 300);
  }
  while (digitalRead(sw_3) == HIGH)
  {
    tone(Piezo, 500);
  }
  while (digitalRead(sw_4) == HIGH)
  {
    tone(Piezo, 700);
  }
  while (digitalRead(sw_5) == HIGH)
  {
    tone(Piezo, 900);
  }
  noTone(Piezo);
}

