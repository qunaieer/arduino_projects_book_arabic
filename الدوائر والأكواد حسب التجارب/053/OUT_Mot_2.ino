//motor pin 1 is named as m1 and connected to pin 2 in Arduino
#define m1 2
//motor pin 2 is named as m1 and connected to pin 3 in Arduino
#define m2 3
void setup()
{
  pinMode(m1, OUTPUT);   //both motor pins are output pins
  pinMode(m2, OUTPUT);
}
void loop()
{
  //pin_1 HIGH, pin_2 LOW >>> rotat diresction 1
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  delay(2000);
  //both pins LOW >>> stop rotation
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  delay(2000);
  //pin_1 LOW, pin_2 HIGH >>> rotat diresction 2
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
  delay(2000);
  //both pins LOW >>> stop rotation
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  delay(2000);
}
