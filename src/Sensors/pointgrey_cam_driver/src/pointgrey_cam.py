#!/usr/bin/env python3

import numpy as np
import cv2
import PySpin

import rospy
from sensor_msgs.msg import Image, CompressedImage
from cv_bridge import CvBridge, CvBridgeError

class Node():
    def __init__(self,serialNumber):

        self.cam = self.getCamera(serialNumber)
        self.nodemap_tldevice = self.cam.GetTLDeviceNodeMap()
        self.cam.Init()
        self.nodemap = self.cam.GetNodeMap()
        self.

        self.image_pub = rospy.Publisher("/pointgrey/original",Image,queue_size=1)
        self.compressed_pub = rospy.Publisher("/pointgrey/compressed",CompressedImage,queue_size=1)
        self.comp_img = CompressedImage()
    
    def getCamera(serialNumber):
        system = PySpin.System.GetInstance()
        cam_list = system.GetCamera()
        cam_size = cam_list.GetSize()
        
        if cam_size == 0:
            print("No camera Found")
            exit
        
        for i in range(cam_size):
            cam = cam_list.GetByIndex(i)
            if cam.TLDevice.DeviceSerialNumber.GetAccessMode() == PySpin.RO:
               if (cam.TLDevice.DeviceSerialNumber.ToString() == serialNumber):
                   return cam
        
    def run(self):
        self.cam.BeginAcquisition()

        while not rospy.is_shutdown():
            image = self.cam.GetNextImage()
            if image.IsIncomplete():
                pass
            result =  image.Convert(PySpin.PixelFormat_Mono8, PySpin.HQ_LINEAR)
            cv2.imshow("Camera",result)
            image.Release()
        self.cam.EndAcquisition()


if __name__ == "__main__":
    rospy.init_node("pointgrey_camera")
    serial = rospy.get_param("~serial_number")

    Camera = Node(serial)
    Camera.run()