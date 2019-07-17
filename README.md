https://m.blog.naver.com/PostView.nhn?blogId=khsuniv201&logNo=221014021629&proxyReferer=https%3A%2F%2Fwww.google.com%2F'

https://www.intorobotics.com/installing-ros-melodic-on-raspberry-pi-3b-running-ubuntu-mate-18-04-2-bionic/
http://wiki.ros.org/melodic/Installation/Ubuntu

# Autonomous-Navigating-and-2D-Mapping-Robot
Autonomous Navigating and 2D Mapping Robot using RC car

360 Degree Laser Scanner Development Kit - RPLIDAR A1M8 [DFR0315]

Ubuntu MATE 18.04 LTS + ROS Melodic

=======
1. How to connect Raspberry Pi

sudo apt-get install minicom
minicom -b 115200 -D /dev/ttyUSB0

id : pi
pw : 000000


--------------------------------------
sudo raspi-config
wifi
SSID :  NAME
PW : PW

--------------------------------------
SSH Connecting

ifconfig -> get ip of raspberry pi

ssh pi@pi_ip


2. How to use GPIO in C++
https://nickcullen.net/blog/raspberry-pi-tutorials/compiling-linking-wiringpi/
>>>>>>> 3513c57fe4647d35afeafdd4e61887d3c2fc0e43

