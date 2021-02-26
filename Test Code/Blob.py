# Standard imports
import cv2
import numpy as np
import matplotlib.pyplot as plt

# Read image
im = cv2.imread("Test Code/disparity.png",cv2.IMREAD_GRAYSCALE)



# Set up the detector with default parameters.
params_detector = cv2.SimpleBlobDetector_Params()
params_detector = cv2.SimpleBlobDetector_Params()
params_detector.filterByArea = True
params_detector.minArea = 500
params_detector.filterByCircularity = False
params_detector.minCircularity = 0.2
params_detector.filterByConvexity = False
params_detector.minConvexity = 0.2
params_detector.filterByInertia = True
params_detector.minInertiaRatio = 0.00
detector = cv2.SimpleBlobDetector_create(params_detector)

# Create mask
ROI = np.zeros_like(im)
polygons = np.array([[(1000,im.shape[0]),(1000,400),(2000,400),(2000,im.shape[0])]])
cv2.fillPoly(ROI,polygons,255)
masked = cv2.bitwise_and(im,ROI)

# Detect blobs.
keypoints = detector.detect(masked)
print("Keypoints Found")

# Draw detected blobs as red circles.
# cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS ensures the size of the circle corresponds to the size of blob
im_with_keypoints = cv2.drawKeypoints(masked, keypoints, np.array([]), (0,0,255), cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)

# Show keypoints
plt.imshow(im_with_keypoints)
plt.show()