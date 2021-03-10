#!/usr/bin/python3

import numpy as np

import rospy
from std_msgs.msg import Header
from automotive_platform_msgs.msg import Speed, SteeringCommand
from sensor_msgs.msg import Joy

class Converter():
    def __init__(self):
        self.rate = rospy.Rate(100)

        self.h = Header()

        self.speed_pub = rospy.Publisher("/CMD/speed",Speed,queue_size=1)
        self.speed_msg = Speed()
        self.speed_msg.acceleration_limit = 0
        self.speed_msg.deceleration_limit = 0

        self.steer_pub = rospy.Publisher("/CMD/steer",SteeringCommand,queue_size=1)
        self.steer_msg = SteeringCommand()

        self.joy_sub = rospy.Subscriber("/HMI/joystick",Joy,self.joy_cb)

    def joy_cb(self,msg):
        if abs(msg.axes[1]) >= 0.1:
            self.h.stamp = rospy.Time.now()
            self.speed_msg.header = self.h
            self.speed_msg.speed = -5*msg.axes[1]
        else:
            self.h.stamp = rospy.Time.now()
            self.speed_msg.header = self.h
            self.speed_msg.speed = 0

        if abs(msg.axes[3]) >= 0.1:
            self.h.stamp = rospy.Time.now()
            self.steer_msg.header = self.h
            self.steer_msg.steering_wheel_angle = np.deg2rad(30*msg.axes[3])
        else:
            self.h.stamp = rospy.Time.now()
            self.steer_msg.header = self.h
            self.steer_msg.steering_wheel_angle = 0

    def run(self):
        while not rospy.is_shutdown():
            self.speed_pub.publish(self.speed_msg)
            self.steer_pub.publish(self.steer_msg)
            self.rate.sleep()

if __name__ == "__main__":
    rospy.init_node("joystick_vel")
    Node = Converter()
    Node.run()