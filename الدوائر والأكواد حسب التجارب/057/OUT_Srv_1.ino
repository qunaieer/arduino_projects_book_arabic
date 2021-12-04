#include <Servo.h>
Servo myservo;          //servo object for control
int pos = 0;            //variable to store the servo position
void setup()
{
  myservo.attach(11);   //connect the servo motor to pin 11 (~) in Arduino
}
void loop()
{
  //start rotation from 0 degrees to 180 degrees, 1 degree per step
  for (pos = 0; pos <= 180; pos += 1)
  {
    myservo.write(pos); // tell servo to go to position in variable 'pos'
    delay(15);          // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) //for going back (revers rotation)
  {
    myservo.write(pos);
    delay(15);
  }
}
