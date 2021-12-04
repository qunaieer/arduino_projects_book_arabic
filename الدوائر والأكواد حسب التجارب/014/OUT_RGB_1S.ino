int OUT_R = 9;                      //red pin connected to pin 9
int OUT_B = 10;                     //blue pin connected to pin 10
int OUT_G = 11;                     //green pin connected to pin 11
void setup()
{
  pinMode(OUT_R, OUTPUT);           //make the three pins as output
  pinMode(OUT_G, OUTPUT);
  pinMode(OUT_B, OUTPUT);
  Serial.begin(9600);               //start serial with baud rate = 9600
  Serial.flush();                   //to wait to complete the outgoing serial data
  Serial.write("choose color and write: red, green, blue or off");
}
void loop()
{
  String input = "";                //variable to save the input message
  while (Serial.available() > 0)    //that means there's data arrived from the serial
  {
    input += (char) Serial.read();  //to read one char at a time and save it into (input) variable
    delay(5);                       //delay 5ms before next char
  }
  if (input == "red")               //if you write/send (red) by serial
  {
    analogWrite(OUT_R, 255);        //red pin high, others low
    analogWrite(OUT_G, 0);
    analogWrite(OUT_B, 0);
    delay(500);                     //delay 0.5 second to see the light color
  }
  else if (input == "green")        //if you write/send (green) by serial
  {
    analogWrite(OUT_R, 0);
    analogWrite(OUT_G, 255);        //green pin high, others low
    analogWrite(OUT_B, 0);
    delay(500);
  }
  else if (input == "blue")         //if you write/send (blue) by serial
  {
    analogWrite(OUT_R, 0);
    analogWrite(OUT_G, 0);
    analogWrite(OUT_B, 255);        //blue pin high, others low
    delay(500);
  }
  else if (input == "off")          //if you write/send (blue) by serial
  {
    analogWrite(OUT_R, 0);          //all off
    analogWrite(OUT_G, 0);
    analogWrite(OUT_B, 0);
    delay(500);
  }
}
