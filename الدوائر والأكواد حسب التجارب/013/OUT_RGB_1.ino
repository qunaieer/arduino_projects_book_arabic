int OUT_R = 9;              //red pin connected to pin 9
int OUT_B = 10;             //blue pin connected to pin 10
int OUT_G = 11;             //green pin connected to pin 11
void setup()
{
  pinMode(OUT_R, OUTPUT);   //make the three pins as output
  pinMode(OUT_G, OUTPUT);
  pinMode(OUT_B, OUTPUT);
}
void loop()
{
  analogWrite(OUT_R, 255);  //red pin high, others low
  analogWrite(OUT_G, 0);
  analogWrite(OUT_B, 0);
  delay(500);               //delay 0.5 second to see the light color
  analogWrite(OUT_R, 0);
  analogWrite(OUT_G, 255);  //green pin high, others low
  analogWrite(OUT_B, 0);
  delay(500);
  analogWrite(OUT_R, 0);
  analogWrite(OUT_G, 0);
  analogWrite(OUT_B, 255);  //blue pin high, others low
  delay(500);

}
