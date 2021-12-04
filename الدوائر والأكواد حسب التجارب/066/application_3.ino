#include <LiquidCrystal.h>
#include "Keypad.h"
#define temp_sensor A0
#define fan 12
LiquidCrystal lcd( 2, 3, 4, 5, 6, 7);
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] =
{ {'1', '2', '3' , 'A'},
  {'4', '5', '6' , 'B'},
  {'7', '8', '9' , 'C'},
  {'*', '0', '#' , 'D'}
};
byte rowPins[ROWS] = {11, 10, 9, 8};
byte colPins[COLS] = {A5, A4, A3, A2};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
int user_type = 20;
int tempe2 = 0;
void setup()
{
  lcd.begin(16, 2);
  pinMode(fan, OUTPUT);
  digitalWrite(fan, LOW);
}
void loop()
{
  lcd.setCursor(0, 0);
  lcd.print("temp now: ");
  //measure temperature & print
  int reading = analogRead(temp_sensor);
  float volts = reading * 5.0;
  volts = volts / 1024.0;
  float tempe = (volts - 0.5) * 100 ;
  lcd.setCursor(10, 0);
  lcd.print(tempe);
  lcd.setCursor(14, 0);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Set temp: ");
  lcd.setCursor(10, 1);
  lcd.print(user_type);
  int key = keypad.getKey();        //read ASCII code number from the keypad
  if (key != NO_KEY)                //check if it's real push
  {
    key -= 48;                      //to convert from ASCII code to decimal number
    lcd.setCursor(10, 1);
    lcd.print(key);                 //print the new number (1st digit)
    lcd.setCursor(11, 1);
    lcd.print(" ");                 //delete the old number
    user_type = key * 10;           //the (1st difit) is multiplying * 10
    key = keypad.getKey();          //read from the keypad
    while (key == NO_KEY)           //wait here until press new key
    {
      key = keypad.getKey();        //read again from the keypad
    }
    // now we got a new number in (key) variable
    key -= 48;                      //check ASCII code table
    lcd.setCursor(11, 1);
    lcd.print(key);                 // print the new number (2nd digit)
    user_type = user_type + key;    //put the (1st digit) and (2nd digit) together
    delay(100);
    lcd.clear();
  }
  tempe2 = (int)tempe;             //convert float to integer
  if (tempe2 > user_type)          //if temerature increased
  {
    digitalWrite(fan, HIGH);       //power on the fan
  }
  else digitalWrite(fan, LOW);     //else, power off the fan
}
