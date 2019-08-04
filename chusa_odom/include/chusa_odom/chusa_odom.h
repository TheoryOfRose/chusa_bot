#ifndef CHUSA_ODOM_H_
#define CHUSA_ODOM_H_

#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <geometry_msgs/Twist.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>

#define W_PI 3.14159

class chusa_odom{

public:
    chusa_odom();
    ~chusa_odom();
    bool init();

private:
    ros::NodeHandle nh_;
    ros::Publisher publisher_;
    ros::Subscriber subscriber_;
    void msgCallback(const geometry_msgs::Twist cmd_vel_in);    
};

#endif
