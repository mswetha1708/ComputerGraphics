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
vector<vector<int>> midpt(int x1,int y1,int x2,int y2)
{
  vector<vector<int>> A;
  if(x1>x2)
  {
    swap(x1,x2);
    swap(y1,y2);
  }
 int x = x1,y = y1;
int dy = y2 -y1,dx = x2 -x1;
int d = 2*dy -dx;
int dE = 2*dy ;
int dNE = 2 *(dy - dx);
vector<int> T;
T.push_back(x);
T.push_back(y);
A.push_back(T);
while (x < x2)
{  if (d<= 0)
    d = d+dE;
  else
  { d = d+dNE ;
    y=y+1;
  }
  x=x+1;
  vector<int> Temp;
  Temp.push_back(x);
  Temp.push_back(y);
  A.push_back(Temp);
  glVertex2i(x,y);
}

 return A;
}
void convert(int x1,int y1,int x2,int y2)
{
  float m=(y2-y1)*1.0/(x2-x1);
  float b=y1-m*x1;
  cout<<m;
  if(m<=1 && m>=0)//0 to 45
  {
    flag=1;
  }
  else if(m>1)//45 to 90
  {
    swap(x1,y1);
    swap(x2,y2);
    flag=2;
  }
  else if(m>=-1 && m<=0)//135 to 180
  {
    y1*=-1;
    y2*=-1;
    flag=4;
  }
  else if(m<=-1)//90 to 135
  {
    x1*=-1;
    swap(x1,y1);
    x2*=-1;
    swap(x2,y2);
    flag=3;
  }
  vector<vector<int>> A=midpt(x1,y1,x2,y2);
  glBegin(GL_POINTS);
  if(flag==1)
  {
    for(int i=0;i<A.size();i++)
    {
      glVertex2i(A[i][0],A[i][1]);
    }
  }
  else if(flag==2)
  {
    for(int i=0;i<A.size();i++)
    {
      glVertex2i(A[i][1],A[i][0]);
    }
  }
  else if(flag==3)
  {
    for(int i=0;i<A.size();i++)
    {

      glVertex2i(-1*A[i][1],A[i][0]);
    }
  }
  else 
  {
    for(int i=0;i<A.size();i++)
    {
      glVertex2i(A[i][0],-1*A[i][1]);
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
  convert(100,100,100,500);//Vertical
  convert(100,100,300,100);//horizontal
  convert(100,100,200,150);//m<1 Q1
  convert(100,100,200,400);//m>1 Q2
  convert(50,130,100,100);//m<1 Q3
  convert(50,250,100,100);//Q4
  convert(100,100,120,30);//Q5
  convert(100,100,200,80);//Q6
  convert(100,100,50,80);//Q7
  convert(100,100,50,30);//Q8
  // glBegin(GL_POINTS);
  // glVertex2i(-100,100);
  // glEnd();
  //convert(100,100,200,400);//m>1
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
















