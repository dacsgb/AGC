#!/usr/bin/env python

import cv2
import numpy as np

import rospy
from sensor_msgs.msg import Image, CompressedImage
from cv_bridge import CvBridge, CvBridgeError


class Detector():
    def __init__(self):

        self.img_sub = rospy.Subscriber("/camera/original",Image,self.imgCB)
        self.fits = []
        
        self.colorMasks = np.array([[[0,0,200],[255,55,255]],
                                    [[22,93,0],[45,255,255]]])

        self.mapping = np.float32([[[175, 120],[465, 120],[640,280],[0, 280]],
                                    [[0, 0],[640, 0],[640, 280],[0, 280]]])

        self.M = cv2.getPerspectiveTransform(self.mapping[0], self.mapping[1])

        self.mtx = np.load("/home/pathplanning/Code/AGC/src/Perception/lane_detection/calibrations/results/mtx.npy")
        self.dist = np.load("/home/pathplanning/Code/AGC/src/Perception/lane_detection/calibrations/results/dist.npy")
        self.rvecs = np.load("/home/pathplanning/Code/AGC/src/Perception/lane_detection/calibrations/results/rvecs.npy")
        self.tvecs = np.load("/home/pathplanning/Code/AGC/src/Perception/lane_detection/calibrations/results/tvecs.npy")
        self.newcameramtx, roi = cv2.getOptimalNewCameraMatrix(self.mtx, self.dist, (640,480), 1, (640,480))
    
    def imgCB(self,msg):
        bridge = CvBridge()
        img = bridge.imgmsg_to_cv2(msg,desired_encoding="bgr8")
        undist = self.undistort(img)
        bev = self.BEV(undist)
        markers = self.markers(bev,self.colorMasks)
        self.display(undist,markers)
        self.fits = self.fit(markers)

        

    def undistort(self,img):
        return cv2.undistort(img, self.mtx, self.dist, None, self.newcameramtx)

    def BEV(self,img):
        return cv2.warpPerspective(img, self.M, (img.shape[1],img.shape[0]))

    def markers(self,img,masks):
        processed = []
        hsv = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
        for mask in masks:
            masked = cv2.bitwise_and(img,img,mask=cv2.inRange(hsv,np.array(mask[0]),np.array(mask[1])))
            processed.append(masked)
        return processed

    def fit(self,imgs):
        fits = []
        for img in imgs:
            points = np.argwhere(img > 120)
            try:
                fits.append(np.polyfit(points[:,0],points[:,1],2))
            except:
                fits.append([])

        return fits
        
    def draw_lanes(self,imgs,fits):
        for i, img in enumerate(imgs):
            x = np.arange(0,img.shape[0])
            p = np.poly1d(fits[i])
            y = p(x)
            for i in range(len(x)):
                img = cv2.circle(img,(int(y[i]),int(x[i])),radius=0,color=(255,0,0),thickness=-1)
        return imgs

    def display(self,original,imgs):
        res = imgs[0]
        for img in imgs:
            res = cv2.bitwise_or(res,img)
        cv2.imshow("Corrected",original)
        cv2.imshow("Final",res)

    def run(self): 
        rate = rospy.Rate(10)
        while not rospy.is_shutdown():
            print(self.fits)
            rate.sleep()


if __name__ == "__main__":
    rospy.init_node("lane_detector")

    Node = Detector()
    Node.run()