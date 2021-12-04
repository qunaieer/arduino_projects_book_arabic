#include <Servo.h>
Servo myservo;
int input;
void setup()
{
  myservo.attach(11);
  Serial.begin(9600);
}
void loop()
{
  if (Serial.available() > 0)
  {
    input = Serial.parseInt();
    myservo.write(input);
    delay (1000);
  }
}
