//motor pin 1 is named as m1 and connected to pin 2 in Arduino
#define m1 2
//motor pin 2 is named as m1 and connected to pin 3 in Arduino
#define m2 3
void setup()
{
  //both motor pins are output pins
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  //the intial state of the motor is off
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
  Serial.begin(9600);       //start serial with baud rate = 9600
  Serial.flush();           //to wait to complete the outgoing serial data
  Serial.println("to operate the motor write here : ");
  Serial.println("right - left - off");
}
void loop()
{
  String input = "";                //variable to save the input message
  while (Serial.available() > 0)    //that means there's data arrived from the serial
  {
    input += (char) Serial.read();  //to read one char at a time and save it into (input) variable
    delay(5);                       //delay 5ms before next char
  }
  if (input == "right")
  {
    //pin_1 HIGH, pin_2 LOW >>> rotat diresction 1
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    delay(1000);
  }
  else if (input == "left")
  {
    //pin_1 LOW, pin_2 HIGH >>> rotat diresction 2
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    delay(1000);
  }
  else if (input == "off")
  {
    //both pins LOW >>> stop rotation
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    delay(1000);
  }
}
