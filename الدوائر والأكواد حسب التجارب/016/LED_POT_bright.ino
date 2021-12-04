int Pot_Pin = A1;
int led = 9;
int Pot_Val, bright_val;
void setup()
{
  pinMode(led, OUTPUT);
}

void loop()
{
  Pot_Val = analogRead(Pot_Pin);
  bright_val = map(Pot_Val, 0, 1023, 0, 255);
  analogWrite(led, bright_val);
}
