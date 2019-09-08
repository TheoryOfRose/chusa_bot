#include <Arduino.h>
#include <ros.h>
#include <ros/time.h>
#include <chusa_msgs/TiltStamped.h>
#include <Stepper.h>

Stepper myStepper(1, 8, 9, 10, 11);
ros::NodeHandle nh;
void msgCb(const chusa_msgs::TiltStamped& msg);
ros::Subscriber<chusa_msgs::TiltStamped> sub("/tilt", msgCb);
int tick = 0;
void msgCb(const chusa_msgs::TiltStamped& msg){
  if(tick < msg.tilt.tick){
    myStepper.step(-1);
    delay(10);
  }
  else if(tick > msg.tilt.tick){
    myStepper.step(1);
    delay(10);
  }
  
}

void setup()
{
  myStepper.setSpeed(60);
  nh.getHardware()->setBaud(57600);
  nh.initNode();
  nh.subscribe(sub);
}

void loop() 
{
  nh.spinOnce();
  delay(100);
}
