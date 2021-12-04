#include "IRremote.h"
int receiver = 2;
int led_R = 8;
int led_G = 9;
int led_B = 10;
IRrecv irrecv(receiver);           
decode_results results;            
void setup()
{
  pinMode(led_R,OUTPUT);  
  pinMode(led_G,OUTPUT);  
  pinMode(led_B,OUTPUT);  
  irrecv.enableIRIn(); 
}
void translateIR() //do this depend on received IR signal 
{
  switch(results.value)
  {
    case 0xFD08F7:    //button : 1
    digitalWrite(led_R,HIGH); 
    break;

  case 0xFD8877:      //button : 2
    digitalWrite(led_G,HIGH); 
    break;

  case 0xFD48B7:      //button : 3
    digitalWrite(led_B,HIGH); 
    break;
    
    case 0xFD28D7:    //button : 4
    digitalWrite(led_R,LOW); 
    break;

  case 0xFDA857:      //button : 5
    digitalWrite(led_G,LOW); 
    break;

  case 0xFD6897:      //button : 6
    digitalWrite(led_B,LOW); 
    break;
  }
  delay(500);
} 
void loop()   
{
  if (irrecv.decode(&results)) 
      {
     translateIR(); 
    irrecv.resume(); 
  }  
}
