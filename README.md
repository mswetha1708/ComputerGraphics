# ComputerGraphics

This repository contains all programs implemented as a part of computer graphics lab course.
## Lab 1
1) Find if given point is inside figure.
2) Find if given point is inside line
3) Find if given point inside triangle.
4) Find minimum bounding rectangle of a given triangle.

## Lab 2
1) functions available in graphics.h, display the following
a. Point
b. Line
c. Circle
d. Ellipse
e. Triangle
f. Rectangle
Manu Driven C program, using switch-case, needs to be written to choose the option
of drawing above mentioned graphics primitives. Good modularity (separate
function for each graphics primitive) is required.
2) Draw triangle inscribed in a circle.
3) Draw a smiley:)

## Lab 3
Using OpenGL, draw the following figures. The dimensions of the various components in the figures
can be considered as you wish, but the overall shape should be the same as the figures given here
1. Draw House
2. Draw Car

## Lab 4
Objective: Simulation of Printing with and without Error Diffusion
Let P1 and P2 be two bi-level printers. Bi-level printers are the printers which will print only two
shades(black and white) even when the input image is colour or gray scale image.
The bi-level printer P1 prints the colour image as binary image using the following transformation :
1) Colour image is converted to gray scale using the formula : f ’(x,y) =
(0.299r(x,y)+0.587g(x,y)+0.114b(x,y)), where the input image f(x,y)=(r(x,y), g(x,y), b(x,y))
2) The gray scale image f’(x,y) is converted into binary image using thresholding, where the
threshold is 127 for the image with pixel range 0 to 255(ie. B1(x,y) =0 if f’(x,y)&lt;=127;
B1(x,y)=255 otherwise)
3) The resultant binary image B1(x,y) will be printed
Whereas the bi-level printer P2 prints the colour image as binary image using the following
transformation :
1) Colour image is converted to gray scale using the formula : f ’(x,y) =
(0.299r(x,y)+0.587g(x,y)+0.114b(x,y)), where the input image f(x,y)=(r(x,y), g(x,y), b(x,y))
2) Apply Floyd –Steinberg error diffusion algorithm on f’(x,y), say the resultant image is B2(x,y),
which is a binary image
a. The gray scale image f’(x,y) is converted into binary image using thresholding after
distributing error, where the threshold is 127 for the image with pixel range 0 to
255
3) The resultant binary image B2(x,y) will be printed (Note that B2(x,y) will be 0 or 255 for all
(x,y))
a) Simulate process of printing by printers P1 and P2 and display the final output of P1 and P2
in any language of your choice(Python, MATLAB, OpelGL) for the colour input lena image
given below.
b) Display f’(x,y) along with B1(x,y) and B2(x,y), and find out whether B1 is close to f’ or B2 is
close to f’
c) Print the local average absolute error between f’(x,y) and B1(x,y) and also between f’(x,y)
and B2(x,y). The local average absolute error for f’ and B1 is defined at each pixel (x,y) as
the average of absolute difference f’ and B1 in 3x3 window centred at (x,y). Similarly for
f’ and B2.
d) It is more complex to use OpenGL, hence you will be awarded extra credit if OpenGL is
used
In Floyd- Steinberg algorithm, You are expected to use three neighbours: for (x,y), consider (x+1,y),
(x+1, y+1), (x,y+1) with weights 3/8, 2/8,3/8 respectively. And also consider top-left corner as origin.

## Lab 5
1. Given the end points (x1, y1) and (x2, y2) of a line segment, find slope m, and y-intercept b.
Compute the value of y=mx+b for each integer value of x starting from x1 to x2 and plot
(round(x), round(y)) with the step size 5. Repeat the plotting for step size 4, step size 3, step
size 1. What do you observe on these 5 plots
a. When m&gt;1, check if your program works
b. When line segment is horizontal or vertical, check if your program works
2. Given the parameter of a and b of ellipse x= a cos(theta); y= b sin(theta), plot the points
(round(x), round(y)) for theta varies from 0 to 2*PI, with various step sizes and observe the
quality of the plot. Also check if circle is plotted when a=b.

## Lab 6
1. Implement DDA algorithm for drawing straight line and observe how the lines are drawn when
the slope is close to 0, and also when close to infinity
2. Implement Midpoint line drawing algorithm and display one line segment in each of the eight
octants

## Lab 7
1. Given the centre (a, b) and radius r, display circle( in red colour) cantered at (a, b) and with
radius r using midpoint circle drawing algorithm
2. Given the centre (h, k), a half length of major axis ‘a’ and a half length of minor axis ‘b’ , display
Ellipse(in Yellow colour) cantered at (h, k) and with major axis length 2a and minor axis length
2b using midpoint ellipse drawing algorithm

## Lab 8
1. Implement Boundary Fill algorithm(with 4 neighbours) to display boundary of one rectangle and one triangle
, given vertices, in red colour and then fill the rectangle with blue and triangle with yellow when the mouse 
click is done inside the regions.
(Hint: Use (1) glutMouseFunc() to interface mouse with display
system; (2) getPixel() to get the pixel colour at the given
location from frame buffer )
2. Implement the Boundary Fill algorithm(with 8 neighbours) to display triangle with given vertices,
and observe if leaking happens. To fix the leaking, For each boundary point, make all four neighbours
of it as boundary points, and then run the Boundary fill algorithm.
3. Draw Rectangle in Red colour, and implement the Flood Fill
algorithm to replace the red colour region to green colour when a
mouse click is done at a point inside the rectangle.

## Lab 9
Implement Poly Fill algorithm in OpenGL to rasterise polygon region, and observe the effect
of dropping horizontal edge, and also observe how vertical edges are displayed
a. First implement the algorithm using the floating point operations inside any loop(ie
using x=x+1/m).
b. Avoid floating point operation by replacing x=x+1/m with the function to compute
next x for next scan line.

## Lab 10
Geometric transformations in computer graphics do not reduce the visual quality of
images, whereas they reduce visual quality in imageprocessing as interpolation is involved.
1. Using built-in functions in OpenGL , draw polygon with 5 vertices of your choice and then
do the following and display the results
a. Translate the polygon with vector (a,b)
b. Rotate the polygon with given theta
c. Scale the polygon with the given scaling factor
2. Repeat the problem 1 , but use MATLAB or PYTHON with OpenCV for a), b) and c)
1) To understand clipping of parameterized objects in OpenGL
2) To understand the difference between clipping(in object space) and cropping(in image
space)

## Lab 11
1. Given $n$ 2D points (xi, yi), for 1&lt;=i&lt;=n, and a clipping rectangle with diagonal
vertices, (xmin, ymin) and (xmax, ymax), display(in red) the points that are inside the
rectangle(2 Marks)
2. Given $n$ lines segments with end points (xi, yi) for 1&lt;=i&lt;=n, and a clipping rectangle
with diagonal vertices, (xmin, ymin) and (xmax, ymax), display(in green) the portions
of the line segments that are inside the rectangle, using Cohen-Sutherland Line
Clipping Algorithm(6 Marks)
3. Download Lena image, and write code in Python/Matlab to crop and display the
middle half of the image(2 Marks)

Note: For clipping and cropping built-in functions are not to be used
