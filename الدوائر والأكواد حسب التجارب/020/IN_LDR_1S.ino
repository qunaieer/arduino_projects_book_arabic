int LDR_val;
void setup()
{
  Serial.begin(9600);
  Serial.flush();
  Serial.println("slide the switch to check it");
}
void loop()
{
  LDR_val = analogRead(A1);
  Serial.print("Value = ");
  Serial.print(LDR_val);
  if (LDR_val <= 100) Serial.println(" , Dark");
  else if (LDR_val >= 900) Serial.println(" , Max brightness");
  else Serial.println(" , Normal light");
  delay(1000);
}
