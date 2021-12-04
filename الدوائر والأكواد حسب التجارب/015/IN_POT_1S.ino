int Pot_Pin = A1;
float Pot_Val;
float volts;
void setup()
{
  Serial.begin(9600);
  Serial.flush();
  Serial.println("Rotate the potentiometer to print the value");
}
void loop()
{
  Pot_Val = analogRead(Pot_Pin);
  Serial.print("Value = ");
  Serial.print(Pot_Val);
  volts = Pot_Val * 5.0 / 1024;
  Serial.print(" (");
  Serial.print(volts);
  Serial.println(" volts)");
  delay(1000);
}
