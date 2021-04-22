import cv2
import numpy as np
def translate():
	img = cv2.imread('pic.jpg',0)
	rows,cols = img.shape
	M = np.float32([[1,0,100],[0,1,50]])
	dst = cv2.warpAffine(img,M,(cols,rows))
	cv2.imshow('img',dst)
	cv2.waitKey(0)
	cv2.destroyAllWindows()
def rotate():
	img = cv2.imread('pic.jpg',0)
	res = cv2.resize(img,None,fx=2, fy=2, interpolation = cv2.INTER_CUBIC)
	cv2.imshow('img',res)
	cv2.waitKey(0)
	cv2.destroyAllWindows()

def scale():
	img = cv2.imread('pic.jpg',0)
	rows,cols = img.shape
	M = cv2.getRotationMatrix2D((cols/2,rows/2),90,1)
	dst = cv2.warpAffine(img,M,(cols,rows))
	cv2.imshow('img',dst)
	cv2.waitKey(0)
	cv2.destroyAllWindows()

if __name__=="__main__": 
    translate()
    rotate()
    scale() 