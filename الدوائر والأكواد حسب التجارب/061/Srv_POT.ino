#include <Servo.h>
Servo my_servo;
int pot_pin = A5;
int val = 0;
void setup()
{
  my_servo.attach(11);
}
void loop()
{
  val = analogRead(pot_pin);
  val = map (val , 0 , 1023 , 0 , 180) ;
  my_servo.write(val);
  delay(15);
}
