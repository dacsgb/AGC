#!/usr/bin/python3

import numpy as np
from numpy.lib.function_base import angle
import rospy

from sensor_msgs.msg import Range, LaserScan

class Estimator():
    def __init__(self) -> None:
        
        self.scan_sub = rospy.Subscriber("/",LaserScan,self.scan_cb)
        self.scan_data = LaserScan()

        self.roi = np.array([-2,2])

        self.range_pub = rospy.Publisher("/Est/range",Range,queue_size=1)
        self.rate = rospy.Rate(20)

    def scan_cb(self,msg):
        self.scan_data.angle_min = msg.angle_min
        self.scan_data.angle_max = msg.angle_max
        self.scan_data.angle_increment = msg.angle_increment
        self.scan_data.range_min = msg.range_min
        self.scan_data.ranges = np.array(msg.ranges)
    
    def convert(self,data):
        converted = np.zeros_like((len(data.ranges),2))
        for i, ρ in enumerate(data.ranges):
            θ = data.angle_min +i*data.angle_increment
            converted[i] = [(ρ*np.cos(θ),ρ*np.sin(θ))]
        return converted
    
    def masking(self,data,roi):
        pass

    def ranging(self,points):
        range_msg = Range()
        #self.range_msg.header = rospy.Header()
        range_msg.radiation_type = 1
        range_msg.field_of_view = np.abs(self.scan_data.angle_min) + np.abs(self.scan_data.angle_max)
        range_msg.min_range = self.scan_data.range_min
        range_msg.max_range = self.scan_data.range_max
        range_msg.range = np.min(points,axis=0)[0]
        
        self.range_pub.publish(range_msg)
    
    def run(self):
        while not rospy.is_shutdown():
            xy_data = self.convert(self.data)
            obs_pos = self.masking(xy_data,self.roi)
            self.rate.sleep()

if __name__ == "__main__":
    rospy.init_node("range_est")
    Node = Estimator()
    Node.run()