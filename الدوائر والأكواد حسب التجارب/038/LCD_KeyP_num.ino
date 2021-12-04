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
byte rowPins[ROWS] = {8, 7, 6, 5};
byte colPins[COLS] = {4, 3, 2, 1};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
int curs_col = 0;
void setup()
{
  lcd.begin(16, 2);
}
void loop()
{
  char key = keypad.getKey();
  if (key != NO_KEY)
  {
    lcd.print(key);
    curs_col += 1;
    if (curs_col == 16)
    {
      lcd.setCursor(0, 1);
    }
    if (curs_col == 33)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(key);
    }
  }
}
