#include<GL/glut.h>   
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
void home()
{
    // Top of Front Wall
    glColor3f(1,0.2, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(450, 550);
    glVertex2i(300, 350);
    glVertex2i(600, 350);
    glEnd();
    // Front Wall
    glColor3f(0.2, 0.5,1);
    glBegin(GL_POLYGON);
    glVertex2i(300, 350);
    glVertex2i(600, 350);
    glVertex2i(600, 100);
    glVertex2i(300, 100);
    glEnd();
    // Front Door
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2i(425, 250);
    glVertex2i(475, 250);
    glVertex2i(475, 100);
    glVertex2i(425, 100);
    glEnd();
    // window one
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2i(350, 250);
    glVertex2i(385, 250);
    glVertex2i(385,210);
    glVertex2i(350,210);
    glEnd();
    // window two
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2i(515, 250);
    glVertex2i(550, 250);
    glVertex2i(550,210);
    glVertex2i(515,210);
    glEnd();
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
    glutCreateWindow("2D House in OpenGL ");
    // Execute initialization procedure
    init();
    // Send graphics to display window
    glutDisplayFunc(home);
    // Display everything and wait.
    glutMainLoop();
}

