#include <ros/ros.h>
#include <chusa_msgs/TfFromTilt.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
    
    ros::init(argc, argv, "tilt_lidar_node");
    ros::NodeHandle n;

    //ros::ServiceServer server = n.serviceServer<chusa_msgs::TfFromTilt>("tf_tilt");
    ros::Rate loop_rate(1);

    tf::TransformBroadcaster br;
    tf::Transform transform;
/*
    while (node.ok()){
        transform.setOrigin( tf::Vector3(0.0, 0.0, 0.0) );
        transform.setRotation( tf::Quaternion(0, 0, 0, 1) );
        br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "map", "base_footprint"));
        rate.sleep();
    }*/

    while(ros::ok()){
        
        ros::spinOnce();
        loop_rate.sleep();
    }
    
    return 0;
}