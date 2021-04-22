# using matplotlib and numpy 
import matplotlib.image as img 
import numpy as npy 
  
# reading image in variable m 
m = img.imread("Lenna.png") 
  
# determining dimesion of image width(w) height(h) 
w, h = m.shape[:2] 
  
# required image size after cropping 
xNew = int(w * 1 / 2) 
yNew = int(h * 1 / 2) 
newImage = npy.zeros([xNew, yNew, 3]) 
for i in range(int(w / 4), int(3 * w / 4)): 
    for j in range(int(h / 4),int(3*h / 4)):  
        newImage[i-int(w/4), j-int(h/4)]= m[i , j]   
# save image 
img.imsave('cropped_Lena.png', newImage) 
