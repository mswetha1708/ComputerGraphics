#include<GL/glut.h>   
#include<bits/stdc++.h>
using namespace std;
void init()
{
    // Set display window color to as glClearColor(R,G,B,Alpha)
    glClearColor(0, 0., 0., 0.1);
    // Set projection parameters.
    glMatrixMode(GL_PROJECTION);
    // Set 2D Transformation as gluOrtho2D(Min Width, Max Width, Min Height, Max Height)
    gluOrtho2D(0.0, 800, 0.0, 600);
}
void dda(int x1,int y1,int x2,int y2)
{

  float m = (y2-y1)*1.0/(x2-x1);
  float rm= (x2-x1)*1.0/(y2-y1);
  int x=round(x1);int y=round(y1);
  //cout<<m<<" ";
 glBegin(GL_POINTS);
  glVertex2i(x,y);
  float yf=y1,xf=x1;
  if(abs(m)<=1)
  {
  	if(x1>x2)
      {swap(x1,x2);
  	  swap(y1,y2);
  	  x=round(x1);y=round(y1);xf=x1;yf=y1;}
  	while(x<x2)
  	{
  		x=x+1;yf=yf+m;
  		y=round(yf);
  		glVertex2i(x,y);
  	}
  }
  else
  	{ 
  		if(y1>y2)
      {swap(x1,x2);
  	  swap(y1,y2);
  	  x=round(x1);y=round(y1);xf=x1;yf=y1;}
  	while(y<y2)
  	{
  		y=y+1;xf=xf+rm;
  		x=round(xf);
  		glVertex2i(x,y);
  	}
  }
  glEnd();
}
void chaos() {
  glPointSize(5.0);
  glClearColor(0.0, 0.0, 0.0, 1.0); 
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);
  int x1=100,y1=100,x2=100,y2=500;
  dda(100,100,100,300);//Vertical
  dda(100,100,300,100);//horizontal
  dda(100,100,150,260);//m<1
  dda(100,100,50,80);
  dda(100,100,50,130);
  dda(100,100,150,50);
  glFlush();
}
int main(int argc, char ** argv)
{
    //Initialize GLUT
    glutInit(&argc, argv);
    // Set display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Set top - left display window position.
    glutInitWindowPosition(100, 100);
    // Set display window width and height
    glutInitWindowSize(800, 600);
    // Create display window with the given title
    glutCreateWindow("Line Equation ");
    // Execute initialization procedure
    init();
    // Send graphics to display window
    glutDisplayFunc(chaos);
    // Display everything and wait.
    glutMainLoop();
    chaos();
}
