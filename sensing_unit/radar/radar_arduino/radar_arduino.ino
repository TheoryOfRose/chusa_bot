#include<Servo.h> // add servo lib
Servo servo1; // motor of radar 1
int servo1_pin = 2;
int value = 0; // var of angle


void setup() {
  // put your setup code here, to run once:
  servo1.attach(servo1_pin); // attach D2 pin
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    char in_data;
    in_data = Serial.read();
    if(in_data == '1')
    {
      value += 30;
      if(value == 180) value = 0;
    }
    else value = 0;

    servo1.write(value); // rotate by angle value
  }
  delay(1000);
}
