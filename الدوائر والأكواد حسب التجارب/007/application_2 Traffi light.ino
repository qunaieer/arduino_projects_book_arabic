int man_green = 8;
int man_red = 9;
int car_red = 10;
int car_yellow = 11;
int car_green = 12;
void setup()
{
  for (int x = 8 ; x < 13 ; x++)
  {
    pinMode(x, OUTPUT);
    digitalWrite (x, LOW);
  }
}
void loop()
{
  // man stop
  digitalWrite(man_red, HIGH);
  //_________ safe waiting time
  delay(500);
  //car go
  digitalWrite(car_red, LOW);
  digitalWrite(car_green, HIGH);
  //_________ time for car going
  delay(3000);
  //car flash yellow
  digitalWrite(car_green, LOW);
  for (int x = 0 ; x < 6; x++)
  {
    digitalWrite(car_yellow, HIGH);
    delay(300);
    digitalWrite(car_yellow, LOW);
    delay(300);
  }
  //car stop
  digitalWrite(car_red, HIGH);
  //_________ safe waiting time
  delay(500);
  //man go
  digitalWrite(man_red, LOW);
  digitalWrite(man_green, HIGH);
  //_________ time for man going
  delay(3000);
  // man flash
  for (int x = 0 ; x < 6; x++)
  {
    digitalWrite(man_green, HIGH);
    delay(300);
    digitalWrite(man_green, LOW);
    delay(300);
  }
  // man stop
  digitalWrite(man_red, HIGH);
}

