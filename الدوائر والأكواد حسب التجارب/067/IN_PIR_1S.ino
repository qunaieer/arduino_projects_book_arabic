int PIR_sensor = 9;
unsigned long time;
void setup()
{
  pinMode(PIR_sensor, INPUT);
  Serial.begin(9600);
  Serial.println("Move in front of PIR sensor");
}
void loop()
{
  time = millis();
  if (digitalRead(PIR_sensor))
  {
    Serial.print("Motion detected at: ");
    Serial.println(time);
  }
  delay(1000);
}
