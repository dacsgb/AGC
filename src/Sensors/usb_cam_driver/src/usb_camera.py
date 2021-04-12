#!/usr/bin/env python3
import numpy as np

import rospy
import cv2
from sensor_msgs.msg import Image, CompressedImage
from cv_bridge import CvBridge, CvBridgeError


class Node():
    def __init__(self,topic_name):
        
        self.image_pub = rospy.Publisher(topic_name+"/original",Image,queue_size=1)
        self.compressed_pub = rospy.Publisher(topic_name+"/compressed",CompressedImage,queue_size=1)
        self.comp_img = CompressedImage()

    def run(self,src):
        rate = rospy.Rate(src.get(cv2.CAP_PROP_FPS))
        bridge = CvBridge()
        while not rospy.is_shutdown():
            success, frame = src.read()   
            if success:
                self.image_pub.publish(bridge.cv2_to_imgmsg(frame, encoding="bgr8"))
                self.compressed_pub.publish(bridge.cv2_to_compressed_imgmsg(frame))
            rate.sleep()
        src.release()
    
if __name__ == "__main__":
    rospy.init_node("usb_camera")

    camera = cv2.VideoCapture(rospy.get_param('~camera_num', 0))
    camera.set(cv2.CAP_PROP_FRAME_WIDTH, rospy.get_param('~width', camera.get(cv2.CAP_PROP_FRAME_WIDTH)))
    camera.set(cv2.CAP_PROP_FRAME_HEIGHT, rospy.get_param('~height', camera.get(cv2.CAP_PROP_FRAME_HEIGHT)))
    camera.set(cv2.CAP_PROP_FPS, rospy.get_param('~fps',30))
    
    topic_name = rospy.get_param("~topic_name","/usb_camera")

    Camera = Node(topic_name)
    Camera.run(camera)
