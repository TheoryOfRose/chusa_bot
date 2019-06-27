/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/
#include <Servo.h>

// defines pins numbers
Servo servo1;
const int servo1_pin = 2;
const int trigPin1 = 3;
const int echoPin1 = 4;

// defines variables
int angle1 = 0;
long duration1;
int distance1;

void setup() {
  pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  servo1.attach(servo1_pin); // Attach D2 pin  
}

void loop() {
  // rotates the servo motor from 0 to 180 degrees
  for(int i=0;i<=179;i++){  

    servo1.write(i);
    delay(35);
    distance1 = calculateDistance();// Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  
  }
  // Repeats the previous lines from 180 to 0 degrees
  for(int i=179;i>0;i--){  
  
    servo1.write(i);
    delay(35);
    distance = calculateDistance();
   
  }
}

int calculateDistance(){
  // Clears the trigPin
  digitalWrite(trigPin1, LOW);
  delay(500);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration1 = pulseIn(echoPin1, HIGH);
  // Calculating the distance
  distance1= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance1);
  return distance1;
}
