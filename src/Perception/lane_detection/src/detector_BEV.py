#!/usr/bin/env python3

import cv2
import numpy as np

class Detector():
    def __init__(self):
        
        self.colorMasks = np.array([[[0,0,200],[255,55,255]],
                                    [[22,93,0],[45,255,255]]])

        self.mapping = np.float32([[[258, 670],[590, 450],[690, 450],[1041, 670]],
                                    [[258, 720],[258, 0],[1041, 0],[1041, 720]]])
        self.M = cv2.getPerspectiveTransform(self.mapping[0], self.mapping[1])
    
    def undistort(self,img):
        return img #cv2.undistort(img, mtx, dist, None, newcameramtx)

    def BEV(self,img):
        return cv2.warpPerspective(img, self.M, (img.shape[0],img.shape[1]))

    def markers(self,img,masks):
        processed = []
        hsv = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
        for mask in masks:
            masked = cv2.bitwise_and(img,img,mask=cv2.inRange(hsv,np.array(mask[0]),np.array(mask[1])))
            processed.append(np.float32(masked[:,:,2]))
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
                img = cv2.circle(img,(int(y[i]),int(x[i])),radius=0,color=(255),thickness=-1)
        return imgs

    def display(self,original,imgs):
        res = imgs[0]
        for img in imgs:
            res = cv2.bitwise_or(res,img)
        cv2.imshow("Original",original)
        cv2.imshow("Final",res)

    def run(self,src):
        while(src.isOpened()):
            try:
                _ , frame = src.read()
            except:
                print("No frame read")
                continue

            undistorted = self.undistort(frame)
            bev = self.BEV(undistorted)
            markers = self.markers(bev,self.colorMasks)
            fits = self.fit(markers)
            results = self.draw_lanes(markers,fits)

            self.display(undistorted, results)

            if cv2.waitKey(1) & 0xFF == ord('q'):
                break

if __name__ == "__main__":
    video = cv2.VideoCapture('src/Perception/lane_detection/test_videos/project_video.mp4')
    Node = Detector()
    Node.run(video)