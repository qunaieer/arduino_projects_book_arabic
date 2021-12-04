#define Sw_pos 7
int current_status , last_status;
void setup()
{
  pinMode(Sw_pos, INPUT);
  Serial.begin(9600);
  Serial.flush();
  Serial.println("Press the switch to check it");
  current_status = digitalRead (Sw_pos);
  last_status = ! current_status ;
}
void loop()
{
  current_status = digitalRead (Sw_pos);
  delay(100);
  if (current_status == 1 && last_status == 0 )
  {
    Serial.println("switch is ON");
    last_status = 1 ;
  }
  else if (current_status == 0 && last_status == 1 )
  {
    Serial.println("switch is OFF");
    last_status = 0 ;
  }
}
