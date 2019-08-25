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
	publisher_ = nh_.advertise<nav_msgs::Odometry>("odom", 100);
	subscriber_ = nh_.subscribe<geometry_msgs::PoseWithCovarianceStamped>("pose_with_covariance_stamped", 100, &Chusa_Odom::msgCallback, this);
	return true;
}

void Chusa_Odom::msgCallback(const geometry_msgs::PoseWithCovarianceStamped pose_in){
	if(flags == false){
		prev_x = curr_x = pose_in.pose.pose.position.x;
		prev_y = curr_y = pose_in.pose.pose.position.y;
		prev_z = curr_z = 0.0;
		
		prev_time = curr_time = ros::Time::now();
		flags = true;
	}
	else{
		curr_time = ros::Time::now();
		curr_x = pose_in.pose.pose.position.x;
		curr_y = pose_in.pose.pose.position.y;
		curr_z = 0.0;

		double dt = (curr_time - prev_time).toSec();

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
		odom.twist.twist.linear.y = (curr_y - prev_y) / dt;
		odom.twist.twist.linear.z = (curr_z - prev_z) / dt;

		if(curr_y-prev_y < 0.001 || curr_x-prev_x < 0.001){
			odom.twist.twist.angular.z = 0;
		}
		else{
			odom.twist.twist.angular.z = atan( (curr_y - prev_y) / ((curr_x - prev_x)) ) / dt ;
		}
		odom.twist.twist.angular.x = 0.0;
		odom.twist.twist.angular.y = 0.0;

		publisher_.publish(odom);

		prev_x = curr_x;
		prev_y = curr_y;
		prev_z = curr_z;
		
		prev_time = curr_time;

	}
}

int main(int argc, char** argv){
	ros::init(argc, argv, "chusa_odom");

	Chusa_Odom chusa_odom_node;

	ros::spin();

	return 0;
}
