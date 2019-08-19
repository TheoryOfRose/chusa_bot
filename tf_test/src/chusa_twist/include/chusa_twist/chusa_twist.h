#ifndef CHUSA_TWIST_H_
#define CHUSA_TWIST_H_

#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/Twist.h>

class Chusa_Twist{
	public:
		Chusa_Twist();
		~Chusa_Twist();
		bool init();

	private:
		ros::NodeHandle nh_;
		ros::Publisher publisher_;
		ros::Subscriber subscriber_;
		void msgCallback(const sensor_msgs::Imu imu_in);
		
		int flags = 0;

		double ax_prev, ay_prev, az_prev = 0.0;
		double ax_curr, ay_curr, az_curr = 0.0;

		ros::Time time_prev, time_curr;
};

#endif
