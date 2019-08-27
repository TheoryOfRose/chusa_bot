#ifndef IMU_ODOMETRY_H_
#define IMU_ODOMETRY_H_

#include <ros/ros.h>
#include <geometry_msgs/TwistStamped.h>
#include <sensor_msgs/Imu.h>
#include <math.h>

class imu_odom{
	public:
		imu_odom();
		~imu_odom();
		bool init();
	private:
		ros::NodeHandle nh_;
		ros::Publisher publisher_imu_vel;
        ros::Publisher publisher_imu_lpf;
		ros::Subscriber subscriber_imu;
        //ros::Subscriber subscriber_cmd_vel;
		void imuMsgCallback(const sensor_msgs::Imu msg);
        //void cmdVelMsgCallback(const geometry_msgs::Twist msg);
        bool initialized = false;
        double prev_time, curr_time;
        double linear_velocity_x, linear_velocity_y, linear_velocity_z;

        double low_factor = 0.5;
        double lpf_x = 0;

		geometry_msgs::TwistStamped imu_vel;
        geometry_msgs::TwistStamped imu_lpf;
};

#endif