int timer = 200;
void setup()
{
  for (int Led_Pin = 6; Led_Pin < 14; Led_Pin++)
  {
    pinMode(Led_Pin, OUTPUT);
  }
}
void loop()
{
  for (int Led_Pin = 6; Led_Pin < 14; Led_Pin++)
  {
    digitalWrite(Led_Pin, HIGH);
    delay(timer);
    digitalWrite(Led_Pin, LOW);
  }
  for (int Led_Pin = 13; Led_Pin >= 6; Led_Pin--)
  {
    digitalWrite(Led_Pin, HIGH);
    delay(timer);
    digitalWrite(Led_Pin, LOW);
  }
}
