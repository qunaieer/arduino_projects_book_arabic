// Project 6 - Creating a Single-Cell Battery Tester

#define newLED 11     // green LED 'new'
#define okLED 12      // yellow LED 'ok'
#define oldLED 13     // red LED 'old'
int analogValue = 0;
float voltage = 0;
int ledDelay = 2000;
void setup()
{
  pinMode(newLED, OUTPUT);
  pinMode(okLED, OUTPUT);
  pinMode(oldLED, OUTPUT);
}
void loop()
{
  analogValue = analogRead(0);
  voltage = 0.0048 * analogValue;
  if ( voltage >= 1.6 )
  {
    digitalWrite(newLED, HIGH);
    delay(ledDelay);
    digitalWrite(newLED, LOW);
  }
  else if ( voltage < 1.6 && voltage > 1.4 )
  {
    digitalWrite(okLED, HIGH);
    delay(ledDelay);
    digitalWrite(okLED, LOW);
  }
  else if ( voltage <= 1.4 )
  {
    digitalWrite(oldLED, HIGH);
    delay(ledDelay);
    digitalWrite(oldLED, LOW);
  }
}

