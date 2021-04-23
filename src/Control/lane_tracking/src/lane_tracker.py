#!/usr/bin/env python3

import numpy as np

import rospy
from agc.msg import StampedFloat, AGC

class Controller():
    def __init__(self,gains,bounds):
        
        self.err_sub = rospy.Subscriber("/PER/lane_detection/cross_error",StampedFloat,self.errCB)
        self.err = np.array([0.0,0.0])
        self.gains = np.array(gains)
        self.time = np.array([0.0,0.0])
        self.bounds = np.array(bounds)
        self.I = 0
        self.ϕ_pub = rospy.Publisher("/CONT/lane_tracking/steering",StampedFloat,queue_size=1)

    def errCB(self,msg):
        
        self.time[1] = msg.time.secs + msg.time.nsecs*1e-9
        self.err[1] = msg.data

        control = StampedFloat()

        dt = (self.time[1]-self.time[0])
        de = (self.err[1]-self.err[0])

        P = self.err[1]
        D = (de/dt)
        dI = np.average(self.err)*dt
        self.I += dI

        u = self.gains[0]*P + self.gains[1]*self.I + self.gains[2]*D

        if (self.bounds[1] < u < self.bounds[0]):
            self.I -= dI
            u = self.gains[0]*P + self.gains[1]*self.I + self.gains[2]*D

        self.err[0] = self.err[1]
        self.time[0] = self.time[1]

        control.time = rospy.Time()
        control.data = u
        self.ϕ_pub.publish(control)
        
    def run(self):
        rate = rospy.Rate(30)
        while not rospy.is_shutdown():
            rate.sleep()

if __name__ == "__main__":
    rospy.init_node("lane_tracker")
    
    Node = Controller([0.005,0,0],[-np.pi/6,np.pi/6])
    Node.run()#!/usr/bin/env python3

import numpy as np

import rospy
from agc.msg import StampedFloat, AGC

class Controller():
    def __init__(self,gains,bounds):
        
        self.err_sub = rospy.Subscriber("/PER/lane_detection/cross_error",StampedFloat,self.errCB)
        self.err = np.array([0.0,0.0])
        self.gains = np.array(gains)
        self.time = np.array([0.0,0.0])
        self.bounds = np.array(bounds)
        self.I = 0
        self.ϕ_pub = rospy.Publisher("/CONT/lane_tracking/steering",StampedFloat,queue_size=1)

    def errCB(self,msg):
        
        self.time[1] = msg.time.secs + msg.time.nsecs*1e-9
        self.err[1] = msg.data

        control = StampedFloat()

        dt = (self.time[1]-self.time[0])
        de = (self.err[1]-self.err[0])

        P = self.err[1]
        D = (de/dt)
        dI = np.average(self.err)*dt
        self.I += dI

        u = self.gains[0]*P + self.gains[1]*self.I + self.gains[2]*D

        if (self.bounds[1] < u < self.bounds[0]):
            self.I -= dI
            u = self.gains[0]*P + self.gains[1]*self.I + self.gains[2]*D

        self.err[0] = self.err[1]
        self.time[0] = self.time[1]

        control.time = rospy.Time()
        control.data = u
        self.ϕ_pub.publish(control)
        
    def run(self):
        rate = rospy.Rate(30)
        while not rospy.is_shutdown():
            rate.sleep()

if __name__ == "__main__":
    rospy.init_node("lane_tracker")
    
    Node = Controller([0.0015,0,0],[-np.pi/6,np.pi/6])
    Node.run()