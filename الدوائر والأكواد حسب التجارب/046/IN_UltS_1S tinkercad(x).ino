#define pulse_signal 4
float the_time = 0, the_distance = 0;
void setup()
{
  Serial.begin(9600);
  Serial.println("Put a device in front of sensor to measure the distance");
}
void loop()
{
  pinMode(pulse_signal, OUTPUT);
  digitalWrite(pulse_signal, LOW);
  delayMicroseconds(2);
  digitalWrite(pulse_signal, HIGH);
  delayMicroseconds(10);
  digitalWrite(pulse_signal, LOW);
  delayMicroseconds(2);
  pinMode(pulse_signal, INPUT);
  the_time = pulseIn(pulse_signal, HIGH);
  the_distance = microsecondsToCentimeters(the_time);
  Serial.print("Distance = ");
  Serial.print(the_distance);
  Serial.println(" cm");
  delay(1000);
}
float microsecondsToCentimeters(float micro_seconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  return micro_seconds / 29 / 2;
}
