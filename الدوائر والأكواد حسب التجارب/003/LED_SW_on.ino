int led = 7;
int butt = 4;
void setup()
{
  pinMode(led, OUTPUT);
  pinMode(butt, INPUT);
}
void loop()
{
  if (digitalRead (butt) == HIGH)
  {
    digitalWrite(led, HIGH);
    delay (200);
  }
  else
    digitalWrite(led, LOW);
}
