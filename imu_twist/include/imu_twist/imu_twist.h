#ifndef IMU_TWIST_H_
#define IMU_TWIST_H_

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Imu.h>
#include <math.h>

class imu_twist{
	public:
		imu_twist();
		~imu_twist();
		bool init();
	private:
		ros::NodeHandle nh_;
		ros::Publisher publisher_twist;
		ros::Subscriber subscriber_imu;
        ros::Subscriber subscriber_cmd;
        //ros::Subscriber subscriber_cmd_vel;
		void imuMsgCallback(const sensor_msgs::Imu msg);
        void cmdMsgCallback(const geometry_msgs::Twist msg);
        void pub();
        //void cmdVelMsgCallback(const geometry_msgs::Twist msg);
        bool initialized = false;
        double prev_time, curr_time;
        double linear_velocity_x = 0.0;
        double linear_velocity_y = 0.0;
        double linear_velocity_z = 0.0;
        double angular_velocity_x = 0.0;
        double angular_velocity_y = 0.0;
        double angular_velocity_z = 0.0;

        int cnt_cmd = 0;
        bool stop = false;
        

        bool imu_flag = false;
        bool cmd_flag = false;

		geometry_msgs::Twist twist_out;
};

#endif