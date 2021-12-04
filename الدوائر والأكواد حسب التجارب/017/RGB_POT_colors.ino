int OUT_R = 9;
int OUT_B = 10;
int OUT_G = 11;
int Pot_Pin = A1;
float Pot_Val;

void setup()
{
  pinMode(OUT_R, OUTPUT);
  pinMode(OUT_G, OUTPUT);
  pinMode(OUT_B, OUTPUT);
}
void loop()
{
  Pot_Val = analogRead(Pot_Pin);
  if (0 <= Pot_Val && Pot_Val < 340)
  {
    analogWrite(OUT_R, 255);
    analogWrite(OUT_G, 0);
    analogWrite(OUT_B, 0);
  }
  if (340 <= Pot_Val && Pot_Val < 680)
  {
    analogWrite(OUT_R, 0);
    analogWrite(OUT_G, 255);
    analogWrite(OUT_B, 0);
  }
  if (680 <= Pot_Val && Pot_Val <= 1023)
  {
    analogWrite(OUT_R, 0);
    analogWrite(OUT_G, 0);
    analogWrite(OUT_B, 255);
  }
}
