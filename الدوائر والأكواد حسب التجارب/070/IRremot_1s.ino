#include <IRremote.h>
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();      //enable IR receiver
}
void loop()
{
  if (irrecv.decode(&results))     //If there's IR signal
  {
    Serial.println(results.value, HEX);
    irrecv.resume();      //receive the next value
  }
  delay(100);
}

