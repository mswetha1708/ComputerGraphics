
// C code to implement basic 
// transformations in OPENGL 
#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include <GL/glut.h> 
#include<bits/stdc++.h>
// window size 
#define maxWD 640 
#define maxHT 480 
using namespace std;
// rotation speed 
#define thetaSpeed 0.31
// this is a basic init for the glut window 
void myInit(void) 
{ 
    glClearColor(1.0, 1.0, 1.0, 0.0); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluOrtho2D(0.0, maxWD, 0.0, maxHT); 
    glClear(GL_COLOR_BUFFER_BIT); 
    glFlush(); 
} 
void rotateAroundPt(vector<vector<int>>A, int cx, int cy) 
{ 
    int xf, yf; 
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    for(int i=0;i<A.size();i++)
    { 
        float theta = 0.0; 
        int px=A[i][0],py=A[i][1]; 
        // update thiclockwise rotation 
        theta = theta + thetaSpeed; 
        // check overflow 
        if (theta >= (2.0 * 3.14159)) 
            theta = theta - (2.0 * 3.14159); 
  
        // actual calculations.. 
        xf = cx + (int)((float)(px - cx) * cos(theta)) 
             - ((float)(py - cy) * sin(theta)); 
        yf = cy + (int)((float)(px - cx) * sin(theta)) 
             + ((float)(py - cy) * cos(theta));   
        glVertex2i(xf, yf); 
    } 
    glEnd();
} 
  
// this function will translate the point 
void translatePoint(vector<vector<int>> A,int tx, int ty) 
{ 
     
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    for(int i=0;i<A.size();i++)
    { 
        // update 
        int px=A[i][0],py=A[i][1];
        int fx = px, fy = py;
        px = px + tx; 
        py = py + ty; 
  
        // check overflow to keep point in screen 
        if (px > maxWD || px < 0 || py > maxHT || py < 0) { 
            px = fx; 
            py = fy; 
        } 
  
        glVertex2i(px, py);  
    } 
    glEnd();
} 
  
//this function draws 
void scalePoint(vector<vector<int>> A, int sx, int sy) 
{ 
    int fx, fy;
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    for(int i=0;i<A.size();i++)
    { 
        fx = A[i][0] * sx; 
        fy = A[i][1] * sy; 
        glVertex2i(fx, fy); 
    }  
    glEnd();
} 
  
// Actual display function 
void myDisplay(void) 
{  

        //translatePoint(100, 200, 1, 5);  
        //rotateAroundPt(200, 200, maxWD / 2, maxHT / 2);
        vector <vector<int> > A;
        vector<int> temp;
        temp.push_back(100);
        temp.push_back(100);
        A.push_back(temp);
        temp.clear();
        temp.push_back(200);
        temp.push_back(100);
        A.push_back(temp);
        temp.clear();
        temp.push_back(150);
        temp.push_back(200);
        A.push_back(temp);
        glBegin(GL_POLYGON);
        glColor3f(0.0, 1.0, 0.0);
        int sum1=0;int sum2=0;
        for(int i=0;i<A.size();i++)
        {  
        glVertex2i(A[i][0],A[i][1]);
        sum1+=A[i][0];
        sum2=A[i][1]; 
        }  
        glEnd(); 
        // scalePoint(A,1,2);
        // translatePoint(A,10,20);
         rotateAroundPt(A,0,0);//circle
        // rotateAroundPt(A,sum1*1.0/A.size(),sum2*1.0/A.size());
        glFlush(); 
} 
  
int main(int argc, char** argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(maxWD, maxHT); 
    glutInitWindowPosition(100, 150); 
    glutCreateWindow("Transforming point"); 
    glutDisplayFunc(myDisplay); 
    myInit(); 
    glutMainLoop(); 
    return 0;
} 
