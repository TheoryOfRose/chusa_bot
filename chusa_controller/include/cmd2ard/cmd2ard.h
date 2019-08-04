#ifndef CMD2ARD_H_
#define CMD2ARD_H_

#include <ros/ros.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Twist.h>

#define robot_w 100

class Cmd2Ard{

public:
    Cmd2Ard();
    ~Cmd2Ard();
    bool init();

private:
    ros::NodeHandle nh_;
    ros::Publisher publisher_;
    ros::Subscriber subscriber_;
    void msgCallback(const geometry_msgs::Twist cmd_vel_in);    
};

#endif
