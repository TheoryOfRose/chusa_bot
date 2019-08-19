#ifndef CHUSA_TF_H_
#define CHUSA_TF_H_

#include <ros/ros.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>

class Chusa_Tf{
    public:
        Chusa_Tf();
        ~Chusa_Tf();
        bool init();

    private:
        ros::NodeHandle nh_;
        ros::Publisher publisher_;
        ros::Subscriber sub_twist;
        ros::Subscriber sub_pose;
        void msgCallback_twist(const geometry_msgs::Twist twist_in);
        void msgCallback_pose(const geometry_msgs::PoseWithCovarianceStamped pose_in);
        void publish_ftn();
        
        bool flags_twist = false;
        bool flags_pose = false;

        double position_x = 0.0;
        double position_y = 0.0;
        double position_z = 0.0;
        
        double orientation_x = 0.0;
        double orientation_y = 0.0;
        double orientation_z = 0.0;
        double orientation_w = 0.0;

        double covariance[36];

        double linear_x = 0.0;
        double linear_y = 0.0;
        double linear_z = 0.0;

        double angular_x = 0.0;
        double angular_y = 0.0;
        double angular_z = 0.0;


};

#endif
