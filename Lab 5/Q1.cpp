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
void drawline(int x1,int y1,int x2,int y2)
{
if(x1>x2)
      swap(x1,x2);
  float m = (y2-y1)*1.0/(x2-x1);
  float b = y2-(m*x2);
  if(x1==x2)
  {
  glBegin(GL_POINTS);
  for(int i = y1; i < y2; i++) {
      glVertex2i(round(x1),round(i));
  }
  }
  else
  {
  glBegin(GL_POINTS);
  for(int i = x1; i < x2; i++) {
      float y=m*i +b;
      glVertex2i(round(i),round(y));
  }
  }
  glEnd();
  
}
void chaos() {
  glPointSize(1.0);
  glClearColor(0.0, 0.0, 0.0, 1.0); 
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);
  int x1=100,y1=100,x2=100,y2=500;
  drawline(100,100,100,500);//Vertical
  drawline(100,100,300,100);//horizontal
  drawline(100,100,200,150);//m<1
  drawline(100,100,200,400);//m>1
  glFlush();
}
int main(int argc, char ** argv)
{
    // Initialize GLUT
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
}

