#!/usr/bin/env python3

import numpy as np

import rospy
from sensor_msgs.msg import LaserScan, Range

class Node():
    def __init__(self,y_bounds):

        self.y_bounds = y_bounds

        self.laser_sub = rospy.Subscriber('/scan',LaserScan,self.laser_cb)
        self.data_polar = None
        self.data_xy = None
        self.inc = None
        self.θ_bounds = np.empty(2)

    def laser_cb(self,msg):
        self.data_polar = np.asarray(msg.ranges)
        self.inc = msg.angle_increment
        self.θ_bounds = np.array([msg.angle_min, msg.angle_max])
        self.data_xy = np.empty((len(self.data_polar,2)))

    def inbounds(self,point):
        if (self.y_bounds[0] <= point[1] <= self.y_bounds[1]):
            return True
        else:
            return False

    def run(self):
        while not rospy.is_shutdown():

            for i in range(len(self.data_xy)):
                θ = self.θ_bounds[0] + i*self.inc
                self.data_xy[i] = [self.data_polar[i]*np.cos(θ),self.data_polar[i]*np.sin(θ)]
            
            self.points = filter(self.inbounds,self.data_xy)

            self.range = min(self.points)


if __name__ == "__main__":
    rospy.init_node('lane_range_estimator')

    y_bounds = [rospy.get_param('~y_min'), rospy.get_param('~y_max')]

    Est = Node(y_bounds)
    Est.run()