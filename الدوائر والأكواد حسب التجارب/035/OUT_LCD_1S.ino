#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
void setup()
{
  Serial.begin(9600);               //start serial with baud rate = 9600
  Serial.flush();                   //to wait to complete the outgoing serial data
  lcd.begin(16, 2);
  lcd.print("    Hello");
  delay(500);
  lcd.clear();
  Serial.write("enter here your massage");
}
void loop()
{
  String input = "";                //variable to save the input message
  while (Serial.available() > 0)    //that means there's data arrived from the serial
  {
    lcd.clear();
    input += (char) Serial.read();  //to read one char at a time and save it into (input) variable
    delay(5);                       //delay 5ms before next char
  }
  lcd.setCursor(0, 0);
  lcd.print(input);
  delay(500);  
}

