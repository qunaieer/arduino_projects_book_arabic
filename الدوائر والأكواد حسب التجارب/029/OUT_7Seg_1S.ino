int a = 6;        //for light part A
int b = 7;        // B
int c = 8;        // C
int d = 9;        // D
int e = 10;       // E
int f = 11;       // F
int g = 12;       // G
int input;

void setup()
{
  pinMode(a, OUTPUT);    pinMode(b, OUTPUT);    pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);    pinMode(e, OUTPUT);    pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  Serial.begin(9600);               //start serial with baud rate = 9600
  Serial.flush();                   //to wait to complete the outgoing serial data
  Serial.write("enter number 0:9 to display");
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

void segmentoff()
{
  digitalWrite(a, HIGH);  digitalWrite(b, HIGH);  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);  digitalWrite(e, HIGH);  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void loop()
{
  segmentoff();
  while (Serial.available() > 0)   //that means there's data arrived from the serial
  {
    input = Serial.parseInt();
  }
  segment_nom(input);             // go to print the number
  delay(100);
}
