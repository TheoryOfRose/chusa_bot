https://m.blog.naver.com/PostView.nhn?blogId=khsuniv201&logNo=221014021629&proxyReferer=https%3A%2F%2Fwww.google.com%2F'


# Autonomous-Navigating-and-2D-Mapping-Robot
Autonomous Navigating and 2D Mapping Robot using RC car

<<<<<<< HEAD
We use Soundwave Sensor as a radar.

We use Servo Motor to circulate a Soundwave Sensor.

Connect Arduino with Soundwave sensor & Servo Motor

Arduino will transfer distance data to Raspberry Pi.

Raspberry pi accept the data and Mapping on own coordinate.

=======
1. How to connect Raspberry Pi

sudo apt-get install minicom
minicom -b 115200 -D /dev/ttyUSB0

id : pi
pw : raspberry


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

