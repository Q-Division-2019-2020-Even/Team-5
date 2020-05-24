/*
    Instructions for giving the Input :-
    *To move the base by 8cm forward - 'a'
    *To move the base by 8cm back - 'b'
    *To rotate the base 60 degrees clockwise - 'c'
    *To rotate the base 60 degrees anti-clockwise - 'd'
    *To lower the 2nd Arm by 40 degrees - 'e' 
    *To raise the 2nd Arm by 40 degrees - 'f'
    *To lower the 3nd Arm by 40 degrees - 'g'
    *To raise the 3nd Arm by 40 degrees - 'h'
    *To make the Gripper to Clench the Object - 'i'
    *To make the Gripper to Un-Clench the Object - 'j'
*/

#include <Servo.h>
Servo Arm;  //Creates a Servo object to Control the Metal Gear Servo placed between 2nd and 3rd Arm
Servo Grip; //Creates a Servo object to Control the Toy Servo within the Gripper

int armpos = 0;    // variable to store the position of Servo Motor present in the Arm
int gripos = 0;    // variable to store the position of Servo Motor present in the Gripper
void setup() 
{
  Serial.begin(9600);
  pinMode(6,OUTPUT);  //Lead Screw Motor
  pinMode(7,OUTPUT);  //Lead Screw Motor
  pinMode(8,OUTPUT);  //Base Rotation Motor
  pinMode(9,OUTPUT);  //Base Rotation Motor
  pinMode(10,OUTPUT); //2nd Arm Bending Motor
  pinMode(11,OUTPUT); //2nd Arm Bending Motor
  Arm.attach(4);  // Configures the Servo in Arm onto pin 30 with Servo object
  Grip.attach(5);  // Configures the Servo in Gripper onto pin 31 with Servo object
  Arm.write(armpos);
  Grip.write(gripos);
}

void loop() 
{
  char data=Serial.read();  //Reads the Input from the Serial Monitor which is obtained through Bluetooth Module
  if(data=='a')
  {
    digitalWrite(6,HIGH); //Rotates the Lead Screw Motor Clockwise for 20 Seconds 
    digitalWrite(7,LOW);  //Makes the Base move forward by 8cm
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    delay(2000);
    digitalWrite(6,LOW);  //Stops the Motor
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  }
  else if(data=='b')
  {
    digitalWrite(6,LOW); //Rotates the Lead Screw Motor Anti-Clockwise for 20 Seconds 
    digitalWrite(7,HIGH); //Makes the Base to come back by 8cm
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    delay(2000);
    digitalWrite(6,LOW);  //Stops the Motor
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  }
  else if(data=='c')
  {
    digitalWrite(8,HIGH); //Rotates the Motor placed on the Base Clockwise for 1 second
    digitalWrite(9,LOW);  //Rotates the Base Clockwise by 60 degrees 
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    delay(1000);
    digitalWrite(8,LOW);  //Halts the Rotation of the Base
    digitalWrite(9,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  }
    else if(data=='d')
  {
    digitalWrite(8,LOW); //Rotates the Motor placed on the Base Anti-Clockwise for 1 second
    digitalWrite(9,HIGH); //Rotates the Base Anti-Clockwise by 60 degrees 
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    delay(1000);
    digitalWrite(8,LOW);  //Halts the Rotation of the Base
    digitalWrite(9,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
  }
   else if(data=='e')
  {
    digitalWrite(10,HIGH); //Rotates the Motor placed between 1st and 2nd Arm, Clockwise for 800 milli-seconds
    digitalWrite(11,LOW); //Lowers the 2nd Arm by 40 degrees 
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    delay(800);
    digitalWrite(10,LOW);  //Halts the Movement of 2nd Arm
    digitalWrite(11,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
  }
   else if(data=='f')
  {
    digitalWrite(10,LOW); //Rotates the Motor placed between 1st and 2nd Arm, Anti-Clockwise for 800 milli-seconds
    digitalWrite(11,HIGH); //Raises the 2nd Arm by 40 degrees 
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    delay(800);
    digitalWrite(10,LOW);  //Halts the Movement of 2nd Arm
    digitalWrite(11,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
  }
  else if(data=='g') //Lowers the 3rd arm by 40 degree
  {
    Arm.write(armpos);
    armpos=40;
    Arm.write(armpos);
  }
  else if(data=='h') //Raises the 3rd Arm by 40 degrees
  {
    armpos=0;
    Arm.write(armpos);
  }
  else if(data=='i') // Clenches the gripper
  {
    Grip.write(gripos);
    gripos=90;
    Grip.write(gripos);
  }
  else if(data=='j') //Un-Clenches the Gripper
  {
    gripos=0;
    Grip.write(gripos);
  }
}
