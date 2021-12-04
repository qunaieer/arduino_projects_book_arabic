#include <LiquidCrystal.h>
LiquidCrystal lcd(6, 7, 8, 9, 10, 11);
#define PIR_sensor 12
#define m0 3
#define m1 4
void setup()
{
  pinMode(m0, OUTPUT);
  pinMode(m1, OUTPUT);
  pinMode(PIR_sensor, INPUT);
  lcd.begin(16, 2);
  lcd.print(" Automatic Door");
  lcd.setCursor(0, 1);
  lcd.print(" Control System");
  delay(2000);
  lcd.clear();
}
void loop()
{
  if (digitalRead(PIR_sensor) == HIGH)
  {
    lcd.clear();
    lcd.print(" Move Detected");
    lcd.setCursor(0, 1);
    lcd.print("Door is Opening");
    digitalWrite(m0, HIGH);
    digitalWrite(m1, LOW);
    delay(1000);
    digitalWrite(m0, LOW);
    digitalWrite(m1, LOW);
    delay(2000);
    while (digitalRead(PIR_sensor) == HIGH)
    {
    }
    if (digitalRead(PIR_sensor) == LOW)
    {
      lcd.clear();
      lcd.print("Door is Closing");
      digitalWrite(m0, LOW);
      digitalWrite(m1, HIGH);
      delay(1000);
      digitalWrite(m0, LOW);
      digitalWrite(m1, LOW);
      lcd.clear();
    }
  }
  if (digitalRead(PIR_sensor) == LOW)
  {
    lcd.print("  No Movement   ");
    lcd.setCursor(0, 1);
    lcd.print("  Door Closed   ");
    digitalWrite(m0, LOW);
    digitalWrite(m1, LOW);
  }
}
