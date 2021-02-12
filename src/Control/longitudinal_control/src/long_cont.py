#!/usr/bin/env python3

import numpy as np
import rospy as ros

from sensor_msgs import Image, Range
from automotive_platform_msgs import GearCommand, SpeedMode, SteerWheel

class Longitudinal_Control():
    def __init__(self):
        # Create Control Variables
        self.autonomy = 0
        self.u = np.array([0.0,0.0])


        # Create ROS Subcribers
        self.dist_sub = ros.Subscriber("Long_Est/dist",Range,self.rangeCB)
        self.steer_sub = ros.Subscriber("Lat_Cont/steer",SteerWheel,self.steeringCB)
        self.feedback_sub = ros.Subscriber("LLC/feedback",*INSERT MESSAGE TYPE*,self.feedbackCB)

        # Create ROS Publishers
        self.gear_pub = ros.Publisher("Long_Cont/gear",GearCommand)
        self.gear_msg = GearCommand

        self.speed_pub = ros.Publisher("Long_Cont/speed",SpeedMode)
        self.speed_msg = SpeedMode

        self.steer_pub = ros.Publisher("Long_Cont/steer",SteerWheel)
        self.steer_msg = SteerWheel

    def rangeCB(self,msg):
        pass
    
    def feedbackCB(self,msg):
        pass

    def steeringCB(self,msg):
        pass
    
    def fill_message(self):
        self.gear_msg.command = np.sign()
        
        self.steer_msg.mode = self.autonomy
        self.steer_msg.angle = self.u[1]
        self.steer_msg.angle_velocity = 0

        self.speed_msg.mode = self.autonomy
        self.speed_msg.speed = self.u[0]
        self.speed_msg.acceleration_limit = 0
        self.speed_msg.deceleration_limit = 0


    def publish(self):
        self.gear_pub.publish()
        self.speed_pub.publish()
        self.steer_pub.publish()

    def run(self):
        while not ros.is_shutdown():
            pass
    
if "__name__" == "__main__":
    ros.init_node("Longitudinal Control")
    Node = Longitudinal_Control()
    Node.run()