#!/usr/bin/env python

import cv2
import numpy as np

import rospy
from agc.msgs import StampedFloat
from sensor_msgs.msg import Image, CompressedImage, CameraInfo
from cv_bridge import CvBridge, CvBridgeError


class Detector():
    def __init__(self,camera):

        if camera == None:
            print("No camera topic given")
            exit()

        self.img_sub = rospy.Subscriber("/{}/image_color".format(camera),Image,self.imgCB)
        self.cam_sub = rospy.Subscriber("/{}/camera_info".format(camera),CameraInfo,self.camCB)
        self.img = None
        
        self.err_pub = rospy.Publisher("/PER/lane_detection/cross_error",StampedFloat,queue_size=1)
        self.err = Float32

        self.colorMasks = np.array([[[0,0,200],[255,55,255]],
                                    [[22,93,0],[45,255,255]]])

    def camCB(self,msg):
        self.dist = np.array(msg.D)
        self.mtx = np.reshape(msg.K,(3,3))
        self.camMtx, self.roi = cv2.getOptimalNewCameraMatrix(self.mtx, self.dist, (msg.width, msg.height), 1,(msg.width, msg.height))

    def imgCB(self,msg):
        bridge = CvBridge()
        self.img = bridge.imgmsg_to_cv2(msg,desired_encoding="bgr8")

    def undistort(self,img):
        return cv2.undistort(img, self.mtx, self.dist, None, self.camMtx)[self.roi[1]:self.roi[1]+self.roi[3], self.roi[0]:self.roi[0]+self.roi[2]]

    def BEV(self,img):
        mapping = np.float32([[[18.34, 493.96],[163.41,426.91],[866.35,426.93],[965.41,493.32]],
                                [[0, img.shape[0]],[0, 0],[img.shape[1],0],[img.shape[1],img.shape[0]]]])
        M = cv2.getPerspectiveTransform(mapping[0], mapping[1])
        return cv2.warpPerspective(img, M, (img.shape[1],img.shape[0]))

    def markers(self,img,masks):
        hsv = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
        processed = [cv2.bitwise_and(img,img,mask=cv2.inRange(hsv,np.array(mask[0]),np.array(mask[1]))) for mask in masks]
        return processed

    def fit(self,imgs):
        fits = []
        for img in imgs:
            points = np.argwhere(img > 120)
            try:
                fits.append(np.poly1d(np.polyfit(points[:,0],points[:,1],2)))
            except:
                fits.append([])
        return fits

    def est(self,img,fit):
        h, w, c = img.shape
        est = [f(h) for f in fit]
        avg = np.average(est)
        return avg, w/2 - avg

    def draw_lanes(self,imgs,fits):
        for i, img in enumerate(imgs):
            x = np.arange(0,img.shape[0])
            p = np.poly1d(fits[i])
            y = p(x)
            for i in range(len(x)):
                img = cv2.circle(img,(int(y[i]),int(x[i])),radius=0,color=(255,0,0),thickness=-1)
        return imgs

    def display(self,original,bev,imgs,est):
        res = imgs[0]
        for i, img in enumerate(imgs):
            res = cv2.bitwise_or(res,img)
        cv2.circle(res,(int(est),res.shape[0]),3,(0,0,255),-1)
        cv2.line(res,(int(res.shape[1]/2),0),(int(res.shape[1]/2),res.shape[0]),(0,255,0),2 )
        cv2.imshow("Undistorted",original)
        cv2.imshow("BEV",bev)
        cv2.imshow("Masks",res)
        cv2.waitKey(3)

    def publishErr(self,err):
        msg = StampedFloat()
        msg.data = 3.048*err/1003
        msg.time = rospy.Time()

    def run(self): 
        rate = rospy.Rate(60)
        while not rospy.is_shutdown():
            if self.img is not None:

                undist = self.undistort(self.img)
                bev = self.BEV(undist)
                markers = self.markers(bev,self.colorMasks)
                fits = self.fit(markers)
                estimate, err = self.est(bev,fits)

                self.err_pub.publish(3.048*err/1003)

                predict = self.draw_lanes(markers,fits)
                self.display(undist,bev,predict,estimate)

            rate.sleep()

if __name__ == "__main__":
    rospy.init_node("lane_detector")
    
    camera = rospy.get_param("~camera", default=None)
    Node = Detector(camera)
    Node.run()