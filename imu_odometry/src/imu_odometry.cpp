#include <imu_odometry/imu_odometry.h>

imu_odom::imu_odom(){
    bool init_result = init();
	ROS_ASSERT(init_result);
}

imu_odom::~imu_odom(){

}

bool imu_odom::init(){
	publisher_imu_vel = nh_.advertise<geometry_msgs::TwistStamped>("imu_vel", 1);
    publisher_imu_lpf = nh_.advertise<geometry_msgs::TwistStamped>("imu_lpf", 1);
	subscriber_imu = nh_.subscribe<sensor_msgs::Imu>("imu/data_lpf", 1, &imu_odom::imuMsgCallback, this);
    linear_velocity_x = linear_velocity_y = linear_velocity_z = 0;
	return true;
}

void imu_odom::imuMsgCallback(const sensor_msgs::Imu msg){
    
    if(!initialized){
        prev_time = curr_time = ros::Time::now().toSec();
        initialized = true;

    }
    else{
        curr_time = ros::Time::now().toSec();
        double a_x = floor(msg.linear_acceleration.x*100)/100;
        double a_y = floor(msg.linear_acceleration.y*100)/100;
        double a_z = floor(msg.linear_acceleration.z*100)/100;
        double r_x = floor(msg.angular_velocity.x*100)/100;
        double r_y = floor(msg.angular_velocity.y*100)/100;
        double r_z = floor(msg.angular_velocity.z*100)/100;
        double dt = curr_time - prev_time;

        linear_velocity_x += a_x * dt;
        linear_velocity_y += a_y * dt;
        linear_velocity_z += a_z * dt;

        imu_vel.twist.linear.x = linear_velocity_x;
        imu_vel.twist.linear.y = linear_velocity_y;
        imu_vel.twist.linear.z = linear_velocity_z;
        imu_vel.twist.angular.x = r_x;
        imu_vel.twist.angular.y = r_y;
        imu_vel.twist.angular.z = r_z;
        imu_vel.header.stamp = ros::Time::now();

        lpf_x = lpf_x + (low_factor * (imu_vel.twist.linear.x - lpf_x));

        imu_lpf.twist.linear.x = lpf_x;
        imu_lpf.header.stamp = ros::Time::now();

        publisher_imu_lpf.publish(imu_lpf);

        publisher_imu_vel.publish(imu_vel);
        prev_time = curr_time;
    }
}

int main(int argc, char** argv){
	ros::init(argc, argv, "imu_odometry_node");
	imu_odom imu_odometry_node;
	ros::spin();

	return 0;
}