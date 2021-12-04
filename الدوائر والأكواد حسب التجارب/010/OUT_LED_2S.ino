int led = 13;                       // Led connected to pin 13
int x;                            //variable to save the status
void setup()
{
  pinMode(led, OUTPUT);             // pin 13 is output
  Serial.begin(9600);               // start serial with baud rate = 9600
  Serial.flush();                   //to wait to complete the outgoing serial data
  Serial.println("write fast or slow");
}
void loop()
{
  String input = "";                //variable to save the input message
  while (Serial.available() > 0)    //that means there's data arrived from the serial
  {
    input += (char) Serial.read();  //to read one char at a time and save it into (input) variable
    delay(5);                       //delay 5ms before next char
  }
  if (input == "fast")              // if you write/send (fast) by serial
  {
    x = 1;
  }
  else if (input == "slow")         // if you write/send (slow) by serial
  {
    x = 0;
  }
  if ( x == 1)
  {
    digitalWrite(led, HIGH);        //make the led on
    delay(100);                     //wait small time to be fast
    digitalWrite(led, LOW);         //make the led off
    delay(100);
  }
  else if (x == 0)
  {
    digitalWrite(led, HIGH);        //make the led on
    delay(800);                     //wait bigger time to be slow
    digitalWrite(led, LOW);         //make the led off
    delay(800);
  }
}
