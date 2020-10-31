//Clipping a line code
#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include <GL/glut.h> 
#include<bits/stdc++.h>
// window size 
#define maxWD 640 
#define maxHT 480 
// Defining region codes 
const int INSIDE = 0; // 0000 
const int LEFT = 1; // 0001 
const int RIGHT = 2; // 0010 
const int BOTTOM = 4; // 0100 
const int TOP = 8; // 1000 

const int x_max = 350; 
const int y_max = 350; 
const int x_min = 100; 
const int y_min = 100; 
using namespace std; 
// this is a basic init for the glut window 
void myInit(void) 
{ 
    glClearColor(0.0, 0.0, 0.0, 1.0); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluOrtho2D(0.0, maxWD, 0.0, maxHT); 
    glClear(GL_COLOR_BUFFER_BIT); 
    glFlush(); 
} 
//function to find the code 
int computeCode(double x, double y) 
{ 
    // initialized as being inside 
    int code = INSIDE; 
  
    if (x < x_min) // to the left of rectangle 
        code |= LEFT; 
    else if (x > x_max) // to the right of rectangle 
        code |= RIGHT; 
    if (y < y_min) // below the rectangle 
        code |= BOTTOM; 
    else if (y > y_max) // above the rectangle 
        code |= TOP; 
  
    return code; 
} 
void cohenSutherlandClip(double x1, double y1, 
                         double x2, double y2) 
{ 
    // Compute region codes for P1, P2 
    int code1 = computeCode(x1, y1); 
    int code2 = computeCode(x2, y2); 
    bool accept = false; 
  
    while (true) 
    { 
        if ((code1 == 0) && (code2 == 0))//both points inside rect 
            { 
             accept = true; 
             break; 
            } 
        else if (code1 & code2) // If both endpoints are outside rectangle
            {  
            break; 
            } 
        else 
            {  
            int code_out; 
            double x, y; 
  
            // At least one endpoint is outside the 
            // rectangle, pick it. 
            if (code1 != 0) 
                code_out = code1; 
            else
                code_out = code2; 
            if (code_out & TOP) // point is above the clip rectangle 
            {     
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1); 
                y = y_max; 
            } 
            else if (code_out & BOTTOM) // point is below the rectangle 
            {    
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1); 
                y = y_min; 
            } 
            else if (code_out & RIGHT) // point is to the right of rectangle 
            {     
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1); 
                x = x_max; 
            } 
            else if (code_out & LEFT) // point is to the left of rectangle 
            {     
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1); 
                x = x_min; 
            } 
            if (code_out == code1) 
            { 
                x1 = x; 
                y1 = y; 
                code1 = computeCode(x1, y1); 
            } 
            else 
            { 
                x2 = x; 
                y2 = y; 
                code2 = computeCode(x2, y2); 
            } 
        } 
    } 
    if (accept) 
    { 
        glBegin(GL_LINES);
        glColor3f(0.0, 1.0, 0.0);  
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);  
        glEnd(); 
    } 
    else
    {
        glBegin(GL_LINES);
        glColor3f(1.0, 0.0, 0.0);  
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);  
        glEnd();
    } 
}  
// Actual display function 
void myDisplay(void) 
{  
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_LINE_LOOP);
        glVertex2i(x_min,y_min);
        glVertex2i(x_min,y_max);
        glVertex2i(x_max,y_max);
        glVertex2i(x_max,y_min);
        glEnd();//Draw a rectangle
        //points 
        int n=3;
        int X[6][4] = {{400,350,600, 380}, {400, 100, 100, 400}, {400, 400,100, 40}};
        for(int i=0;i<n;i++)
        {
         cohenSutherlandClip(X[i][0], X[i][1], X[i][2], X[i][3]);    
        }        
        glFlush(); 
} 
int main(int argc, char** argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(maxWD, maxHT); 
    glutInitWindowPosition(100, 150); 
    glutCreateWindow("Clipping a point"); 
    glutDisplayFunc(myDisplay); 
    myInit(); 
    glutMainLoop(); 
    return 0;
} 
