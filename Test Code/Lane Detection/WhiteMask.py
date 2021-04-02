import cv2
import numpy as np

cap = cv2.VideoCapture(0)

while(1):

    _, frame = cap.read()
    HLS = cv2.cvtColor(frame, cv2.COLOR_BGR2HLS)

    Lchannel = HLS[:,:,1]

    mask = cv2.inRange(HLS, np.array([0,250,0]), np.array([255,255,255]))
    res = cv2.bitwise_and(frame, frame, mask = mask)

    cv2.imshow('frame', frame)
    cv2.imshow('res',res)

    # # define range of white color in HSV
    # # change it according to your need !
    # lower_white = np.array([0,0,200])
    # upper_white = np.array([255,55,255])

    # # Bitwise-AND mask and original image
    # res = cv2.bitwise_and(frame,frame, mask=cv2.inRange(hsv, lower_white, upper_white))

    # cv2.imshow('frame',frame)
    # cv2.imshow('res',res)

    k = cv2.waitKey(5) & 0xFF
    if k == 27:
        break

cv2.destroyAllWindows()