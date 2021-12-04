#include <Keypad.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
const byte Rows = 4;
const byte Cols = 4;
char keys[Rows][Cols] =
{
  {'1', '2', '3', '+'},
  {'4', '5', '6', '-'},
  {'7', '8', '9', '*'},
  {'C', '0', '=', '/'}
};
byte rowPins[Rows] = {11, 10, 9, 8};
byte colPins[Cols] = {7, 6, 5, 4};
Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, Rows, Cols);
float num1, num2;
float total;
char operation, button;
void setup()
{
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Simple Arduino");
  lcd.setCursor(3, 1);
  lcd.print("Calculator");
  delay(1000);
  lcd.clear();
}
void loop()
{
  //Loop for reading 1st number
  while (1)
  {
    button = customKeypad.getKey();
    if (button == 'C')    //Clear
    {
      operation = 0;
      num1 = 0;
      num2 = 0;
      total = 0;
      lcd.clear();
    }
    else if (button >= '0' && button <= '9')
    {
      lcd.setCursor(0, 0);
      num1 = button - 48;
      lcd.print(num1);
      lcd.setCursor(1, 0);
      lcd.print("   ");
    }
    else if (button == '-' || button == '+' || button == '*' || button == '/')
    {
      operation = button;
      lcd.setCursor(0, 1);
      lcd.print(operation);
      break;
    }
  }
  //Loop for reading 2nd number
  while (1)
  {
    button = customKeypad.getKey();
    if (button == 'C')
    {
      num1 = 0;
      num2 = 0;
      total = 0;
      operation = 0;
      lcd.clear();
      break;
    }
    else if (button >= '0' && button <= '9')
    {
      lcd.setCursor(1, 1);
      num2 = button - 48;
      lcd.print(num2);
      lcd.setCursor(2, 1);
      lcd.print("   ");
    }
    if (button == '=')
    {
      domath();
      break;
    }
  }
  //Loop to check if button 'C' is pressed after 2nd number
  while (1)
  {
    button = customKeypad.getKey();
    if (button == 'C')
    {
      num1 = 0;
      num2 = 0;
      total = 0;
      operation = 0;
      lcd.clear();
      break;        //go out from the loop
    }
  }
}
void domath()
{
  switch (operation)
  {
    case '+':
      total = num1 + num2;
      break;
    case '-':
      total = num1 - num2;
      break;
    case '/':
      total = num1 / num2;
      break;
    case '*':
      total = num1 * num2;
      break;
  }
  lcd.setCursor(2, 1);
  lcd.print('=');
  if (operation == '/' && num2 == 0)
  {
    lcd.print("ERROR 0 DIV");
  }
  else
  {
    lcd.print(total);
  }
}
