#ifndef CHUSA_ODOM_H_
#define CHUSA_ODOM_H_

#include <ros/ros.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>

class Chusa_Odom{
	public:
		Chusa_Odom();
		~Chusa_Odom();
		bool init();
	private:
		ros::NodeHandle nh_;
		ros::Publisher publisher_;
		ros::Subscriber subscriber_pose;
		ros::Subscriber subscriber_vel;
		void cb1(const geometry_msgs::PoseWithCovarianceStamped msg);
		void cb2(const geometry_msgs::Twist msg);
		void msgCallback();

		bool flags = false;
		double curr_time;
		double prev_time[10];
		int prev_num = 0;

		double prev_xx[10] = {0.0};
		double prev_yy[10] = {0.0};
		double prev_z = 0.0;
		double prev_theta = 0.0;

		double curr_x = 0.0;
		double curr_y = 0.0;
		double curr_z = 0.0;
		double curr_theta = 0.0;

		double position_x = 0.0;
		double position_y = 0.0;
		double position_z = 0.0;

		double orientation_x = 0.0;
		double orientation_y = 0.0;
		double orientation_z = 0.0;
		double orientation_w = 0.0;

		double linear_x = 0.0;
		double linear_y = 0.0;
		double linear_z = 0.0;

		double angular_x = 0.0;
		double angular_y = 0.0;
		double angular_z = 0.0;

		double covariance[36];

		bool vel_flag = false;
		bool pose_flag = false;
		double cov_x = 0.005;
		double cov_z = 0.05;

		geometry_msgs::PoseWithCovarianceStamped pose_in;
		geometry_msgs::Twist vel_in;
};

#endif
