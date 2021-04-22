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
int flag=0;

void midpt(int x1,int y1,int R)
{
  vector<vector<int>> A;
glBegin(GL_POINTS);
int x=0;
int y=R;
int h=(1-R);
int dE=3;
int SE=-2*R+5;
vector<int> T;
T.push_back(x);
T.push_back(y);
A.push_back(T);
while(y > x)
{if (h < 0) 
  {
    h=h+dE;
    dE=dE+2;
    SE=SE+2;
  }
  else
  {
    h=h+SE;
    dE=dE+2;
    SE=SE+4;
    y=y-1;
  }
x=x+1;
vector<int> Temp;
Temp.push_back(x);
Temp.push_back(y);
A.push_back(Temp);
}
for(int i=0;i<A.size();i++)
{
  glVertex2i(A[i][0]+x1,A[i][1]+y1);
  glVertex2i(A[i][1]+x1,A[i][0]+y1);
   glVertex2i(A[i][0]+x1,-1*(A[i][1])+y1);
  glVertex2i(-1*(A[i][0])+x1,1*(A[i][1])+y1);
  glVertex2i(-1*(A[i][1])+x1,(A[i][0]+y1));
  glVertex2i((A[i][1]+x1),-1*(A[i][0])+y1);
  glVertex2i(-1*(A[i][0])+x1,-1*(A[i][1])+y1);
  glVertex2i(-1*(A[i][1])+x1,-1*(A[i][0])+y1);
}
glEnd();
}
void chaos() {
  glPointSize(5.0);
  glClearColor(0.0, 0.0, 0.0, 1.0); 
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 0.0, 0.0);
  // int x1=100,y1=100,x2=100,y2=500;
  midpt(100,250,100);
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
  chaos();
}



 









