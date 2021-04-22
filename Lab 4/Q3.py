import numpy as np
import cv2
im= cv2.imread(r'picture.png')
#0 red,1,green 2,blue
f = (0.299 * im[:,:,0])+(0.587 * im[:,:,1] )+(0.144 * im[:,:,2])
b1= cv2.imread(r'Q1.png')
b1=b1[:,:,0]
b2= cv2.imread(r'Q2.png')
b2=b2[:,:,0]
rows=len(f)
col=len(f[0])
e1=(0.299 * im[:,:,0])+(0.587 * im[:,:,1] )+(0.144 * im[:,:,2])
e2=(0.299 * im[:,:,0])+(0.587 * im[:,:,1] )+(0.144 * im[:,:,2])
count=0
t=0
direct =[[-1,0],[1,0],[1,1],[-1,1],[-1,1],[1,-1],[0,1],[0,-1]]
for x in range(0,rows):
	for y in range(0,col):
		count=0
		t1=0.0
		t2=0.0
		for r in range(0,8):
			if(x+direct[r][0]>=0 and x+direct[r][0]<rows and y+direct[r][1]>=0 and y+direct[r][1]<col):
				t1+=abs(f[x+direct[r][0]][y+direct[r][1]]- b1[x+direct[r][0]][y+direct[r][1]])
				t2+=abs(f[x+direct[r][0]][y+direct[r][1]]- b2[x+direct[r][0]][y+direct[r][1]])
				count=count+1
		e1[x][y]=t1/count
		e2[x][y]=(t2/count)
# sum1=sum2=0.0
# for x in range(0,rows):
# 	for y in range(0,col):
# 		sum1+=e1[x][y]
# 		sum2+=e2[x][y]
# print(sum1/rows*col),
# print(sum2/rows*col)
cv2.imwrite('Q1_error.png',e1)
cv2.imwrite('Q2_error.png',e2)