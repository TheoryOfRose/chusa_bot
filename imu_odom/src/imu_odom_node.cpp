#include <ros/ros.h>
#include <imu_odom/imu_odom.h>
#include <math.h>

imu_odom::imu_odom(){
	bool init_result = init();
	ROS_ASSERT(init_result);
}

imu_odom::~imu_odom(){
}

bool imu_odom::init(){
	publisher_ = nh_.advertise<nav_msgs::Odometry>("odom", 1);
	subscriber_pose = nh_.subscribe<geometry_msgs::PoseWithCovarianceStamped>("pose_with_covariance_stamped", 1, &imu_odom::poseCallback, this);
	subscriber_twist = nh_.subscribe<geometry_msgs::Twist>("cmd_vel", 1, &imu_odom::twistCallback, this);
	return true;
}

void imu_odom::poseCallback(const geometry_msgs::PoseWithCovarianceStamped msg){
	pose_in = msg;
	pose_flag = true;
	if(twist_flag && pose_flag) msgCallback();
}

void imu_odom::twistCallback(const geometry_msgs::Twist msg){
	twist_in = msg;
	twist_flag = true;
	if(twist_flag && pose_flag) msgCallback();
}

void imu_odom::msgCallback(){

	nav_msgs::Odometry odom;
	odom.header.stamp = ros::Time::now();
	odom.header.frame_id = "odom";
	odom.child_frame_id = "base_footprint";

	odom.pose.pose.orientation.x = pose_in.pose.pose.orientation.x;
	odom.pose.pose.orientation.y = pose_in.pose.pose.orientation.y;
	odom.pose.pose.orientation.z = pose_in.pose.pose.orientation.z;
	odom.pose.pose.orientation.w = pose_in.pose.pose.orientation.w;
	odom.pose.pose.position.x = pose_in.pose.pose.position.x;
	odom.pose.pose.position.y = pose_in.pose.pose.position.y;
	odom.pose.pose.position.z = pose_in.pose.pose.position.z;
	odom.twist.twist.linear.x = twist_in.linear.x;
	odom.twist.twist.linear.y = twist_in.linear.y;
	odom.twist.twist.linear.z = twist_in.linear.z;
	for(int i=0; i<36; i++){
		odom.pose.covariance[i] = pose_in.pose.covariance[i];
		odom.twist.covariance[i] = 0;
	}

	publisher_.publish(odom);

	twist_flag = false;
	pose_flag = false;

}

int main(int argc, char** argv){
	ros::init(argc, argv, "imu_odom_node");
	imu_odom imu_odom_node;
	ros::Rate r(10);
	while(ros::ok()){
		ros::spinOnce();
		r.sleep();
	}
	return 0;
}
