#define Sw_pos1 7
#define Sw_pos2 8
int current_status , last_status    ;
void setup()
{
  pinMode(Sw_pos1, INPUT);
  pinMode(Sw_pos2, INPUT);
  Serial.begin(9600);
  Serial.flush();
  Serial.println("slide the switch to check it");
  current_status = digitalRead (Sw_pos1);
  last_status = ! current_status ;
}
void loop()
{
  current_status = digitalRead (Sw_pos1);
  delay(100);
  if (current_status == 1 && last_status == 0 )
  {
    Serial.println("switch is on right side");
    last_status = 1 ;
  }
  else if (current_status == 0 && last_status == 1 )
  {
    Serial.println("switch is on left side");
    last_status = 0 ;
  }
}
