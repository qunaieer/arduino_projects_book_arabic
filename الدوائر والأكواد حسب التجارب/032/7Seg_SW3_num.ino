int a = 6;        //for light part A
int b = 7;        // B
int c = 8;        // C
int d = 9;        // D
int e = 10;       // E
int f = 11;       // F
int g = 12;       // G
int sw_1 = 3;
int sw_2 = 4;
int x;
void segmentoff()
{
  digitalWrite(a, HIGH);  digitalWrite(b, HIGH);  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);  digitalWrite(e, HIGH);  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
void setup()
{
  pinMode(a, OUTPUT);    pinMode(b, OUTPUT);    pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);    pinMode(e, OUTPUT);    pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

void segment_nom(int nomb)
{
  if ( nomb != 1 && nomb != 4)
    digitalWrite(a, LOW);
  if (nomb != 5 && nomb != 6)
    digitalWrite(b, LOW);
  if (nomb != 2)
    digitalWrite(c, LOW);
  if (nomb != 1 && nomb != 4 && nomb != 7)
    digitalWrite(d, LOW);
  if (nomb != 1 && nomb != 3 && nomb != 4 && nomb != 5 && nomb != 7 && nomb != 9 )
    digitalWrite(e, LOW);
  if (nomb != 1 && nomb != 2 && nomb != 3 && nomb != 7)
    digitalWrite(f, LOW);
  if (nomb != 0 && nomb != 1 && nomb != 7)
    digitalWrite(g, LOW);
}
void loop()
{
  segmentoff();
  if (digitalRead (sw_1) == HIGH)
  {
    x = 1;
    delay(100);
  }
  else if (digitalRead (sw_2) == HIGH)
  {
    x = 2;
    delay(100);
  }
  if (x == 1) segment_nom(1);
  else if (x == 2) segment_nom(2);
}
