#!/usr/bin/python3

import numpy as np

import rospy
import rosnode

from agc.msgs import AGC
from std_msgs.msg import String

def Supervisor():
    def __init__(self):

        self.ϕ = 0.0
        self.v = np.array([0.0,0.0])

        self.nodes = rosnode.get_node_names()
        self.rate = rospy.Rate(20)

        self.laneTrackingSub = rospy.Subscriber("\laneTracking\cmd",AGC,self.laneTrackingCB)
        self.accSub = rospy.Subscriber("\acc\cmd",AGC,self.accCB)

        self.supervisorPub = rospy.Publisher("\supervisor\cmd",AGC,queue_size=1)
        self.ttsPub = rospy.Publisher("\supervisor\tts",String,queue_size=1)
        self.tts = String()

    def laneTrackingCB(self,msg):
        self.ϕ = msg.steering_angle
        self.v[0] = msg.speed

    def accCB(self,msg):
        self.v[1] = msg.speed

    def cmd_publish(self):
        cmd = AGC()
        cmd.autonomous = False
        cmd.speed = np.min(self.v)
        cmd.steering_angle = self.ϕ
        self.supervisorPub.publish(cmd)
    
    def tts_publish(self,text):
        tts = String()
        tts.data = text
        self.ttsPub.publish(tts)

    def run(self):
        self.tts_publish("Supervisor online")
        while not rospy.is_shutdown():
            self.cmd_publish()
            self.rate.sleep()
        self.tts_publish("Supervisor offline")

if __name__ == "__main__":
    rospy.init_node("agc_supervisor")
    Node = Supervisor()
    Node.run()