<<<<<< HEAD
Arduino Upload
$arduino --upload name.ino
$sudo chmod 666 /dev/ttyACM0
$rosrun rosserial_python serial_node.py _port:=/dev/ttyACM0 _baud:=57600
=======
ssh
https://askubuntu.com/questions/600584/error-could-not-load-host-key-when-trying-to-recreate-ssh-host-keys
https://yeopbox.com/%EC%9A%B0%EB%B6%84%ED%88%AC-%EB%A9%94%EC%9D%B4%ED%8A%B8-16-04-lts-ssh-%EC%9B%90%EA%B2%A9-%EC%A0%9C%EC%96%B4%EB%A5%BC-%EC%9C%84%ED%95%9C-%EC%84%A4%EC%A0%95%ED%95%98%EA%B8%B0/
>>>>>>> f067fee5a04d55da518d4f92ccc2d11dc4654e92

sudo apt-get install ros-melodic-octomap ros-melodic-octomap-mapping ros-melodic-octomap-msgs ros-melodic-octomap-ros ros-melodic-octomap-rviz-plugins ros-melodic-octomap-server

https://m.blog.naver.com/PostView.nhn?blogId=khsuniv201&logNo=221014021629&proxyReferer=https%3A%2F%2Fwww.google.com%2F'

https://www.intorobotics.com/installing-ros-melodic-on-raspberry-pi-3b-running-ubuntu-mate-18-04-2-bionic/
http://wiki.ros.org/melodic/Installation/Ubuntu
http://wiki.ros.org/rplidar

https://m.blog.naver.com/PostView.nhn?blogId=thumbdown&logNo=220385363246&proxyReferer=https%3A%2F%2Fwww.google.com%2F

//raspi setting

https://m.blog.naver.com/elepartsblog/221171496379
makeshare.org/bbs/board.php?bo_table=raspberrypi&wr_id=73


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


=============================================================================================
=============================================================================================

1. Install ROS in Ubuntu 18.04 

http://wiki.ros.org/melodic/Installation/Ubuntu

ROS Tutorials

http://wiki.ros.org/ROS/Tutorials

** Use Catkin

2. Tutorial for RPLidar

$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/
$ catkin_make

Follow this url : https://m.blog.naver.com/PostView.nhn?blogId=thumbdown&logNo=220385363246&proxyReferer=https%3A%2F%2Fwww.google.com%2F

$ source devel/setup.bash

이후 센서 구동 및 모니터링


qt4-qmake :

Try installing libqt4-dev to install the Qt4 development files.

=================================================
rosserial 사용
systemctl stop ModemManager.service
