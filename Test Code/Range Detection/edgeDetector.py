import cv2
import numpy as np 
import matplotlib.pyplot as plt    

def canny_edge_detector(image):

    # Conver the image color to grayscale
    gray_image = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)

    # Reduce noise from the image
    blur = cv2.GaussianBlur(gray_image, (5, 5), 0)
    canny = cv2.Canny(blur, 50, 150)
    return gray_image, blur, canny 

path = "Lane.png"
src = cv2.imread(path)

grey, blur, canny = canny_edge_detector(src)
cv2.imwrite("grey.png", grey)
cv2.imwrite("blurred.png",blur)
cv2.imwrite("canny.png", canny)