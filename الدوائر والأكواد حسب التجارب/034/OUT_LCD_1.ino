#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
void setup()
{
  lcd.begin(16, 2);
}
void loop()
{
  lcd.setCursor(5, 0);
  lcd.print("Hello");
  delay(1000);
  lcd.clear();
  lcd.print("Welcome to");
  lcd.setCursor(0, 1);
  lcd.print("Arduino Project");
  delay(1500);
  lcd.clear();  
}

