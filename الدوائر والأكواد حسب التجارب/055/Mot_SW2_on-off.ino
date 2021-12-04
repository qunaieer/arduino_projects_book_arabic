int mot = 2;
int sw_on = 9 ;
int sw_off = 10 ;
void setup()
{
  pinMode(mot, OUTPUT);
  pinMode(sw_on, INPUT);
  pinMode(sw_on, INPUT);
}
void loop()
{
  if (digitalRead(sw_on) == HIGH)
  {
    digitalWrite(mot, HIGH);
    delay(100);
  }
  else if (digitalRead(sw_off) == HIGH)
  {
    digitalWrite(mot, LOW);
    delay(100);
  }
}

