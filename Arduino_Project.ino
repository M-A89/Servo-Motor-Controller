// 
// Project Miae 215 - Fall 2022
// Mira Alanzarouti 
// This arduino program controls the servo motor using the joystick by using analogue read amd map to alter servo position,
// it also prints out the y joystick position at every instant and it uses the position to light LEDS at 2 specific positions.
//including the servo library 
#include <Servo.h>

//creating a global servo object 
Servo servo_project;
int servo_pin = 4;   //integer to store servo pin number
int joystick = 1;    //integer to store joycon to analog pin 1

//code that only runs once 
void setup()
//establishing serial communication at 9600 baud rate 
  Serial.begin(9600);
//setting digital pin 13 as output
  pinMode(13, OUTPUT);
//setting digital pin 12 as output
  pinMode(12, OUTPUT);
//connecting servo to digital pin number 4
  servo_project.attach(servo_pin);
}

//code that keeps on running in a loop 
void loop()
{

//reads joystick value from the analog pin 4, 
  int joystick_value = analogRead(joystick); 

//Joystick values range from 0-1023 depending on position
  joystick_value = map(joystick_value, 0, 1023, 10, 170); //Scale the joystick X value to use it with the servo

//Sets the servo position according to the scaled values.
  servo_project.write(joystick_value);   
   
//printing the y position(found using map and analogRead) at every iteration of the loop
  Serial.print("Y JOYSTICK POSITION: ");      
  Serial.println(joystick_value);             
  
   //if the joystick stored value is equal to 10 (recorded position when joystick is turned to the left) turn on output 5V to digital pin 13 and low to pin 12
     if (joystick_value == 10){
       digitalWrite(13, HIGH);
       digitalWrite(12, LOW);
     }
     //if the joystick stored value is equal to 89 (recorded position when joystick is not being used at all) turn off both LEDS
     if (joystick_value == 89){
        digitalWrite(13, LOW);
       digitalWrite(12, LOW);
     }
     //if the joystick stored value is equal to 170 (recorded position when joystick is to the right) turn oon both LED at pin 12 and turn off pin 13
      if (joystick_value == 170){
        digitalWrite(13, LOW);
       digitalWrite(12, HIGH);
     }
  
 
  //delay by 10ms before starting loop again
   delay(10);
}
