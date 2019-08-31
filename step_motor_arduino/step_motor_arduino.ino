#include <ros.h>
#include <ros/time.h>
#include <Arduino.h>
#include <chusa_msgs/Step.h>
#include <geometry_msgs/TwistStamped.h>

const int left_dir = 2;
const int left_step = 3;
const int right_dir = 4;
const int right_step = 5;
const int enable = 7;
const float loop_delay = 0.1 * 1000 / 45; // delay (ms)

#define LOOP 44
#define ROBOT_WIDTH 0.16

// declaration of functions
void setupPins();
void msgCallback(const chusa_msgs::Step& msg);

geometry_msgs::TwistStamped twist_msg;
ros::NodeHandle nh_;
ros::Subscriber<chusa_msgs::Step> sub("/step_motor", &msgCallback);
ros::Publisher pub("wheel_odom", &twist_msg);
//ros::Rate r(10);

void setupPins(){
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(left_dir, OUTPUT);
  pinMode(left_step, OUTPUT);
  pinMode(right_dir, OUTPUT);
  pinMode(right_step, OUTPUT);
  pinMode(enable, OUTPUT);
}

void start_motor(){
  digitalWrite(enable, LOW);
}

void stop_motor(){
  digitalWrite(left_dir, LOW);
  digitalWrite(left_step, LOW);
  digitalWrite(right_dir, LOW);
  digitalWrite(right_step, LOW);
  digitalWrite(enable, HIGH);
}

void msgCallback(const chusa_msgs::Step& msg){
  digitalWrite(LED_BUILTIN, 0);
  int mod_left = floor(LOOP / msg.left_tick);
  int mod_right = floor(LOOP / msg.right_tick);

  digitalWrite(left_dir, msg.left_direction);
  digitalWrite(right_dir, !msg.right_direction);

  if(msg.left_tick == 0 && msg.right_tick == 0){
    stop_motor();
    delay(100);
    start_motor();
  }
  else{
    for(int i=0; i< LOOP; i++){
      
      if(i % mod_left == 0){
        digitalWrite(left_step, LOW);
      }
      else{
        digitalWrite(left_step, HIGH);
      }
  
      if(i % mod_right == 0){
        digitalWrite(right_step, LOW);
      }
      else{
        digitalWrite(right_step, HIGH);
      }
  
      //delay
      delay(loop_delay);
    }
  }

  // publish

  double v_x = ( ( double(msg.left_tick) / 100.0 + double(msg.right_tick) / 100.0 ) / 2.0 );
  double v_z = ( double( msg.right_tick - msg.left_tick ) / 16.0 );

  twist_msg.header.stamp = nh_.now();
  twist_msg.twist.linear.x = v_x;
  twist_msg.twist.linear.y = 0;
  twist_msg.twist.linear.z = 0;
  twist_msg.twist.angular.x = 0;
  twist_msg.twist.angular.y = 0;
  twist_msg.twist.angular.z = v_z;

  pub.publish( &twist_msg );
}

void setup(){
  Serial.begin(57600);
  setupPins();
  stop_motor();
  start_motor();
  nh_.initNode();
  nh_.subscribe(sub);
  nh_.advertise(pub);
}

void loop(){
  nh_.spinOnce();
}
