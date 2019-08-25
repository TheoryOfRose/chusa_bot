#include <ros/ros.h>
#include <chusa_PID/chusa_PID.h>

Chusa_PID::Chusa_PID(){
    bool init_result = init();
    ROS_ASSER(init_result);
}

Chusa_PID::~Chusa_PID(){

}

bool Chusa_PID::init(){
    publisher_ = nh_.advertise<chusa_msgs::Pwm>("pwm", 100);
    sub_vel = nh_.subscribe<geometry_msgs::Twist>("cmd_vel", 100, &Chusa_PID::msgCallback_vel, this);
    sub_odom = nh_.subscribe<nav_msgs::Odometry>("odom", 100, &Chusa_PID::msgCallback_odom, this);
    return true;
}

void Chusa_PID::msgCallback_vel(const geometry_msgs::Twist twist_in){
    vel_flag = true;

    desired_vl = twist_in.linear.x + twist_in.angular.z * robot_radius;
    desired_vr = twist_in.linear.x - twist_in.angular.z * robot_radius;

    if(vel_flag && odom_flag){
        PID();
    }
}

void Chusa_PID::msgCallback_odom(const nav_msgs::Odometry odom_in){
    vel_odom = true;

    current_vl = odom_in.twist.twist.linear.x + odom_in.twist.twist.angular.z * robor_radius;
    current_vr = odom_in.twist.twist.linear.x - odom_in.twist.twist.angular.z * robot_radius;

    if(vel_flag && odom_flag){
        PID();
    }
}

void Chusa_PID::PID(){

    chusa_msgs::Pwm pwm;

    pwm.left_pwm = min( vel2pwm(desired_vl), max_pwm ) + output_pwm_l;
    pwm.right_pwm = min( vel2pwm(desired_vr), max_pwm ) + output_pwm_r;

    publisher_.publish(pwm);

    curr_time = ros::Time::now();
    double dt = (curr_time - prev_time).toSec();

    error_l = desired_vl - current_vl;
    error_r = desired_vr - current_vr;

    double P_l = k_p * error_l;
    double I_l = k_i * error_l * dt;
    double D_l = k_d * (error_l - prev_error_l) / dt;

    double P_r = k_p * error_r;
    double I_r = k_i * error_r * dt;
    double D_r = k_d * (error_r - prev_error_r) / dt;

    output_pwm_l = vel2pwm(P_l + I_l + D_l);
    output_pwm_r = vel2pwm(P_r + I_r + D_r);

    prev_time = curr_time;
    prev_error_l = error_l;
    prev_error_r = error_r;

    vel_flag = true;
    odom_flag = true;
}

double Chusa_PID::vel2PWM(double vel){
    return ( min_pwm + ( vel - min_vel ) / (max_vel - min_vel) * (max_pwm - min_pwm) );
}

int main(int argc, char** argv){
    if(time_flag == false){
        time_flag = true;
        prev_time = curr_time = ros::Time::now();
    }
    ros::init(argc, argv, "chusa_PID");

    Chusa_PID chusa_PID_node;

    ros::spin();

    return 0;
}