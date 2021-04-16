#!/usr/bin/python3

import numpy as np

import rospy
from agc.msg import AGC
from sensor_msgs.msg import Joy

class Converter():
    def __init__(self):
        self.rate = rospy.Rate(100)

        self.joy_sub = rospy.Subscriber("/HMI/joystick",Joy,self.joy_cb)

        self.cmd_pub = rospy.Publisher("/CONT/joy_cmd",AGC,queue_size=1)
        self.agc = AGC()
        self.agc.autonomous = False
        self.last = [0,0]

    def joy_cb(self,msg):
        self.agc.header.stamp = rospy.Time.now()

        if msg.buttons[6] == 1:
            if (msg.header.seq - self.last[0] > 25 ):
                self.last = [msg.header.seq, msg.buttons[6]]
                self.agc.autonomous = not self.agc.autonomous

        if abs(msg.axes[1]) >= 0.1:
            self.agc.speed = -3*msg.axes[1]
        else:
            self.agc.speed = 0

        if abs(msg.axes[3]) >= 0.1:
            self.agc.steering_angle = -np.deg2rad(30*msg.axes[3])
        else:
            self.agc.steering_angle = 0

    def run(self):
        while not rospy.is_shutdown():
            self.cmd_pub.publish(self.agc)
            self.rate.sleep()

if __name__ == "__main__":
    rospy.init_node("joystick_vel")
    Node = Converter()
    Node.run()