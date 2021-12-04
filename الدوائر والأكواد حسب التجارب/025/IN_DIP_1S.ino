int Sw_pos[4] = {7, 6, 5, 4};
int current_status[4];
int last_status[4];
void setup()
{
  Serial.begin(9600);
  Serial.flush();
  Serial.println("Press the switch to check it");
  for (int i = 0; i < 4 ; i++)
  {
    pinMode(Sw_pos[i], INPUT);
    current_status[i] = digitalRead (Sw_pos[i]);
    last_status[i] = ! current_status[i] ;
  }
}
void loop()
{
  for (int i = 0; i < 4 ; i++)
  {
    current_status[i] = digitalRead (Sw_pos[i]);
    delay(100);
  }
  /////////////////------------------------------------
  for (int i = 0; i < 4 ; i++)
  {
    if (current_status[i] == 1 && last_status[i] == 0 )
    {
      Serial.print(i+1);
      Serial.println(" ON");
      last_status[i] = 1 ;
    }
    else if (current_status[i] == 0 && last_status[i] == 1 )
    {
      Serial.print(i+1);
      Serial.println(" OFF");
      last_status[i] = 0 ;
    }
  }
}
