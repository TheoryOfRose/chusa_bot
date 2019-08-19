#include <ros/ros.h>
#include <chusa_tf/chusa_tf.h>

Chusa_Tf::Chusa_Tf(){
    bool init_result = init();
    ROS_ASSERT(init_result);
}

Chusa_Tf::~Chusa_Tf(){

}

bool Chusa_Tf::init(){
    publisher_ = nh_.advertise<nav_msgs::Odometry>("chusa_tf", 100);
    sub_twist = nh_.subscribe<geometry_msgs::Twist>("chusa_twist", 100, &Chusa_Tf::msgCallback_twist, this);
    sub_pose = nh_.subscribe<geometry_msgs::PoseWithCovarianceStamped>("robot_pose_ekf/odom_combined", 100, &Chusa_Tf::msgCallback_pose, this);
    return true;
}


void Chusa_Tf::publish_ftn(){

    nav_msgs::Odometry odom;

    odom.pose.pose.position.x = position_x;
    odom.pose.pose.position.y = position_y;
    odom.pose.pose.position.z = position_z;

    odom.pose.pose.orientation.x = orientation_x;
    odom.pose.pose.orientation.y = orientation_y;
    odom.pose.pose.orientation.z = orientation_z;
    odom.pose.pose.orientation.w = orientation_w;

    //odom.pose.covariance = covariance;

    odom.twist.twist.linear.x = linear_x;
    odom.twist.twist.linear.y = linear_y;
    odom.twist.twist.linear.z = linear_z;

    odom.twist.twist.angular.x = angular_x;
    odom.twist.twist.angular.y = angular_y;
    odom.twist.twist.angular.z = angular_z;

    //odom.twist.covariance = covariance;

    for(int i=0; i<36; i++){
	    odom.pose.covariance[i] = odom.twist.covariance[i] = covariance[i];
    }
    publisher_.publish(odom);

    flags_twist = flags_pose = false;

}

void Chusa_Tf::msgCallback_twist(const geometry_msgs::Twist twist_in){
    flags_twist = true;

    linear_x = twist_in.linear.x;
    linear_y = twist_in.linear.y;
    linear_z = twist_in.linear.z;

    angular_x = twist_in.angular.x;
    angular_y = twist_in.angular.y;
    angular_z = twist_in.angular.z;

    if(flags_twist && flags_pose){
        // call function
        publish_ftn();
    }
}

void Chusa_Tf::msgCallback_pose(const geometry_msgs::PoseWithCovarianceStamped pose_in){
    flags_pose = true;

    position_x = pose_in.pose.pose.position.x;
    position_y = pose_in.pose.pose.position.y;
    position_z = pose_in.pose.pose.position.z;

    orientation_x = pose_in.pose.pose.orientation.x;
    orientation_y = pose_in.pose.pose.orientation.y;
    orientation_z = pose_in.pose.pose.orientation.z;
    orientation_w = pose_in.pose.pose.orientation.w;
    
    for(int i=0; i<36; i++){
	    covariance[i] = pose_in.pose.covariance[i];
    }
    //covariance = pose_in.pose.covariance;

    if(flags_twist && flags_pose){
        // call funciton
        publish_ftn();
    }
}


int main(int argc, char** argv){
    ros::init(argc, argv, "chusa_tf");

    Chusa_Tf chusa_tf_node;

    ros::spin();

    return 0;
}
