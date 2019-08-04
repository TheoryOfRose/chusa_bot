#include "ros/ros.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Twist.h"
#include "cmd2ard/arduino.h"
#include "cmd2ard/cmd2ard.h"

Cmd2Ard::Cmd2Ard(){
  bool init_result = init();
  ROS_ASSERT(init_result);
}

Cmd2Ard::~Cmd2Ard(){

}

bool Cmd2Ard::init(){
  publisher_ = nh_.advertise<cmd2ard::arduino>("motor", 100);
  subscriber_ = nh_.subscribe("cmd_vel", 100, &Cmd2Ard::msgCallback, this);

  return true;
}

void Cmd2Ard::msgCallback(const geometry_msgs::Twist cmd_vel_in){
  int v_l, v_r, d_l, d_r;

  v_l = cmd_vel_in.linear.x - cmd_vel_in.angular.z*robot_w/2;
  v_r = cmd_vel_in.linear.x + cmd_vel_in.angular.z*robot_w/2;

  if(v_l>=0){
    d_l = 1; // move forward
  }
  else{
    d_l = 0; // move backward
  }
  if(v_r>=0){
    d_r = 1; // move forward
  }
  else{
    d_r = 0; // move backward
  }

  cmd2ard::arduino msg;

  msg.v_l = v_l;
  msg.v_r = v_r;
  msg.d_l = d_l;
  msg.d_r = d_r;

  publisher_.publish(msg);  
}

int main(int argc, char** argv){
  ros::init(argc, argv, "cmd2ard");

  Cmd2Ard cmd2ard_node;

  ros::spin();

  return 0;
}
