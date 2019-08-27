#include <ros.h>
#include <Arduino.h>
#include <ArduinoHardware.h>
#include <math.h>
#include <chusa_msgs/Pwm.h>

#define R_PWM 3
#define R_FORW 4
#define R_BACK 2
#define L_PWM 9
#define L_FORW 8
#define L_BACK 7
#define MAX_PWM 255
#define MIN_PWM 0

// functions
void setupPins();
void stop();
int left = 0;
int right = 0;
void msgCallback(const chusa_msgs::Pwm &msg);

void setupPins(){
  pinMode(LED_BUILTIN, OUTPUT);
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
  digitalWrite(LED_BUILTIN, 0);
  digitalWrite(R_FORW, 0);
  digitalWrite(R_BACK, 0);
  digitalWrite(L_FORW, 0);
  digitalWrite(L_BACK, 0);
  analogWrite(R_PWM, 0);
  analogWrite(L_PWM, 0);
}

// message callback
void msgCallback(const chusa_msgs::Pwm& msg){
  
  bool left_for, right_for;
  if(msg.left_pwm > 0){
    left_for = true;
    if(msg.left_pwm < MAX_PWM){
      left = msg.left_pwm;
    }
    else{
      left = MAX_PWM;
    }
  }
  else{
    left_for = false;
    if(msg.left_pwm > - MAX_PWM){
      left = msg.left_pwm;
    }
    else{
      left = - MAX_PWM;
    }
  }
  if(msg.right_pwm > 0){
    right_for = true;
    if(msg.right_pwm < MAX_PWM){
      right = msg.right_pwm;
    }
    else{
      right = MAX_PWM;
    }
  }
  else{
    right_for = false;
    if(msg.right_pwm > - MAX_PWM){
      right = msg.right_pwm;
    }
    else{
      right = - MAX_PWM;
    }
  }

  if(left == 0 && right == 0){
    stop();
  }
  else{
    if(left_for){
      digitalWrite(L_FORW, HIGH);
      digitalWrite(L_BACK, LOW);
    }
    else{
      digitalWrite(L_FORW, LOW);
      digitalWrite(L_BACK, HIGH);
    }
    if(right_for){
      digitalWrite(R_FORW, HIGH);
      digitalWrite(R_BACK, LOW);
    }
    else{
      digitalWrite(R_FORW, LOW);
      digitalWrite(R_BACK, HIGH);
    }
    analogWrite(R_PWM, right);
    analogWrite(L_PWM, left);
  }
  
}


ros::NodeHandle nh;

ros::Subscriber<chusa_msgs::Pwm> sub("/pwm", &msgCallback );

void setup() {
  Serial.begin(57600);
  setupPins();
  nh.initNode();
  nh.subscribe(sub);
}

void loop() {
  nh.spinOnce();
  delay(10);
}
