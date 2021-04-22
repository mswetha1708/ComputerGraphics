#Convert image
import numpy as np
import cv2
im= cv2.imread(r'picture.png')

#0 red,1,green 2,blue
f = (0.299 * im[:,:,0])+(0.587 * im[:,:,1] )+(0.144 * im[:,:,2])
rows=len(f)
col=len(f[0])
for x in range(0,rows):
	for y in range(0,col):
		oldpixel = f[x][y]
		newpixel=0
		if(oldpixel>127):
			f[x][y]= 255
			newpixel=255
		else :
			f[x][y]=0 
		quant_error = oldpixel - newpixel
		if(x+1!=rows):
			f[x + 1][y] = f[x + 1][y] + quant_error * 3 / 8
		if(y+1!=col):
			f[x][y + 1] = f[x][y + 1] + quant_error * 3 / 8
		if(x+1 != rows and y+1 !=col):
			f[x + 1][y + 1] = f[x + 1][y + 1] + quant_error * 2 / 8
cv2.imwrite('Q2.png',f)

