#include <LiquidCrystal.h>
#include "Keypad.h"
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] =
{ {'1', '2', '3' , 'A'},
  {'4', '5', '6' , 'B'},
  {'7', '8', '9' , 'C'},
  {'*', '0', '#' , 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
String secret_code = "2580";
String user_type;
int counter = 0;
void setup()
{
  lcd.begin(16, 2);
  lcd.print(" Enter PIN code");
  lcd.setCursor(6, 1);
}
void loop()
{
  char key = keypad.getKey();
  if (key != NO_KEY)
  {
    lcd.print(key);
    user_type += key;
    counter ++;
    if (counter == 4)
    {
      counter = 0;
      lcd.clear();
      lcd.setCursor(0, 0);
      if ( user_type == secret_code)
      {
        lcd.print("Successful");
        lcd.setCursor(0, 1);
        lcd.print("operation");
      }
      else
      {
        lcd.print("Faild");
        lcd.setCursor(0, 1);
        lcd.print("Try again");
      }
      delay(1000);
      lcd.clear();
      lcd.print(" Enter PIN code");
      lcd.setCursor(6, 1);
      user_type = "";
    }
  }
}
