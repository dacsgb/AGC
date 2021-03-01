# Standard imports
import cv2
import time
import numpy as np
import matplotlib.pyplot as plt
from numpy.lib.type_check import imag

# Read image
start = time.time()
im = cv2.imread("Test Code\\Range Detection\\unnamed.png")
grey = cv2.cvtColor(im,cv2.COLOR_RGB2GRAY)

#plt.imshow(grey)
#plt.show()

# Apply Canny 
edges = cv2.Canny(grey, 20, 100)
cv2.imwrite("Test Code\\Range Detection\\edges.png",edges)
#plt.imshow(edges) 
#plt.show()

# Create and apply mask
ROI = np.zeros_like(grey)
w,h = 100,100
polygons = np.array([[(grey.shape[1]/2 - w,grey.shape[0]/2 - h),
                        (grey.shape[1]/2 - w,grey.shape[0]/2 + h),
                        (grey.shape[1]/2 + w,grey.shape[0]/2 + h),
                        (grey.shape[1]/2 + w,grey.shape[0]/2 - h)]])
cv2.fillPoly(ROI,polygons.astype(int),255)
masked = cv2.bitwise_and(edges,ROI)
cv2.imwrite("Test Code\\Range Detection\\masked.png",masked)
#plt.imshow(masked) 
#plt.show()


contours, hierarchy = cv2.findContours(masked ,cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE) 
#print("Number of Contours found = " + str(len(contours))) 

avg = []
for c in contours:
    avg.append(np.average(c,axis=0))

# Draw all contours 
# -1 signifies drawing all contours 
cv2.drawContours(im, contours, -1, (0,255,0), 3)
cv2.imwrite("Test Code\\Range Detection\\contours.png",im)

for p in avg:
    im = cv2.circle(im, (int(p[0][0]),int(p[0][1])), radius=5, color=[255,0,0], thickness=-1)
#plt.imshow(im) 
#plt.show()
cv2.imwrite("Test Code\\Range Detection\\results.png",im)
print(1/(time.time() - start))