#include <LiquidCrystal.h>
#define sw_1  2
#define sw_2  3
#define sw_3  4
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
void setup()
{
  lcd.begin(16, 2);
  pinMode(sw_1, INPUT);
  pinMode(sw_2, INPUT);
  pinMode(sw_3, INPUT);
}
void loop()
{
  if (digitalRead (sw_1) == HIGH)
  {
    delay(100);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("User ** 1 ** win");
    delay(2000);
    lcd.clear();
  }
  else if (digitalRead (sw_2) == HIGH)
  {
    delay(100);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("User ** 2 ** win");
    delay(2000);
    lcd.clear();
  }
  else if (digitalRead (sw_3) == HIGH)
  {
    delay(100);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("User ** 3 ** win");
    delay(2000);
    lcd.clear();
  }
  else
  {
    lcd.setCursor(1, 0);
    lcd.print("press a switch");
  }
}

