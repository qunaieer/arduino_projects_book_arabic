#include <LiquidCrystal.h>
#define sw 3
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
void setup()
{
  lcd.begin(16, 2);
  pinMode(sw, INPUT);
}
void loop()
{
  if (digitalRead (sw) == HIGH)
  {
    delay(100);
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Hello");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("This is");
    delay(1000);
    lcd.setCursor(0, 2);
    lcd.print("Arduino test");
    delay(3000);
    lcd.clear();
  }
  else
  {
    lcd.setCursor(0, 0);
    lcd.print("press the switch");
  }
}

