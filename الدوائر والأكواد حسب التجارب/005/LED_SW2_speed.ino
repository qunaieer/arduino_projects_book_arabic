int led = 7;
int butt_1 = 4;   //Fast
int butt_2 = 5;   //Slow
int x;
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
    x = 1;
    delay (200);
  }
  else if (digitalRead (butt_2) == HIGH)
  {
    x = 2;
    delay (200);
  }
  if ( x == 1)
  {
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(100);
  }
  else if (x == 2)
  {
    digitalWrite(led, HIGH);
    delay(600);
    digitalWrite(led, LOW);
    delay(600);
  }
}
