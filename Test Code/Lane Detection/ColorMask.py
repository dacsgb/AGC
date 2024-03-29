import cv2
import numpy as np

cap = cv2.VideoCapture(0)

while(1):

    _, frame = cap.read()
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # define range of white color in HSV
    # change it according to your need !
    # Bitwise-AND mask and original image
    res = cv2.bitwise_and(frame,frame, mask=cv2.inRange(hsv, np.array([0,0,200]), np.array([255,55,255])))

    cv2.imshow('res',res)

    k = cv2.waitKey(5) & 0xFF
    if k == 27:
        break

cv2.destroyAllWindows()