int Relay_1 = 7;          
void setup()
{
  pinMode(Relay_1, OUTPUT);     
}
void loop()                      
{
  digitalWrite(Relay_1, HIGH);      
  delay (1000);                  
  digitalWrite(Relay_1, LOW);    
  delay (1000);
}
