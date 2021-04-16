#!/usr/bin/env python

import cv2
import numpy as np

import rospy
from sensor_msgs.msg import Image, CompressedImage, CameraInfo
from cv_bridge import CvBridge, CvBridgeError


class Detector():
    def __init__(self,camera):

        if camera == None:
            print("No camera topic given")
            exit()
        

        self.img_sub = rospy.Subscriber("/{}/image_color".format(camera),Image,self.imgCB)
        self.cam_sub = rospy.Subscriber("/{}/camera_info".format(camera),CameraInfo,self.camCB)
        self.loaded = False

        self.fits = []

        self.colorMasks = np.array([[[0,0,200],[255,55,255]],
                                    [[22,93,0],[45,255,255]]])

        self.mapping = np.float32([[[175, 120],[465, 120],[640,280],[0, 280]],
                                    [[0, 0],[640, 0],[640, 280],[0, 280]]])


        self.M = cv2.getPerspectiveTransform(self.mapping[0], self.mapping[1])

    def camCB(self,msg):
        self.dist = np.array(msg.D)
        self.mtx = np.reshape(msg.K,(3,3))
        self.camMtx, self.roi = cv2.getOptimalNewCameraMatrix(self.mtx, self.dist, (msg.width, msg.height), 1,(msg.width, msg.height))

    def imgCB(self,msg):
        bridge = CvBridge()
        img = bridge.imgmsg_to_cv2(msg,desired_encoding="bgr8")
        undist = self.undistort(img)
        bev = self.BEV(undist)
        markers = self.markers(bev,self.colorMasks)
        self.fits = self.fit(markers)
        predict = self.draw_lanes(markers,self.fits)
        self.display(undist,bev,predict)
        

    def undistort(self,img):
        return cv2.undistort(img, self.mtx, self.dist, None, self.camMtx)[self.roi[1]:self.roi[1]+self.roi[3], self.roi[0]:self.roi[0]+self.roi[2]]

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

    def display(self,original,bev,imgs):
        for i, img in enumerate(imgs):
            cv2.imshow("Prediction: {}".format(i),img)
        cv2.imshow("Undistorted",original)
        cv2.imshow("BEV",bev)
        cv2.waitKey(3)

    def run(self): 
        rate = rospy.Rate(60)
        while not rospy.is_shutdown():
            print(self.fits)
            
            rate.sleep()


if __name__ == "__main__":
    rospy.init_node("lane_detector")
    
    camera = rospy.get_param("~camera", default=None)

    Node = Detector(camera)
    Node.run()