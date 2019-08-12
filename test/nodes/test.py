#!/usr/bin/env python
import roslib; roslib.load_manifest('test')
import rospy
from sensor_msgs.msg import Imu
def talker():
    #pub = rospy.Publisher('chatter', String)
    pub = rospy.Publisher('imu', Imu)
    rospy.init_node('talker')
    msg = Imu()
    msg.orientation_covariance = [1.0, 2.0, 3.0, 4.0, 5.0, 4.0, 3.0, 2.0, 1.0]
    while not rospy.is_shutdown():
        pub.publish(msg)
        rospy.sleep(1.0)
if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException: pass
