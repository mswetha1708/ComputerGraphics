#include<GL/glut.h> 
#include<bits/stdc++.h>    
using namespace std;
void init()
{
    // Set display window color to as glClearColor(R,G,B,Alpha)
    glClearColor(0.5, 0.9, 0.4, 0.0);
    // Set projection parameters.
    glMatrixMode(GL_PROJECTION);
    // Set 2D Transformation as gluOrtho2D(Min Width, Max Width, Min Height, Max Height)
    gluOrtho2D(0.0, 800, 0.0, 600);
}
void circle(float x1,float y1,double radius)
{
float x2,y2;
float angle;
glColor3f(0.9,0.9,0.9);
glBegin(GL_TRIANGLE_FAN);
glVertex2f(x1,y1);
for (angle=1.0f;angle<361.0f;angle+=0.2)
{
    x2 = x1+sin(angle)*radius;
    y2 = y1+cos(angle)*radius;
    glVertex2f(x2,y2);
}
glEnd();
}
void home()
{
    // Top of car
    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP);
    glVertex2i(300, 300);
    glVertex2i(600, 300);
    glVertex2i(550, 425);
    glVertex2i(425, 425);
    glEnd();
    //Outline left
    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP);
    glVertex2i(310, 305);
    glVertex2i(460, 305);
    glVertex2i(460, 415);
    glVertex2i(420, 415);
    glEnd();
    //Outline Right
    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP);
    glVertex2i(465, 415);
    glVertex2i(546, 415);
    glVertex2i(590, 305);
    glVertex2i(465, 305);
    glEnd();
    // Car
    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP);
    glVertex2i(200, 200);
    glVertex2i(600, 200);
    glVertex2i(600, 300);
    glVertex2i(200, 300);
    glEnd();
    circle(300,200,40);
    circle(535,200,40);
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
    glutCreateWindow("2D Car in OpenGL ");
    // Execute initialization procedure
    init();
    // Send graphics to display window
    glutDisplayFunc(home);
    // Display everything and wait.
    glutMainLoop();
}