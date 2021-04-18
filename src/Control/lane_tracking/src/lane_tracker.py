#!/usr/bin/env python3

import numpy as np

import rospy
from agc.msgs import StampedFloat, AGC

class Controller():
    def __init__(self,gains,bounds):
        
        self.err_sub = rospy.Subscriber("/PER/lane_detection/cross_error",StampedFloat,self.errCB)
        self.err = np.array([0.0,0.0])
        self.gains = np.array(gains)
        self.time = np.array([0.0,0.0])
        self.bounds = np.array(bounds)
        
        self.ϕ_pub = rospy.Publisher("/CONT/lane_tracking/steering",StampedFloat,queue_size=1)

    def errCB(self,msg)
        self.time[1] = msg.time.secs + msg.time.nsecs*1e-9
        self.err[1] = msg.data
        
    def run(self):
        msg = StampedFloat()
        rate = rospy.Rate(30)
        I = 0
        while not rospy.is_shutdown():

            dt = (self.time[1]-self.time[1])
            de = (self.err[1]-self.err[0])

            P = self.err[1]
            D = (de/dt)
            dI = np.average(self.err)*dt
            I += dI
            
            u = self.gains[0]*P + self.gains[1]*I + self.gains[2]*D
            
            if (self.bounds[1] < u < self.bounds[0]):
                I -= dI
            
            u = self.gains[0]*P + self.gains[1]*I + self.gains[2]*D
            
            msg.time = rospy.Time()
            msg.data = u
            self.ϕ_pub.publish(msg)
            rate.sleep()

if __name__ == "__main__":
    rospy.init_node("lane_tracker")
    
    Node = Controller()
    Node.run()