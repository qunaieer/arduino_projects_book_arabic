const int buzzerPin = 7;
const int lightPin = 8;
const int pirSensor = 9;
int moveDetect, lightBulb;
void setup()
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(pirSensor, INPUT);
  pinMode(lightPin, INPUT);
}

void loop()
{
  moveDetect = digitalRead(pirSensor);
  lightBulb = digitalRead(lightPin);
  if (moveDetect == 1)
  {
    if ( lightBulb == 0)
    {
      digitalWrite(buzzerPin, HIGH);
      delay(500);
    }
  }
  else
  {
    digitalWrite(buzzerPin, LOW);
  }
  delay(100);
}

