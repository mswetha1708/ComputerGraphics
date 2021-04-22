#Convert image
import numpy as np
import cv2
im= cv2.imread(r'picture.png')
#0 red,1,green 2,blue
f = (0.299 * im[:,:,0])+(0.587 * im[:,:,1] )+(0.144 * im[:,:,2])
cv2.imwrite(r'picture_grey.png',f)
rows=len(f);
col=len(f[0])
for i in range(0,rows):
	for j in range(0,col):
		if(f[i][j]<=127) :
			f[i][j]=0;
		else :
			f[i][j]=255;
cv2.imwrite(r'Q1.png',f)

