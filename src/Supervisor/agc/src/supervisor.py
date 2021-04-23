#!/usr/bin/python3

import numpy as np

import rospy
from agc.msg import AGC, StampedFloat, Auto
from std_msgs.msg import String

class Supervisor():
    def __init__(self):

        self.ϕ = 0.0
        self.v = np.array([0.0,0.0,0.0])
        self.auto = True

        self.rate = rospy.Rate(50)

        self.dashSub = rospy.Subscriber("/HMI/dash_autonomy",Auto,self.dashCB)
        #self.joy_contSub = rospy.Subscriber("/CONT/joy_cmd",AGC,self.joyCB)
        self.laneTrackingSub = rospy.Subscriber("/CONT/lane_tracking/steering",StampedFloat,self.laneTrackingCB)
        self.accSub = rospy.Subscriber("/CONT/acc_cmd",AGC,self.accCB)

        self.supervisorPub = rospy.Publisher("/SUP/cmd",AGC,queue_size=1)
        self.ttsPub = rospy.Publisher("/SUP/tts",String,queue_size=1)
        self.ledPub = rospy.Publisher("SUP/led",String,queue_size=1)

    def dashCB(self,msg):
        pass

    def laneTrackingCB(self,msg):
        self.ϕ = msg.data

    def accCB(self,msg):
        self.v[1] = msg.speed
    
    def joyCB(self,msg):
        self.auto = msg.autonomous
        self.ϕ = msg.steering_angle
        self.v[2] = msg.speed

    def cmd_publish(self,auto,u):
        cmd = AGC()
        cmd.autonomous = auto
        cmd.speed = u[0]
        cmd.steering_angle = u[1]
        self.supervisorPub.publish(cmd)
    
    def tts_publish(self,text):
        tts = String()
        tts.data = text
        self.ttsPub.publish(tts)
    
    def led_publish(self,text):
        led = String()
        led.data = text
        self.ledPub.publish(led)

    def run(self):
        while not rospy.is_shutdown():
            self.cmd_publish(self.auto,[0,self.ϕ])
            self.rate.sleep()

if __name__ == "__main__":
    rospy.init_node("agc_supervisor")
    Node = Supervisor()
    Node.run()