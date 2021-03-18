#!/usr/bin/env python3

import numpy as np
import cv2
import PySpin

import rospy
from sensor_msgs.msg import Image, CompressedImage
from cv_bridge import CvBridge, CvBridgeError

class Node():
    def __init__(self):

        self.image_pub = rospy.Publisher("/pointgrey/original",Image,queue_size=1)
        self.compressed_pub = rospy.Publisher("/pointgrey/compressed",CompressedImage,queue_size=1)
        self.comp_img = CompressedImage()

    def run(self):
        while not rospy.is_shutdown():
            pass

    

if __name__ == "__main__":
    rospy.init_node("pointgrey_camera")

    Camera = Node()
    Camera.run()