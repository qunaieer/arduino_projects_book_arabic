#define pulse_signal 4
float the_time = 0, the_distance = 0;
#include <LiquidCrystal.h>
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
void setup()
{
  lcd.begin(16, 2);
  lcd.print("put somthing");
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
  delay(1000);
  lcd.clear();
  lcd.print("Distance =");
  lcd.setCursor(0, 1);
  lcd.print(the_distance);
  lcd.setCursor(7, 1);
  lcd.print("cm");
}
float microsecondsToCentimeters(float micro_seconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  return micro_seconds / 29 / 2;
}
