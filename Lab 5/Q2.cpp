#include<GL/glut.h> 
#include<bits/stdc++.h>    
using namespace std; 
void init()
{
    // Set display window color to as glClearColor(R,G,B,Alpha)
    glClearColor(0., 0, 0, 0.1);
    // Set projection parameters.
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Set 2D Transformation as gluOrtho2D(Min Width, Max Width, Min Height, Max Height)
    gluOrtho2D(-780,780,-420,420);
}
void circle(float x1,float y1,double radius1,double radius2)
{
float x2,y2;
glClearColor(0., 0, 0, 0.1);
float angle;
glColor3f(1,1,1);
glBegin(GL_POINTS);
for (angle=0.0f;angle<360;angle+=1.0f)
{
    x2 = x1+sin(angle)*radius1;
    y2 = y1+cos(angle)*radius2;
    glVertex2i(round(x2),round(y2));
}
glEnd();
}
void home()
{

  glClear(GL_COLOR_BUFFER_BIT);
    circle(300,200,40,50);
    glFlush();
}
int main(int argc, char ** argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);
    // Set display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Set top - left display window position.
    glutInitWindowPosition(0, 0);
    // Set display window width and height
    glutInitWindowSize(1366, 768);
    // Create display window with the given title
    glutCreateWindow("Ellipse");
    // Execute initialization procedure
    init();
    // Send graphics to display window
    glutDisplayFunc(home);
    // Display everything and wait.
    glutMainLoop();
}