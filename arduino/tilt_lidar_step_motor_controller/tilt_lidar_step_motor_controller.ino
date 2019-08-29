#include <Arduino.h>
#include <Stepper.h>
#include <ros.h>
#include <ros/time.h>
#include <chusa_msgs/TiltClkWise.h>
#include <chusa_msgs/TiltCounterClkWise.h>
#include <chusa_msgs/ResetTilt.h>
#include <chusa_msgs/TfFromTilt.h>

const int stepsPerRevolution = 20;  // change this to fit the number of steps per revolution
ros::NodeHandle nh;

// ros service client
ros::ServiceClient<chusa_msgs::TfFromTilt::Request, chusa_msgs::TfFromTilt::Response> tf_tilt("tf_tilt");

// service server callback func
void tiltClkWiseCb(const chusa_msgs::TiltClkWise::Request &req, chusa_msgs::TiltClkWise::Response &res);
void tiltCounterClkWiseCb(const chusa_msgs::TiltCounterClkWise::Request &req, chusa_msgs::TiltCounterClkWise::Response &res);
void resetTiltCb(const chusa_msgs::ResetTilt::Request &req, chusa_msgs::ResetTilt::Response &res);

// ros service server
ros::ServiceServer<chusa_msgs::TiltClkWise::Request,chusa_msgs::TiltClkWise::Response> clk("tilt_clk",&tiltClkWiseCb);
ros::ServiceServer<chusa_msgs::TiltCounterClkWise::Request,chusa_msgs::TiltCounterClkWise::Response> cclk("tilt_counter_clk",&tiltCounterClkWiseCb);
ros::ServiceServer<chusa_msgs::ResetTilt::Request,chusa_msgs::ResetTilt::Response> reset("reset_tilt",&resetTiltCb);

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
int tick = 0;

void tiltClkWiseCb(const chusa_msgs::TiltClkWise::Request &req, chusa_msgs::TiltClkWise::Response &res){
  chusa_msgs::TfFromTilt::Request tf_req;
  chusa_msgs::TfFromTilt::Response tf_res;
  double angle = 0;
  
  for(; tick < stepsPerRevolution; tick++){
    myStepper.step(2);
    angle = 3.6 * tick;
    tf_req.tilt = angle;
    tf_tilt.call(tf_req,tf_res);
    delay(500);
  }
}
void tiltCounterClkWiseCb(const chusa_msgs::TiltCounterClkWise::Request &req, chusa_msgs::TiltCounterClkWise::Response &res){
  chusa_msgs::TfFromTilt::Request tf_req;
  chusa_msgs::TfFromTilt::Response tf_res;
  double angle = 0;
  
  for(; tick > -stepsPerRevolution; tick--){
    myStepper.step(-2);
    angle = 3.6 * tick;
    tf_req.tilt = angle;
    tf_tilt.call(tf_req,tf_res);
    delay(500);
  }
}
void resetTiltCb(const chusa_msgs::ResetTilt::Request &req, chusa_msgs::ResetTilt::Response &res){
  chusa_msgs::TfFromTilt::Request tf_req;
  chusa_msgs::TfFromTilt::Response tf_res;
  double angle = 0;
  if(tick >= 0){
    for(; tick > 0; tick--){
      myStepper.step(-2);
      angle = 3.6 * tick;
      tf_req.tilt = angle;
      tf_tilt.call(tf_req,tf_res);
      delay(200);
    }
  }
  else{
    for(; tick < 0; tick++){
      myStepper.step(2);
      angle = 3.6 * tick;
      tf_req.tilt = angle;
      tf_tilt.call(tf_req,tf_res);
      delay(200);
    }
  }
}


void setup() {
  // initialize the serial port:
  Serial.begin(9600);
  
  // set ros
  nh.initNode();
  nh.advertiseService(clk);
  nh.advertiseService(cclk);
  nh.advertiseService(reset);
  
  // set the speed at 1 rpm:
  myStepper.setSpeed(1);
  
  // L298N for Robojax.com 
  pinMode(2,OUTPUT);// for EN1
  digitalWrite(2,HIGH);// enable EN1
  pinMode(3,OUTPUT);// for EN1
  digitalWrite(3,HIGH); // enable EN2
}

void loop() {
  nh.spinOnce();
  delay(100);
}
