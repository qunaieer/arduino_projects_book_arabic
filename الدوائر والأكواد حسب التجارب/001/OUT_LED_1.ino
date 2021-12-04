int led = 13;                     //Led is an integer variable = 13 (pin number)
void setup()
{
  pinMode(led, OUTPUT);           // pin 13 is output
}
void loop()                       //code will run continuously
{
  digitalWrite(led, HIGH);        //make the led on
  delay (1000);                   //wait 1 second
  digitalWrite(led, LOW);         //make the led off
  delay (1000);
}
