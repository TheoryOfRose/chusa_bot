
#include <ros.h>


#include <math.h>
#include <geometry_msgs/Twist.h>

#define PWM_MIN 0
#define PWM_MAX 250
#define VEL_MAX 10
#define R_PWM 9
#define R_FORW 8
#define R_BACK 7
#define L_PWM 3
#define L_FORW 2
#define L_BACK 4



// functions
void setupPins();
void stop();
bool rosConnected();
void msgCallback(const geometry_msgs::Twist &msg);
float vel2PWM(float x);

float k= 20.0;
ros::NodeHandle nh;
ros::Subscriber<geometry_msgs::Twist> sub("/cmd_vel", msgCallback );


void setupPins()
{
  pinMode(R_PWM, OUTPUT);
  pinMode(R_FORW, OUTPUT);
  pinMode(R_BACK, OUTPUT);
  pinMode(L_PWM, OUTPUT);
  pinMode(L_FORW, OUTPUT);
  pinMode(L_BACK, OUTPUT);
  stop();
}

void stop()
{
  digitalWrite(R_FORW, 0);
  digitalWrite(R_BACK, 0);
  digitalWrite(L_FORW, 0);
  digitalWrite(L_BACK, 0);
  analogWrite(R_PWM, 0);
  analogWrite(L_PWM, 0);
}

void msgCallback(const geometry_msgs::Twist& msg)
{
    Serial.println(msg.linear.x);
    Serial.println(msg.angular.z);

    // float x = max(min(msg.linear.x, 1.0f), -1.0f);
    float x;
    if(msg.linear.x < 1.0f){
      if(msg.linear.x < -1.0f){
        x = -1.0f;
      }
      else{
        x = msg.linear.x;
      }
    }
    else{
      x = 1.0f;
    }
    
    // float z = max(min(msg.angular.z, 1.0f), -1.0f);
    float z;
    if(msg.angular.z < 1.0f){
      if(msg.angular.z < -1.0f){
        z = -1.0f;
      }
      else{
        z = msg.angular.z;
      }
    }
    else{
      z = 1.0f;
    }
    
    float v_r = 0; 
    float v_l = 0; 
    float d_r = 0; 
    float d_l = 0; 
    float r_PWM = 0; 
    float l_PWM = 0;

    v_r = x + z * 0.125 / 2;
    v_l = x - z * 0.125 / 2;

    r_PWM = k*vel2PWM(fabs(v_r));
    l_PWM = k*vel2PWM(fabs(v_l));

    if(r_PWM > PWM_MAX){
      r_PWM = PWM_MAX;
    }
    if(l_PWM > PWM_MAX){
      l_PWM = PWM_MAX;
    }
    Serial.println(r_PWM);
    delay(100);
    
    if(v_l >= 0){
      digitalWrite(L_FORW, HIGH);
      digitalWrite(L_BACK, LOW);
    }
    else{
      digitalWrite(L_FORW, LOW);
      digitalWrite(L_BACK, HIGH);
    }
  
    if(v_r >= 0){
      digitalWrite(R_FORW, HIGH);
      digitalWrite(R_BACK, LOW);
    }
    else{
      digitalWrite(R_FORW, LOW);
      digitalWrite(R_BACK, HIGH);
    }
    analogWrite(R_PWM, r_PWM);
    analogWrite(L_PWM, l_PWM);
    
}

float vel2PWM(float x)
{
  if(x == 0){
    return 0;
  }
  return x * (PWM_MAX - PWM_MIN) + PWM_MIN;
}

void setup()
{
  
  Serial.begin(9600);
  setupPins();
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{
  if(!nh.connected()){
    stop();
  }
  nh.spinOnce();
}
