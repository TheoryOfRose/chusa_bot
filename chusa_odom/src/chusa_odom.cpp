#include <ros/ros.h>
#include <chusa_odom/chusa_odom.h>
#include <math.h>

Chusa_Odom::Chusa_Odom(){
	bool init_result = init();
	ROS_ASSERT(init_result);
}

Chusa_Odom::~Chusa_Odom(){
}

bool Chusa_Odom::init(){
	publisher_ = nh_.advertise<nav_msgs::Odometry>("odom", 1);
	subscriber_pose = nh_.subscribe<geometry_msgs::PoseWithCovarianceStamped>("pose_with_covariance_stamped", 1, &Chusa_Odom::cb1, this);
	subscriber_vel = nh_.subscribe<geometry_msgs::Twist>("cmd_vel", 1, &Chusa_Odom::cb2, this);
	return true;
}

void Chusa_Odom::cb1(const geometry_msgs::PoseWithCovarianceStamped msg){
	pose_in = msg;
	pose_flag = true;
	if(vel_flag && pose_flag) msgCallback();
}

void Chusa_Odom::cb2(const geometry_msgs::Twist msg){
	vel_in = msg;
	vel_flag = true;
	if(vel_flag && pose_flag) msgCallback();
}

void Chusa_Odom::msgCallback(){
	double max_linear_x = 0.5;
	double max_linear_y = 0.2;
	double max_angular_z = 0.5;
	if(flags == false){
		curr_x = pose_in.pose.pose.position.x;
		curr_y = pose_in.pose.pose.position.y;
		for(int i = 0 ; i < 10 ; i ++){
			prev_xx[i] = pose_in.pose.pose.position.x;
			prev_yy[i] = pose_in.pose.pose.position.y;
		}
		prev_z = curr_z = 0.0;
		
		curr_time = ros::Time::now().toSec();
		for(int i = 0 ; i < 10; i++){
			prev_time[i] = curr_time;
		}
		flags = true;
	}
	else{
		curr_time = ros::Time::now().toSec();
		curr_x = pose_in.pose.pose.position.x;
		curr_y = pose_in.pose.pose.position.y;
		curr_z = 0.0;

		double dt = (curr_time - prev_time[prev_num]);
		double prev_x = prev_xx[prev_num];
		double prev_y = prev_yy[prev_num];

		nav_msgs::Odometry odom;
		odom.header.stamp = ros::Time::now();
		odom.header.frame_id = "odom";
		odom.child_frame_id = "base_footprint";
		for(int i=0; i<36; i++){
			odom.pose.covariance[i] = pose_in.pose.covariance[i];
			odom.twist.covariance[i] = 0;
		}

		odom.pose.pose.position.x = curr_x;
		odom.pose.pose.position.y = curr_y;
		odom.pose.pose.position.z = curr_z;

		odom.pose.pose.orientation.x = pose_in.pose.pose.orientation.x;
		odom.pose.pose.orientation.y = pose_in.pose.pose.orientation.y;
		odom.pose.pose.orientation.z = pose_in.pose.pose.orientation.z;
		odom.pose.pose.orientation.w = pose_in.pose.pose.orientation.w;

		odom.twist.twist.linear.x = (curr_x - prev_x) / dt;
		if(odom.twist.twist.linear.x > max_linear_x){
			odom.twist.twist.linear.x = 0;
		}
		if(odom.twist.twist.linear.x < - max_linear_x){
			odom.twist.twist.linear.x = 0;
		}

		odom.twist.twist.linear.y = (curr_y - prev_y) / dt;
		if(odom.twist.twist.linear.y > max_linear_y){
			odom.twist.twist.linear.y = 0;
		}
		if(odom.twist.twist.linear.y < - max_linear_y){
			odom.twist.twist.linear.y = 0;
		}
		//odom.twist.twist.linear.x = 0;
		//odom.twist.twist.linear.y = 0;
		odom.twist.twist.linear.z = (curr_z - prev_z) / dt;
/*
		if(curr_y-prev_y < 0.001 || curr_x-prev_x < 0.001){
			odom.twist.twist.angular.z = 0;
		}
		else{*/
			odom.twist.twist.angular.z = atan( (curr_y - prev_y) / (curr_x - prev_x) ) / dt ;
			if(odom.twist.twist.angular.z > max_angular_z){
				odom.twist.twist.angular.z = 0;
			}
			if(odom.twist.twist.angular.z < - max_angular_z){
				odom.twist.twist.angular.z = 0;
			}
		
		odom.twist.twist.angular.x = 0.0;
		odom.twist.twist.angular.y = 0.0;
/*
		odom.twist.twist.linear.x = 0;
		odom.twist.twist.linear.y = 0;
		odom.twist.twist.linear.z = 0;
		odom.twist.twist.angular.x = 0.0;
		odom.twist.twist.angular.y = 0.0;
		odom.twist.twist.angular.z = 0.0;*/

		/*if( !(vel_in.linear.x - cov_x <odom.twist.twist.linear.x < vel_in.linear.x + cov_x)){
			odom.twist.twist.linear.x = ( odom.twist.twist.linear.x + vel_in.linear.x) / 2;
		}
		/*
		if( !(vel_in.angular.z - cov_z <odom.twist.twist.angular.z < vel_in.angular.z + cov_z)){
			odom.twist.twist.angular.z = ( odom.twist.twist.angular.z + vel_in.angular.z) / 2;
		}*/
		if( (vel_in.angular.z ==0)){
			odom.twist.twist.angular.z = 0;
		}

		publisher_.publish(odom);

		prev_xx[prev_num] = curr_x;
		prev_yy[prev_num] = curr_y;
		prev_z = curr_z;
		prev_time[prev_num++] = curr_time;
		if(prev_num == 10)	prev_num = 0;

		vel_flag = false;
		pose_flag = false;

	}
}

int main(int argc, char** argv){
	ros::init(argc, argv, "chusa_odom");
	Chusa_Odom chusa_odom_node;
	ros::Rate r(10);
	while(ros::ok()){
		ros::spinOnce();
		r.sleep();
	}
	//ros::spin();

	return 0;
}
