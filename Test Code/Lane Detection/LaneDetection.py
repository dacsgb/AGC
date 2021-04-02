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
        lines = cv2.HoughLines(img, 2, np.pi/180, 100)
        if lines is not None:
            for ρ, θ in lines[0]:
                if θ < 0:
                    left.append([ρ, θ])
                else:
                    right.append([ρ, θ])
            
            left_avg = np.average(left,axis=0)
            right_avg = np.average(right,axis=0)

            if (left_avg == np.nan):
                left_avg = None
            
            if (right_avg == np.nan):
                right_avg = None

            return [left_avg, right_avg]
        else:
            return None

    def fuse(self,imgs,lanes,error):
        res = imgs[0]
        for img in imgs:
            res = cv2.bitwise_or(res,img)
        return res

    def error(self,dim,lanes):
        x = np.array([])

        for lane in lanes:
            if lane is not None:
                for l in lane:
                    if l is not None:
                        for ρ, θ in l:
                            x = np.append(x, (ρ - dim[0]*np.sin(θ))/np.cos(θ))

        return (dim[1] - np.average(x))

    def run(self,src):
        while True:
            processed = []
            lanes = []

            _, frame = src.read()
            for i, masks in enumerate(self.masksBounds):
                processed.append(self.masking(frame,masks))

            for i, img in enumerate(processed):
                lanes.append(self.lanes(cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)))  

            err = self.error(processed[0].shape,lanes)

            fused = self.fuse(processed,lanes,err)
            cv2.imshow("Final",fused)

            if cv2.waitKey(1) & 0xFF == ord('q'):
                    break

        src.release()
        cv2.destroyAllWindows()
            
    def make_points(self,image, line):
        slope, intercept = line
        y1 = int(image.shape[0])# bottom of the image
        y2 = int(y1*3/5)         # slightly lower than the middle
        x1 = int((y1 - intercept)/slope)
        x2 = int((y2 - intercept)/slope)
        return [[x1, y1, x2, y2]]

    def average_slope_intercept(self,image, lines):
        left_fit    = []
        right_fit   = []
        if lines is None:
            return [left_fit,right_fit]
        for line in lines:
            for x1, y1, x2, y2 in line:
                fit = np.polyfit((x1,x2), (y1,y2), 1)
                slope = fit[0]
                intercept = fit[1]
                if slope < 0: # y is reversed in image
                    left_fit.append((slope, intercept))
                else:
                    right_fit.append((slope, intercept))
        # add more weight to longer lines
        left_fit_average  = np.average(left_fit, axis=0)
        right_fit_average = np.average(right_fit, axis=0)
        left_line  = make_points(image, left_fit_average)
        right_line = make_points(image, right_fit_average)
        return [left_line, right_line]

    def canny(self,img):
        blur = cv2.GaussianBlur(cv2.cvtColor(img, cv2.COLOR_BGR2GRAY), (5, 5), 0)
        canny = cv2.Canny(blur, 50, 150)
        return canny

    def display_lines(self,img,lines):
        line_image = np.zeros_like(img)
        if lines is not None:
            for line in lines:
                for x1, y1, x2, y2 in line:
                    cv2.line(line_image,(x1,y1),(x2,y2),(255,0,0),10)
        return line_image

    def region_of_interest(self,canny):
        height, width = canny.shape
        mask = np.zeros_like(canny)

        triangle = np.array([[(0, height),(int(1.5*width / 4), int(height / 4)),(int(2.5*width / 4), int(height / 4)),(width, height),]], np.int32)

        cv2.fillPoly(mask, triangle, 255)
        masked_image = cv2.bitwise_and(canny, mask)

        return masked_image

    def detectLanes(self):
        cap = cv2.VideoCapture(0)

        while(cap.isOpened()):
            ret, frame = cap.read()
            canny_image = self.canny(frame)
            cropped_canny = self.region_of_interest(canny_image)
            lines = cv2.HoughLinesP(cropped_canny, 2, np.pi/180, 100, np.array([]), minLineLength=40,maxLineGap=5)
            try:
                averaged_lines = self.average_slope_intercept(frame, lines)
                line_image = self.display_lines(frame, averaged_lines)
                combo_image = cv2.addWeighted(frame, 0.8, line_image, 1, 1)
                cv2.imshow('frame', cropped_canny)
                if cv2.waitKey(1) & 0xFF == ord('q'):
                    break
            except:
                pass
        
        cap.release()
        cv2.destroyAllWindows()
    


if __name__ == "__main__":

    camera = cv2.VideoCapture(0)

    Node = LaneDetector()
    Node.run(camera)
