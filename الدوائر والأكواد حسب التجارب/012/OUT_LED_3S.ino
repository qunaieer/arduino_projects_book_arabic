int led = 9;                         //Led connected to PWM pin 9
int input;
void setup()
{
  pinMode(led, OUTPUT);             //pin 9 is an output
  Serial.begin(9600);               //start serial with baud rate = 9600
  Serial.flush();                   //to wait to complete the outgoing serial data
  Serial.write("enter brightness between 0 , 255");
}
void loop()
{
  while (Serial.available() > 0)   //that means there's data arrived from the serial
  {
    input = Serial.parseInt();
  }
  analogWrite(led, input);         //set the brightness of led
  delay(30);                       //wait 30 milliseconds to see the dimming effect
}
