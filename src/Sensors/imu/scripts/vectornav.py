#!/usr/bin/env python3

import rospy
import numpy as np
import pymap3d as pm
from vnpy import *
from geometry_msgs.msg import Accel,Point
from sensor_msgs.msg import NavSatFix

# Initialize Sensor
Sen = VnSensor() # VS CODE HIGHLIGHTS THE CLASS BUT CODE WORKS
Sen.connect('/dev/ttyUSB0',115200)
print('Connected')

# Referene Coordinates
Ref = np.array([36.123456,-97.06981,0])

class Sensor(object):

    def __init__(self):
        print("started")

        self.attitude = Point()
        self.accelerations = Accel()
        self.gps = NavSatFix()
        self.ned = Point()

        # Create ROS Pubs
        self.att_pub = rospy.Publisher('/attitude', Point, queue_size=1)
        self.acc_pub = rospy.Publisher('/accelerations', Accel, queue_size=1)
        self.gps_pub = rospy.Publisher('/gps', NavSatFix, queue_size=1)
        self.ned_pub = rospy.Publisher('/NED_pos', Point, queue_size=1)

    def run(self):
        rate = rospy.Rate(10)
        while not rospy.is_shutdown():
            
            # Recieve Sensor Data
            data = Sen.read_ins_solution_lla()
            acc = Sen.read_acceleration_measurements()

            # Publish Attitude data
            self.attitude.x = data.yawPitchRoll.x
            self.attitude.y = data.yawPitchRoll.y
            self.attitude.z = data.yawPitchRoll.z
            self.att_pub.publish(self.attitude)

            # Get and Publish Acceleration data
            self.accelerations.linear.x = acc.x
            self.accelerations.linear.y = acc.y
            self.accelerations.linear.z = acc.z
            self.acc_pub.publish(self.accelerations)

            # Get and Publish GPS data
            self.gps.latitude = data.position.x
            self.gps.longitude = data.position.y
            self.gps.altitude = data.position.z
            self.gps_pub.publish(self.gps)
            
            # Get and Publish NED Coordinates
            ned = pm.geodetic2ned(self.gps.latitude,self.gps.longitude,self.gps.altitude,Ref[0],Ref[1],Ref[2],deg=True)
            self.ned.x = ned[0]
            self.ned.y = ned[1]
            self.ned.z = ned[2]
            self.ned_pub.publish(self.ned)

            print(Sen.is_connected)

            rate.sleep()

if __name__ == "__main__":
    rospy.init_node('imu_gps')
    node = Sensor()
    node.run()
