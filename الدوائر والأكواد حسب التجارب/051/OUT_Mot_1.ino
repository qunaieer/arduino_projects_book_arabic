int mot = 12;               //connect the motor to pin 12 in Arduino
void setup()
{
  pinMode(mot, OUTPUT);     //pin 12 for motor is an output
}
void loop()
{
  digitalWrite(mot, HIGH);  //send signal to run the motor
  delay(2000);              //keep it running for 2 seconds
  digitalWrite(mot, LOW);   //stop the motor
  delay(2000);
}
