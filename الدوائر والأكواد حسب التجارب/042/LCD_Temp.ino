#include <LiquidCrystal.h>
#define Temp_TMP36 A2
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("temp = ");
  lcd.setCursor(14, 0);
  lcd.print(" C");
}
void loop()
{
  //lcd.clear();

  int reading = analogRead(Temp_TMP36);
  float volts = reading * 5.0;
  volts = volts / 1024.0;
  float tempe = (volts - 0.5) * 100 ;
  lcd.setCursor(8, 0);
  lcd.print(tempe);
  delay(1000);
}

