import numpy as np
import matplotlib.pyplot as plt
import cv2

class LaneDetector():
    def __init__(self):

        self.masksBounds = np.array([[[0,0,200],[255,55,255]],
                                    [[22,93,0],[45,255,255]]])

        self.ROI =  np.array([200,400])

    def masking(self,img,mask):
        hsv = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)
        masked =  cv2.bitwise_and(img,img,mask=cv2.inRange(hsv,np.array(mask[0]),np.array(mask[1])))
        return masked[self.ROI[0]:self.ROI[1],:]

    def lanes(self,img):
        left = []
        right = []
        lines = cv2.HoughLinesP(img, 2, np.pi/180, 100)
        if lines is not None:
            for x1, y1, x2, y2 in lines[0]:
                if (y2-y1)/(x2-x1) >= 0:
                    left.append([x1,y1,x2,y2])
                else:
                    right.append([x1,y1,x2,y2])
            return [np.average(left,axis=0), np.average(right,axis=0)]
        else:
            return [None, None]

    def fuse(self,imgs,lanes):
        res = imgs[0]
        for img in imgs:
            res = cv2.bitwise_or(res,img)

        for side in lanes:
            for line in side:
                if np.size(line) > 1:
                    cv2.line(res,(int(line[0]),int(line[1])),(int(line[2]),int(line[3])),(255,0,0),thickness=3)
        return res

    def run(self,src):
        while True:
            processed = []
            lanes = []

            _, frame = src.read()
            for i, masks in enumerate(self.masksBounds):
                processed.append(self.masking(frame,masks))

            for i, img in enumerate(processed):
                lanes.append(self.lanes(cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)))

            fused = self.fuse(processed,lanes)
            cv2.imshow("Final",fused)

            if cv2.waitKey(1) & 0xFF == ord('q'):
                    break

        src.release()
        cv2.destroyAllWindows()

if __name__ == "__main__":

    camera = cv2.VideoCapture(0)

    Node = LaneDetector()
    Node.run(camera)
