/*********TACHLOG powered********
*********www.troncart.com*******
**electronics components online**
***********Bluetooth controlled car**************
***********13-05-2019**************
*/
 

int incomingByte = 0;     // for incoming serial data
int enA = 9;              //setting pin 9 as the enable pin of left motor
int in1 = 5;              //setting pin 5 as the input command for left motor
int in2 = 4;              //setting pin 4 as the input command for left motor
int enB = 10;             //setting pin 10 as the enable pin of right motor
int in3 = 3;              //setting pin 3 as the input command for right motor
int in4 = 2;              //setting pin 2 as the input command for right motor
void setup()  
{
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  pinMode(enA, OUTPUT);   //Sets the digital ports used to an output
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() 
{
 if (Serial.available() > 0) // read the incoming byte:
  {
    incomingByte = Serial.read();
//    Serial.print("I received: ");
//    Serial.println(incomingByte);
switch (incomingByte) 
{
  case 83:
  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW); 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.println("both motor are at rest");
  break;

    case 70:
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.println("runs forward");
  break;

    case 66:
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  Serial.println("runs backward");
  break;

    case 82:
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  Serial.println("turns right");
  break;

    case 76:
  digitalWrite(enA, HIGH);
  digitalWrite(enB, HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.println("turns left");
  break;

    case 73:
  digitalWrite(enA, HIGH);
  digitalWrite(enB, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.println("front right");
  break;

  case 71:
  digitalWrite(enA, LOW);
  digitalWrite(enB, HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  Serial.println("front left");
  break;

  case 74:
  digitalWrite(enA, HIGH);
  digitalWrite(enB, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); 
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.println("back right");
  break;

  case 72 :
  digitalWrite(enA, LOW);
  digitalWrite(enB, HIGH);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  Serial.println("back left");
  break;
  
  default:
  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  break;

}                      
}
else
{
  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.println("do nothing");
}
  
}
