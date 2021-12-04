int mot = 2;
int sw = 10 ;
void setup()
{
  pinMode(mot, OUTPUT);
  pinMode(sw, INPUT);
}
void loop()
{
  if (digitalRead(sw) == HIGH)
  {
    digitalWrite(mot, HIGH);
    delay(5000);
    digitalWrite(mot, LOW);
  }

}
