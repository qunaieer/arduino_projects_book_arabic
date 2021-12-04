int led = 7;
int butt_1 = 4;   //ON
int butt_2 = 5;   //OFF
void setup()
{
  pinMode(led, OUTPUT);
  pinMode(butt_1, INPUT);
  pinMode(butt_2, INPUT);
}
void loop()
{
  if (digitalRead (butt_1) == HIGH)
  {
    digitalWrite(led, HIGH);
    delay (200);
  }
  else if (digitalRead (butt_2) == HIGH)
  {
    digitalWrite(led, LOW);
    delay (200);
  }
}
