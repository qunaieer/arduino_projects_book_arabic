int led = 9;                                  //Led connected to PWM pin 9
int brightness = 0;                           //led brightness variable
int fadeAmount = 5;                           //how many points to fade the LED by
void setup()
{
  pinMode(led, OUTPUT);                       //pin 9 is an output
}
void loop()
{
  //put the value of the brightness variable to pin 9
  analogWrite(led, brightness);               //set the brightness of led
  brightness = brightness + fadeAmount;       //make the brightness value high
  if (brightness <= 0 || brightness >= 255)   // reverse the direction of the fading at the ends of the fade:
  {
    fadeAmount = -fadeAmount;
  }
  delay(30);                                   //wait 30 milliseconds to see the dimming effect
}
