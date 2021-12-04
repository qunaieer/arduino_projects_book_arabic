int Relay_1 = 7;
int Relay_2 = 6;
int Relay_3 = 5;
int Relay_4 = 4;
void setup()
{
  pinMode(Relay_1, OUTPUT);
  pinMode(Relay_2, OUTPUT);
  pinMode(Relay_3, OUTPUT);
  pinMode(Relay_4, OUTPUT);
  digitalWrite(Relay_1, LOW);
  digitalWrite(Relay_2, LOW);
  digitalWrite(Relay_3, LOW);
  digitalWrite(Relay_4, LOW);
  Serial.begin(9600);               //start serial with baud rate = 9600
  Serial.flush();                   //to wait to complete the outgoing serial data
  Serial.println("write Relay number: 1 / 2 / 3 / 4");
  Serial.println("then status you want: on / off");
  Serial.println("EX: 1 on");
}
void loop()
{
  String input = "";                //variable to save the input message
  while (Serial.available() > 0)    //that means there's data arrived from the serial
  {
    input += (char) Serial.read();  //to read one char at a time and save it into (input) variable
    delay(5);                       //delay 5ms before next char
  }
  if (input == "1 on")
  {
    digitalWrite(Relay_1, HIGH);
    delay (500);
  }
  else if (input == "1 off")
  {
    digitalWrite(Relay_1, LOW);
    delay (500);
  }
  if (input == "2 on")
  {
    digitalWrite(Relay_2, HIGH);
    delay (500);
  }
  else if (input == "2 off")
  {
    digitalWrite(Relay_2, LOW);
    delay (500);
  }
  if (input == "3 on")
  {
    digitalWrite(Relay_3, HIGH);
    delay (500);
  }
  else if (input == "3 off")
  {
    digitalWrite(Relay_3, LOW);
    delay (500);
  }
  if (input == "4 on")
  {
    digitalWrite(Relay_4, HIGH);
    delay (500);
  }
  else if (input == "4 off")
  {
    digitalWrite(Relay_4, LOW);
    delay (500);
  }
}

