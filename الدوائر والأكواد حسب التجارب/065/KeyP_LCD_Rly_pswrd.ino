#include <LiquidCrystal.h>
#include "Keypad.h"
#define device 2
boolean device_status = LOW;
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] =
{ {'1', '2', '3' , 'A'},
  {'4', '5', '6' , 'B'},
  {'7', '8', '9' , 'C'},
  {'*', '0', '#' , 'D'}
};
byte rowPins[ROWS] = {11, 10, 9, 8};
byte colPins[COLS] = {7, 6, 5, 4};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
String secret_code = "88888888";
String user_type;
int counter = 0;
void setup()
{
  lcd.begin(16, 2);
  lcd.print("password to open");
  lcd.setCursor(4, 1);
}
void loop()
{
  char key = keypad.getKey();
  if (key != NO_KEY)
  {
    lcd.print('*');
    user_type += key;
    counter ++;
    if (counter == 8)
    {
      counter = 0;
      lcd.clear();
      lcd.setCursor(0, 0);
      if (user_type == secret_code)
      {
        lcd.print("Accepted");
        lcd.setCursor(0, 1);
        if (device_status == LOW)
        {
          lcd.print("Device : ON");
          digitalWrite (device, HIGH);
          device_status = HIGH;
        }
        else if (device_status == HIGH)
        {
          lcd.print("Device : OFF");
          digitalWrite (device, LOW);
          device_status = LOW;
        }
        delay(1000);
      }
      else
      {
        lcd.print("Rejected");
        lcd.setCursor(0, 1);
        lcd.print("Try again");
      }
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      if (device_status == LOW)
      {
        lcd.print("password to open");
      }
      else if (device_status == HIGH)
      {
        lcd.print("pasword to close");
      }
      lcd.setCursor(4, 1);
      user_type = "";
    }
  }
}
