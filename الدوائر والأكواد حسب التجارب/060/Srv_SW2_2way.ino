#include <Servo.h>
Servo myservo;
int sw_left = 9 ;
int sw_right = 10 ;
int pos = 0;
int pos_current = 0;
void setup()
{
  myservo.attach(11);
  pinMode(sw_left, INPUT);
  pinMode(sw_right, INPUT);
}
void loop()
{
  if (digitalRead(sw_left) == HIGH)
  {
    for (pos = pos_current; pos <= 180; pos += 1)
    {
      myservo.write(pos);
      delay(15);
    }
    pos_current = pos;
    delay(100);
  }
  else if (digitalRead(sw_right) == HIGH)
  {
    for (pos = pos_current; pos >= 0; pos -= 1)
    {
      myservo.write(pos);
      delay(15);
    }
    pos_current = pos;
    delay(100);
  }
}
