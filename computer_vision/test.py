import cv2

# cv2.namedWindow('image', cv2.WINDOW_NORMAL)
img  = cv2.imread("test.png", 0)
cv2.imshow("test.png", img)
cv2.waitKey(0)
cv2.destroyAllWindows()