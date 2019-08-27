#ifndef IMU_ODOM_H_
#define IMU_ODOM_H_

#include <ros/ros.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>

class imu_odom{
	public:
		imu_odom();
		~imu_odom();
		bool init();
	private:
		ros::NodeHandle nh_;
		ros::Publisher publisher_;
		ros::Subscriber subscriber_pose;
		ros::Subscriber subscriber_twist;
		void poseCallback(const geometry_msgs::PoseWithCovarianceStamped msg);
		void twistCallback(const geometry_msgs::Twist msg);
		void msgCallback();

		bool initialized = false;
		bool twist_flag = false;
		bool pose_flag = false;

		geometry_msgs::PoseWithCovarianceStamped pose_in;
		geometry_msgs::Twist twist_in;
};

#endif
