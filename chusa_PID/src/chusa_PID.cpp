#include <ros/ros.h>
#include <chusa_PID/chusa_PID.h>

Chusa_PID::Chusa_PID(){
    bool init_result = init();
    ROS_ASSERT(init_result);
}

Chusa_PID::~Chusa_PID(){

}

auto Chusa_PID::min(auto a, auto b){
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}

auto Chusa_PID::max(auto a, auto b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

bool Chusa_PID::init(){
    publisher_ = nh_.advertise<chusa_msgs::Pwm>("pwm", 100);
    sub_vel = nh_.subscribe<geometry_msgs::Twist>("cmd_vel", 100, &Chusa_PID::msgCallback_vel, this);
    sub_odom = nh_.subscribe<nav_msgs::Odometry>("odom", 100, &Chusa_PID::msgCallback_odom, this);
    if(time_flag == false){
        time_flag = true;
        prev_time = curr_time = ros::Time::now();
    }
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
    odom_flag = true;

    current_vl = odom_in.twist.twist.linear.x + odom_in.twist.twist.angular.z * robot_radius;
    current_vr = odom_in.twist.twist.linear.x - odom_in.twist.twist.angular.z * robot_radius;

    if(vel_flag && odom_flag){
        PID();
    }
}

void Chusa_PID::PID(){

    chusa_msgs::Pwm pwm;

    curr_time = ros::Time::now();
    double dt = (curr_time - prev_time).toSec();

    for(int i=0; i<10; i++){
        error_l = desired_vl - current_vl;
        error_r = desired_vr - current_vr;

        double P_l = k_p * error_l;
        I_l += k_i * error_l * dt;
        double D_l = k_d * (error_l - prev_error_l) / dt;

        double P_r = k_p * error_r;
        I_r += k_i * error_r * dt;
        double D_r = k_d * (error_r - prev_error_r) / dt;

        output_pwm_l = vel2PWM(P_l + I_l + D_l);
        output_pwm_r = vel2PWM(P_r + I_r + D_r);

        pwm.left_pwm = max( min_pwm, min(output_pwm_l, max_pwm));
        pwm.right_pwm = max( min_pwm, min(output_pwm_r, max_pwm));

        publisher_.publish(pwm);
    }
    prev_time = curr_time;
    prev_error_l = error_l;
    prev_error_r = error_r;

    vel_flag = false;
    odom_flag = false;
}

int Chusa_PID::vel2PWM(double vel){
    return ( min_pwm + ( vel - min_vel ) / (max_vel - min_vel) * (max_pwm - min_pwm) );
}

int main(int argc, char** argv){

    ros::init(argc, argv, "chusa_PID");

    Chusa_PID chusa_PID_node;

    ros::spin();

    return 0;
}