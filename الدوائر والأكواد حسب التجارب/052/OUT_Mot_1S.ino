int mot = 12;               //connect the motor to pin 12 in Arduino
void setup()
{
  pinMode(mot, OUTPUT);     //pin 12 for motor is an output
  digitalWrite(mot, LOW);   //the intial state of the motor is off
  Serial.begin(9600);       //start serial with baud rate = 9600
  Serial.flush();           //to wait to complete the outgoing serial data
  Serial.write("to operate the motor, write here 'on' or 'off'  ");
}
void loop()
{
  String input = "";                //variable to save the input message
  while (Serial.available() > 0)    //that means there's data arrived from the serial
  {
    input += (char) Serial.read();  //to read one char at a time and save it into (input) variable
    delay(5);                       //delay 5ms before next char
  }
  if (input == "on")                //if you write/send (on) by serial
  {
    digitalWrite(mot, HIGH);        //send signal to run the motor
    delay(1000);                    //keep it running for 1 seconds
  }
  else if (input == "off")          //if you write/send (off) by serial
  {
    digitalWrite(mot, LOW);         //stop the motor
    delay(1000);
  }
}
