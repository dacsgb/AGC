#!/usr/bin/python2

import numpy as np
import rospy 
import tf2_ros
import tf_conversions

from automotive_platform_msgs.msg import Speed, SteeringCommand
from geometry_msgs.msg import TransformStamped
from tf2_msgs.msg import TFMessage

class Particle():
    def __init__(self,x,y):
        self.x = np.array([x,y,0.0])
        self.xdot = np.array([0.0,0.0,0.0])
        self.L = 1.69
        self.size = 2

    def kinematics(self,u):
        self.xdot[0] = u[0]*np.cos(self.x[2])
        self.xdot[1] = u[0]*np.sin(self.x[2])
        self.xdot[2] = u[0]*np.tan(u[1])/self.L

    def update(self,u,f):
        self.kinematics(u)
        self.x[0] = self.x[0] + self.xdot[0]/f
        self.x[1] = self.x[1] + self.xdot[1]/f
        self.x[2] = self.x[2] + self.xdot[2]/f

class Sim():
    def __init__(self):

        #Cart Variables
        self.cart = Particle(0,0)
        self.u = np.array([0.0,0.0])

        #ROS Setup
        self.f = 30
        self.steer_sub = rospy.Subscriber("/CMD/steer",SteeringCommand,self.steer_cb)
        self.speed_sub = rospy.Subscriber("/CMD/speed",Speed,self.speed_cb)
        self.pub_tf = rospy.Publisher("/tf", TFMessage, queue_size=1)
        self.rate = rospy.Rate(self.f)

    def steer_cb(self,msg):
        self.u[1] = msg.steering_wheel_angle

    def speed_cb(self,msg):
        self.u[0] = msg.speed

    def pose_handler(self):
        t = TransformStamped()

        t.header.stamp = rospy.Time.now()
        t.header.frame_id = "world"
        t.child_frame_id = "base"

        t.transform.translation.x = self.cart.x[0]
        t.transform.translation.y = self.cart.x[1]
        t.transform.translation.z = 0
        q = tf_conversions.transformations.quaternion_from_euler(0, 0, self.cart.x[2])
        t.transform.rotation.x = q[0]
        t.transform.rotation.y = q[1]
        t.transform.rotation.z = q[2]
        t.transform.rotation.w = q[3]

        br = tf2_ros.TransformBroadcaster()
        br.sendTransform(t)

    def run(self):
        while not rospy.is_shutdown():
            self.cart.update(self.u,self.f)
            self.pose_handler()
            self.rate.sleep()

if __name__ == "__main__":
    rospy.init_node("Simulator")
    Node = Sim()
    Node.run()
