#include <imu_twist/imu_twist.h>

imu_twist::imu_twist(){
    bool init_result = init();
	ROS_ASSERT(init_result);
}

imu_twist::~imu_twist(){

}

bool imu_twist::init(){
	publisher_twist = nh_.advertise<geometry_msgs::Twist>("Twist", 1);
    subscriber_cmd = nh_.subscribe<geometry_msgs::Twist>("cmd_vel", 1, &imu_twist::cmdMsgCallback, this);
	subscriber_imu = nh_.subscribe<sensor_msgs::Imu>("imu/data_bpf", 1, &imu_twist::imuMsgCallback, this);
    linear_velocity_x = linear_velocity_y = linear_velocity_z = 0;
	return true;
}

void imu_twist::cmdMsgCallback(const geometry_msgs::Twist msg){
    cmd_flag = true;
    if(msg.linear.x == 0 && msg.angular.z == 0){
        cnt_cmd++;
        if(cnt_cmd==10){
            stop = true;
            cnt_cmd = 0;
        }
    }
    if(cmd_flag && imu_flag){
        pub();
    }
}

void imu_twist::imuMsgCallback(const sensor_msgs::Imu msg){
    imu_flag = true;
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

        if( -0.01 < a_x < 0.01){
            a_x = 0;
        }
        if( -0.01 < a_y < 0.01){
            a_y = 0;
        }
        if( -0.1 < r_z < 0.1){
            r_z = 0;
        }

        linear_velocity_x += a_x * dt;
        linear_velocity_y += a_y * dt;
        linear_velocity_z += a_z * dt;
        angular_velocity_x = r_x;
        angular_velocity_y = r_y;
        angular_velocity_z = r_z;

        if(cmd_flag && imu_flag){
            pub();
        }
        prev_time = curr_time;
    }
}

void imu_twist::pub(){
    if(stop==true){
        twist_out.linear.x = 0;
        twist_out.linear.y = 0;
        twist_out.linear.z = 0;
        twist_out.angular.x = 0;
        twist_out.angular.y = 0;
        twist_out.angular.z = 0;
    }
    else{
        twist_out.linear.x = linear_velocity_x;
        twist_out.linear.y = linear_velocity_y;
        twist_out.linear.z = linear_velocity_z;
        twist_out.angular.x = angular_velocity_x;
        twist_out.angular.y = angular_velocity_y;
        twist_out.angular.z = angular_velocity_z;
    }
    
    publisher_twist.publish(twist_out);
    stop = false;
    cmd_flag = false;
    imu_flag = false;

}

int main(int argc, char** argv){
	ros::init(argc, argv, "imu_twist_node");
	imu_twist imu_twist_node;
	ros::spin();

	return 0;
}