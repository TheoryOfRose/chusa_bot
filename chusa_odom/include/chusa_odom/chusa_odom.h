#ifndef CHUSA_ODOM_H_
#define CHUSA_ODOM_H_

#include <ros/ros.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <nav_msgs/Odometry.h>

class Chusa_Odom{
	public:
		Chusa_Odom();
		~Chusa_Odom();
		bool init();
	private:
		ros::NodeHandle nh_;
		ros::Publisher publisher_;
		ros::Subscriber subscriber_;
		void msgCallback(const geometry_msgs::PoseWithCovarianceStamped pose_in);

		bool flags = false;
		ros::Time prev_time, curr_time;

		double prev_x = 0.0;
		double prev_y = 0.0;
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
};

#endif
