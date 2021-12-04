#define Piezo 5
int pot_pin = A5;
int val = 0;
void setup()
{
  pinMode(Piezo, OUTPUT);
}
void loop()
{
  val = analogRead(pot_pin);
  val = map (val , 0 , 1023 , 0 , 1500) ;
  if (val == 0) noTone(Piezo);
  else tone(Piezo, val);
}
