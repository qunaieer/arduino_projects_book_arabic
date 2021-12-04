int led = 13;                       //Led connected to pin 13
void setup()
{
  pinMode(led, OUTPUT);             //pin 13 is output
  Serial.begin(9600);               //start serial with baud rate = 9600
  Serial.flush();                   //to wait to complete the outgoing serial data
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
    digitalWrite(led, HIGH);        //make the led on
  }
  else if (input == "off")          //if you write/send (off) by serial
  {
    digitalWrite(led, LOW);         //make the led off
  }
}
