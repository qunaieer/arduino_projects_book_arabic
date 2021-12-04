int a = 6;        //for light part A
int b = 7;        // B
int c = 8;        // C
int d = 9;        // D
int e = 10;       // E
int f = 11;       // F
int g = 12;       // G

void setup()
{
  pinMode(a, OUTPUT);    pinMode(b, OUTPUT);    pinMode(c, OUTPUT);  
  pinMode(d, OUTPUT);    pinMode(e, OUTPUT);    pinMode(f, OUTPUT);  
  pinMode(g, OUTPUT);  
  segmentoff();
}

void segment_nom(int nom)
{
  if ( nom != 1 && nom != 4)
    digitalWrite(a, LOW);

  if (nom != 5 && nom != 6)
    digitalWrite(b, LOW);

  if (nom != 2)
    digitalWrite(c, LOW);

  if (nom != 1 && nom != 4 && nom != 7)
    digitalWrite(d, LOW);

  if (nom != 1 && nom != 3 && nom != 4 && nom != 5 && nom != 7 && nom != 9 )
    digitalWrite(e, LOW);

  if (nom != 1 && nom != 2 && nom != 3 && nom != 7)
    digitalWrite(f, LOW);

  if (nom != 0 && nom != 1 && nom != 7)
    digitalWrite(g, LOW);
}

void segmentoff()
{
  digitalWrite(a, HIGH);  digitalWrite(b, HIGH);  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);  digitalWrite(e, HIGH);  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void loop()
{
  for (int i = 9; i >= 0; i--)
  {
    segment_nom(i);
    delay(1000);
    segmentoff();
  }
}

