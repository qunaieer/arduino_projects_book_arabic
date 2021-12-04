#include "IRremote.h"
int receiver = 11;
int lamp = 6;
bool lamp_status = LOW;
IRrecv irrecv(receiver);
decode_results results;
void setup()
{
  pinMode(lamp, OUTPUT);
  irrecv.enableIRIn();
}
void translateIR() //do this depend on received IR signal
{
  switch (results.value)
  {
    case 0xFD30CF:    //button : 0
      lamp_status = !lamp_status;
      digitalWrite(lamp, lamp_status);
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
