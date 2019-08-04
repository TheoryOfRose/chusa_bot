#include "ros/ros.h"
#include "chusa_odom/chusa_odom.h"

chusa_odom::chusa_odom(){
  bool init_result = init();
  ROS_ASSERT(init_result);
}

chusa_odom::~chusa_odom(){

}

bool chusa_odom::init(){
  publisher_ = nh_.advertise<nav_msgs::Odometry>("odom", 10);
  subscriber_ = nh_.subscribe("cmd_vel", 100, &chusa_odom::msgCallback, this);

  return true;
}

void chusa_odom::msgCallback(const geometry_msgs::Twist cmd_vel_in){
  double vx,vy,vth;
  double x,y,th;
  
  vx = cmd_vel_in.linear.x;
  vy = 0;
  vth = cmd_vel_in.angular.z;

  x = y = th = 0.0;
  
  ros::Time current_time;
  ros::Time last_time;
  current_time = ros::Time::now();
  last_time = ros::Time::now();

  tf::TransformBroadcaster broadcaster;
  ros::Rate loop_rate(20);

  const double degree = M_PI/180;

  geometry_msgs::TransformStamped odom_trans;
  odom_trans.header.frame_id = "odom";
  odom_trans.child_frame_id = "base_footprint";

  while(ros::ok()){
	  current_time = ros::Time::now();

	  double dt = (current_time - last_time).toSec();
	  double delta_x = ( vx * cos(th) - vy * sin(th)) * dt;
	  double delta_y = ( vx * sin(th) + vy * cos(th)) * dt;
	  double delta_th = vth * dt;

	  x+=delta_x;
	  y+=delta_y;
	  th+=delta_th;

	  geometry_msgs::Quaternion odom_quat;
	  odom_quat = tf::createQuaternionMsgFromRollPitchYaw(0,0,th);

	  //update transform
	  odom_trans.header.stamp = current_time;
	  odom_trans.transform.translation.x = x;
	  odom_trans.transform.translation.y = y;
	  odom_trans.transform.translation.z = 0.0;
	  odom_trans.transform.rotation = tf::createQuaternionMsgFromYaw(th);

	  //filling the odometry
	  nav_msgs::Odometry odom;
	  odom.header.stamp = current_time;
	  odom.header.frame_id = "odom";
	  odom.child_frame_id = "base_footprint";

	  //position
	  odom.pose.pose.position.x = x;
	  odom.pose.pose.position.y = y;
	  odom.pose.pose.position.z = 0.0;
	  odom.pose.pose.orientation = odom_quat;

	  //velocity
	  odom.twist.twist.linear.x = vx;
	  odom.twist.twist.linear.y = vy;
	  odom.twist.twist.linear.z = 0.0;
	  odom.twist.twist.angular.x = 0.0;
	  odom.twist.twist.angular.y = 0.0;
	  odom.twist.twist.angular.z = vth;

	  last_time = current_time;

	  broadcaster.sendTransform(odom_trans);
	  publisher_.publish(odom);

	  loop_rate.sleep();
	  }
  
}

int main(int argc, char** argv){
  ros::init(argc, argv, "chusa_odom");

  chusa_odom chusa_odom_node;

  ros::spin();

  return 0;
}
