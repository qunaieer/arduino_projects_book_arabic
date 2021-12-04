#define Piezo 11           //connect the piezo buzzer to pin 11 Arduino
void setup()
{
  pinMode(Piezo, OUTPUT);  //piezo pin is an output port
}
void loop()
{
  tone(Piezo, 10);         //generate a tone with 10 Hz frequency
  delay(500);
}
