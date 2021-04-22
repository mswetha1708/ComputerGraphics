//Clipping a point code
#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include <GL/glut.h> 
#include<bits/stdc++.h>
// window size 
#define maxWD 640 
#define maxHT 480 
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
//function to clip points 
void pointClip(int XY[][2], int n, int Xmin, int Ymin,  
                                int Xmax, int Ymax)  
{   
    glBegin(GL_POINTS);

    glColor3f(1.0, 0.0, 0.0); 
    for (int i=0; i<n; i++)  
    {  
    if ( (XY[i][0] >= Xmin) && (XY[i][0] <= Xmax))  
    {  
            if ( (XY[i][1] >= Ymin) && (XY[i][1] <= Ymax))  
                glVertex2i(XY[i][0],XY[i][1]);  
    }  
    }
    glEnd();

}  
 
  
// Actual display function 
void myDisplay(void) 
{  
        int XY[6][2] = {{10, 10}, {-10, 10}, {400, 100},  
                    {100, 400}, {400, 400}, {100, 40}}; 
        int n=6;//size of the array 
        int Xmin = 0;  
        int Xmax = 350;  
        int Ymin = 0;  
        int Ymax = 350;//set frame size
        glColor3f(0.0, 1.0, 0.0);
        glPointSize(5.0);
        glBegin(GL_LINE_LOOP);
        glVertex2i(Xmin,Ymin);
        glVertex2i(Xmin,Ymax);
        glVertex2i(Xmax,Ymax);
        glVertex2i(Xmax,Ymin);
        glEnd();//Draw a rectangle
        //points
        glBegin(GL_POINTS);
        glColor3f(0.0, 0.0, 1.0); 
        for (int i=0; i<n; i++)  
        {  
            glVertex2i(XY[i][0],XY[i][1]);  
        }
        glEnd();
        pointClip(XY,n, Xmin, Ymin, Xmax, Ymax);      
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
