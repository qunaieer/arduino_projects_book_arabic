int LDR_Pin = A1;
int led = 9;
int LDR_val;
int x;
void setup()
{
  pinMode(led, OUTPUT);
}
void loop()
{
  LDR_val = analogRead(LDR_Pin);
  if (0 <= LDR_val && LDR_val < 500)  //Dark
  {
    x = 1;       //Fast Flash
  }
  else if (500 <= LDR_val && LDR_val <= 1023)   //Light
  {
    x = 2;         //Slow Flash
  }
  if (x == 1)
  {
    digitalWrite (led , HIGH);
    delay (100);
    digitalWrite (led , LOW);
    delay (100);
  }
  else if (x == 2)
  {
    digitalWrite (led , HIGH);
    delay (800);
    digitalWrite (led , LOW);
    delay (800);
  }
}
