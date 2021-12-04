int resett = 0;
int user = 0;
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, INPUT);
  pinMode(3, INPUT);
  pinMode(5, INPUT);
  pinMode(7, INPUT);
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
}
void loop()
{
  if (digitalRead (3) && resett == 0 )
  {
    user = 1;
  }
  else if (digitalRead (5) && resett == 0  )
  {
    user = 2;
  }
  else if (digitalRead (7) && resett == 0  )
  {
    user = 3;
  }
  if (user == 1)
  {
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    resett = 1;
  }
  if (user == 2)
  {
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(6, HIGH);
    resett = 1;
  }
  if (user == 3)
  {
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(6, LOW);
    resett = 1;
  }
  if (digitalRead (8) && resett == 1 ) //reset
  {
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    user = 0;
    resett = 0;
  }
}
