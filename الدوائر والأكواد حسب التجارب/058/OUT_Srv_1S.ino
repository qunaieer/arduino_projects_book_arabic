#include <Servo.h>
Servo myservo;          //servo object for control
int pos = 0;            //variable to store the servo position
int pos_current = 0;
void setup()
{
  myservo.attach(11);   //connect the servo motor to pin 11 (~) in Arduino
  Serial.begin(9600);       //start serial with baud rate = 9600
  Serial.flush();           //to wait to complete the outgoing serial data
}
void loop()
{
  String input = "";                //variable to save the input message
  while (Serial.available() > 0)    //that means there's data arrived from the serial
  {
    input += (char) Serial.read();  //to read one char at a time and save it into (input) variable
    delay(5);                       //delay 5ms before next char
  }
  if (input == "right")
  {
    //start rotation from 0 degrees to 180 degrees, 1 degree per step
    for (pos = pos_current; pos <= 180; pos += 1)
    {
      myservo.write(pos); // tell servo to go to position in variable 'pos'
      delay(15);          // waits 15ms for the servo to reach the position
    }
    pos_current = pos;
  }
  else if (input == "left")
  {
    for (pos = pos_current; pos >= 0; pos -= 1) //for going back (revers rotation)
    {
      myservo.write(pos);
      delay(15);
    }
    pos_current = pos;
  }
  else if (input == "center")
  {
    myservo.write(90);
    delay(15);
    pos_current = 90;
  }
}
