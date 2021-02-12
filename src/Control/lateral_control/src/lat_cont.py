#!/usr/bin/env python3

import numpy as np
import rospy as ros

from sensor_msgs import Image
from geometry_msgs import Pose2D
from automotive_navigation_msgs import SteerWheel

class Lateral_Control():
    def __init__(self):
        # Create Controller Varaibles 
        self.autonomy = 0
        self.ϕ = 0


        # Create ROS Subscribers 
        self.state_sub = ros.Subscriber("Lat_Est/state_estimate",Pose2D,self.stateCB)
        self.feedback_sub = ros.Subscriber("LLC/feedback",*INSERT MESSAGE TYPE*,self.feedbackCB)

        # Create ROS Publishers
        self.steer_pub = ros.Publisher("Lat_Cont/steer",SteerWheel)
        self.steer_msg = SteerWheel

    def stateCB(self,msg):
        pass
    
    def feedbackCB(self,msg):
        pass
    
    def fill_message(self):
        self.steer_msg.mode = self.autonomy
        self.steer_msg.angle = self.ϕ
        self.steer_msg.angle_velocity = 0
    
    def publish(self):
        self.steer_pub.publish()
    
    def run(self):
        while not ros.is_shutdown():
            pass
    
if "__name__" == "__main__":
    ros.init_node("Lateral Control")
    Node = Lateral_Control()
    Node.run()