int OUT_R = 9;
int OUT_B = 10;
int OUT_G = 11;
int Pot_Pin_R = A0;
int Pot_Pin_B = A1;
int Pot_Pin_G = A2;
int Pot_Val_R, Pot_Val_B, Pot_Val_G;
int x_R , x_B , x_G;
void setup()
{
  pinMode(OUT_R, OUTPUT);
  pinMode(OUT_G, OUTPUT);
  pinMode(OUT_B, OUTPUT);
}
void loop()
{
  Pot_Val_R = analogRead(Pot_Pin_R);
  Pot_Val_B = analogRead(Pot_Pin_B);
  Pot_Val_G = analogRead(Pot_Pin_G);

  x_R = map (Pot_Val_R , 0 , 1023 , 0 , 255);
  x_B = map (Pot_Val_B , 0 , 1023 , 0 , 255);
  x_G = map (Pot_Val_G , 0 , 1023 , 0 , 255);

  analogWrite(OUT_R, x_R);
  analogWrite(OUT_G, x_G);
  analogWrite(OUT_B, x_B);
}
