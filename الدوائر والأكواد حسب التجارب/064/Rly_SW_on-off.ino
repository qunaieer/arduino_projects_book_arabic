int Relay_1 = 9; int Relay_2 = 8;
int Relay_3 = 7; int Relay_4 = 6;
int Sw_1    = 5; int Sw_2    = 4;
int Sw_3    = 3; int Sw_4    = 2;
boolean x1 = LOW, x2 = LOW, x3 = LOW, x4 = LOW;
void setup()
{
  pinMode(Relay_1, OUTPUT);
  pinMode(Relay_2, OUTPUT);
  pinMode(Relay_3, OUTPUT);
  pinMode(Relay_4, OUTPUT);
  pinMode(Sw_1,    INPUT);
  pinMode(Sw_2,    INPUT);
  pinMode(Sw_3,    INPUT);
  pinMode(Sw_4,    INPUT);
}
void loop()
{
  if (digitalRead (Sw_1) == HIGH)
  {
    x1 = ! x1 ;
    digitalWrite(Relay_1, x1);
    delay(100);
  }
  else if (digitalRead (Sw_2) == HIGH)
  {
    x2 = ! x2 ;
    digitalWrite(Relay_2, x2);
    delay(100);
  }
  else if (digitalRead (Sw_3) == HIGH)
  {
    x3 = ! x3 ;
    digitalWrite(Relay_3, x3);
    delay(100);
  }
  else if (digitalRead (Sw_4) == HIGH)
  {
    x4 = ! x4 ;
    digitalWrite(Relay_4, x4);
    delay(100);
  }
}

