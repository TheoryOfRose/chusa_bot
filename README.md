# Autonomous-Navigating-and-2D-Mapping-Robot
Autonomous Navigating and 2D Mapping Robot using RC car

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

