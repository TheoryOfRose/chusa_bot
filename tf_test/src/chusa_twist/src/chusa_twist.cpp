#include <ros/ros.h>
#include <chusa_twist/chusa_twist.h>


// Constructor
Chusa_Twist::Chusa_Twist(){
    bool init_result = init();
    ROS_ASSERT(init_result);
}

// Destructor
Chusa_Twist::~Chusa_Twist(){

}

bool Chusa_Twist::init(){
    publisher_ = nh_.advertise<geometry_msgs::Twist>("chusa_twist", 100);
    subscriber_ = nh_.subscribe<sensor_msgs::Imu>("imu", 100, &Chusa_Twist::msgCallback, this);
    return true;
}

void Chusa_Twist::msgCallback(const sensor_msgs::Imu imu_in){

    if(flags==0){
        flags=1;
        time_prev = time_curr = ros::Time::now();
        ax_prev = ax_curr = imu_in.linear_acceleration.x;
        ay_prev = ay_curr = imu_in.linear_acceleration.y;
        az_prev = az_curr = imu_in.linear_acceleration.z;
    }

    time_curr = ros::Time::now();
    ax_curr = imu_in.linear_acceleration.x;
    ay_curr = imu_in.linear_acceleration.y;
    az_curr = imu_in.linear_acceleration.z;

    double dt = (time_curr - time_prev).toSec();

    geometry_msgs::Twist tw;

    tw.linear.x += ( ax_prev + ax_curr ) * dt / 2;
    tw.linear.y += ( ay_prev + ay_curr ) * dt / 2;
    tw.linear.z += ( az_prev + az_curr ) * dt / 2;

    tw.angular.x = imu_in.angular_velocity.x;
    tw.angular.y = imu_in.angular_velocity.y;
    tw.angular.z = imu_in.angular_velocity.z;

    publisher_.publish(tw);

    ax_prev = ax_curr;
    ay_prev = ay_curr;
    az_prev = az_curr;

    time_prev = time_curr;
}

int main(int argc, char** argv){
    ros::init(argc, argv, "chusa_twist");

    Chusa_Twist chusa_twist_node;

    ros::spin();

    return 0;
}