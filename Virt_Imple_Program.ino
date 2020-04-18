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
    *The Inbuilt LED blinks if an input other than the above are given
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
  pinMode(13,OUTPUT); //Pin with Inbuilt LED 
  Arm.attach(30);  // Configures the Servo in Arm onto pin 30 with Servo object
  Grip.attach(31);  // Configures the Servo in Gripper onto pin 31 with Servo object
}

void loop() 
{
  char data=Serial.read();  //Reads the Input from the Serial Monitor which is obtained through Bluetooth Module
  if(data=='a')
  {
    digitalWrite(6,HIGH); //Rotates the Lead Screw Motor Clockwise for 20 Seconds 
    digitalWrite(7,LOW);  //Makes the Base move forward by 8cm
    delay(20000);
    digitalWrite(6,LOW);  //Stops the Motor
    digitalWrite(7,LOW);
  }
  else if(data=='b')
  {
    digitalWrite(6,LOW); //Rotates the Lead Screw Motor Anti-Clockwise for 20 Seconds 
    digitalWrite(7,HIGH); //Makes the Base to come back by 8cm
    delay(20000);
    digitalWrite(6,LOW);  //Stops the Motor
    digitalWrite(7,LOW);
  }
  else if(data=='c')
  {
    digitalWrite(8,HIGH); //Rotates the Motor placed on the Base Clockwise for 1 second
    digitalWrite(9,LOW);  //Rotates the Base Clockwise by 60 degrees 
    delay(1000);
    digitalWrite(8,LOW);  //Halts the Rotation of the Base
    digitalWrite(9,LOW);
  }
    else if(data=='d')
  {
    digitalWrite(8,LOW); //Rotates the Motor placed on the Base Anti-Clockwise for 1 second
    digitalWrite(9,HIGH); //Rotates the Base Anti-Clockwise by 60 degrees 
    delay(1000);
    digitalWrite(8,LOW);  //Halts the Rotation of the Base
    digitalWrite(9,LOW);
  }
   else if(data=='e')
  {
    digitalWrite(10,HIGH); //Rotates the Motor placed between 1st and 2nd Arm, Clockwise for 800 milli-seconds
    digitalWrite(11,LOW); //Lowers the 2nd Arm by 40 degrees 
    delay(800);
    digitalWrite(10,LOW);  //Halts the Movement of 2nd Arm
    digitalWrite(11,LOW);
  }
   else if(data=='f')
  {
    digitalWrite(10,LOW); //Rotates the Motor placed between 1st and 2nd Arm, Anti-Clockwise for 800 milli-seconds
    digitalWrite(11,HIGH); //Raises the 2nd Arm by 40 degrees 
    delay(800);
    digitalWrite(10,LOW);  //Halts the Movement of 2nd Arm
    digitalWrite(11,LOW);
  }
  else if(data=='g') //Lowers the 3rd arm by 40 degrees
  {
    for(armpos=0; armpos<=40; armpos++) //loop to increment the position of Servo in each iteration by 1 degree upto 40 degree
        {
          Arm.write(armpos);  //Commands the Metal Gear Servo in 3rd Arm to go to the position in variable 'armpos'
          delay(10);  //Waits 10 milli-seconds to go to that position
        }
  }
  else if(data=='h') //Raises the 3rd Arm by 40 degrees
  {
    for(armpos=40; armpos>=0; armpos--) //loop to decrement the position of Servo in each iteration by 1 degree upto 0 degree
        {
          Arm.write(armpos);  //Commands the Metal Gear Servo in 3rd Arm to go to the position in variable 'armpos'
          delay(10);  //Waits 10 milli-seconds to go to that position
        }
  }
  else if(data=='i') // Clenches the gripper
  {
    for(gripos=0; gripos<=90; armpos++) //loop to increment the position of Servo in each iteration by 1 degree upto 90 degree
        {
          Grip.write(armpos);  //Commands the Toy Servo in Gripper to go to the position in variable 'gripos'
          delay(10);  //Waits 10 milli-seconds to go to that position
        }
  }
  else if(data=='j') //Un-Clenches the Gripper
  {
    for(gripos=90; gripos>=0; armpos--) //loop to decrement the position of Servo in each iteration by 1 degree upto 0 degree
        {
          Grip.write(armpos);  //Commands the Toy Servo in Gripper to go to the position in variable 'gripos'
          delay(10);  //Waits 10 milli-seconds to go to that position
        }
  }
  else
  {
    digitalWrite(13,HIGH);  //Blinks the Inbuilt LED present in the Arduino at pin 13
    delay(1000);                       
    digitalWrite(13,LOW);   //This works as an indicator if an indicator other than the ones present in the Index are given 
    delay(1000);                      
  }
}
