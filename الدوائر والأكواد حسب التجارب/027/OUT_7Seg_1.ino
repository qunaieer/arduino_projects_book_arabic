int a = 6;       //for light part A
int b = 7;       // B
int c = 8;       // C
int d = 9;       // D
int e = 10;      // E
int f = 11;      // F
int g = 12;      // G

void setup()
{
  //make all part as output
  pinMode(a, OUTPUT);    pinMode(b, OUTPUT);  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);    pinMode(e, OUTPUT);  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

void segment_nom(int nom)
{
  if (nom == 0)
  {
    digitalWrite(a, LOW);    digitalWrite(b, LOW);    digitalWrite(c, LOW);
    digitalWrite(d, LOW);    digitalWrite(e, LOW);    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
  }
  if (nom == 1)
  {
    digitalWrite(a, HIGH);    digitalWrite(b, LOW);     digitalWrite(c, LOW);
    digitalWrite(d, HIGH);    digitalWrite(e, HIGH);    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (nom == 2)
  {
    digitalWrite(a, LOW);    digitalWrite(b, LOW);    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);    digitalWrite(e, LOW);    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
  }
  if (nom == 3)
  {
    digitalWrite(a, LOW);    digitalWrite(b, LOW);     digitalWrite(c, LOW);
    digitalWrite(d, LOW);    digitalWrite(e, HIGH);    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
  }
  if (nom == 4)
  {
    digitalWrite(a, HIGH);    digitalWrite(b, LOW);     digitalWrite(c, LOW);
    digitalWrite(d, HIGH);    digitalWrite(e, HIGH);    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (nom == 5)
  {
    digitalWrite(a, LOW);    digitalWrite(b, HIGH);    digitalWrite(c, LOW);
    digitalWrite(d, LOW);    digitalWrite(e, HIGH);    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (nom == 6)
  {
    digitalWrite(a, LOW);    digitalWrite(b, HIGH);    digitalWrite(c, LOW);
    digitalWrite(d, LOW);    digitalWrite(e, LOW);     digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (nom == 7)
  {
    digitalWrite(a, LOW);     digitalWrite(b, LOW);     digitalWrite(c, LOW);
    digitalWrite(d, HIGH);    digitalWrite(e, HIGH);    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  if (nom == 8)
  {
    digitalWrite(a, LOW);    digitalWrite(b, LOW);    digitalWrite(c, LOW);
    digitalWrite(d, LOW);    digitalWrite(e, LOW);    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  if (nom == 9)
  {
    digitalWrite(a, LOW);    digitalWrite(b, LOW);     digitalWrite(c, LOW);
    digitalWrite(d, LOW);    digitalWrite(e, HIGH);    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
}

void segmentoff()
{
  digitalWrite(a, HIGH);   digitalWrite(b, HIGH);   digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);   digitalWrite(e, HIGH);   digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void loop()
{
  for (int i = 0; i < 10; i++)
  {
    segment_nom(i);
    delay(1000);
    segmentoff();
  }
}
