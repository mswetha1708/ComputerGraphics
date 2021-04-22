  #include <GL/glut.h>  
#include<bits/stdc++.h>
  int ww = 600, wh = 500;   
   //  float fillCol[3] = {1.0,1.0,0.1};  
  	// float borderCol[3] = {1.0,0.0,0.0};

int Rect_1[2]={40,240},Rect_2[2]={40,410},Rect_3[2]={250,410},Rect_4[2]={250,240};
int Rect_11[2]={41,241},Rect_21[2]={41,411},Rect_31[2]={251,411},Rect_41[2]={251,241};
int Rect_12[2]={39,239},Rect_22[2]={39,409},Rect_32[2]={249,409},Rect_42[2]={249,239};
int Trian_1[2]={350,240},Trian_2[2]={440,410},Trian_3[2]={490,240};
// int Trian_11[2]={351,241},Trian_21[2]={441,411},Trian_31[2]={491,241};
// int Trian_12[2]={349,239},Trian_22[2]={439,409},Trian_32[2]={489,239};
// int Trian_13[2]={352,242},Trian_23[2]={442,412},Trian_33[2]={492,242};

float find_area(int A[2],int B[2],int C[2])
{
    float area=((A[0])*(B[1]-C[1])+(B[0])*(C[1]-A[1])+(C[0])*(A[1]-B[1]))/2.0;               
    return abs(area);
}

int checkpoint_triangle(int A[2],int B[2],int C[2],int Px,int Py)
{
    int P[2];
    P[0]=Px;P[1]=Py;
    float trian_area=find_area(A,B,C);
    float A1= find_area(P,B,C);
    float A2= find_area(P,A,C);
    float A3= find_area(P,A,B);
    
    if(trian_area==(A1+A2+A3))
        return 1;
    else
        return 0;
}
  void setPixel(int pointx, int pointy, float f[3])  
  {  
       glBegin(GL_POINTS);  
            glColor3fv(f);  
            glVertex2i(pointx,pointy);  
       glEnd();  
       glFlush();  
  }  
  void getPixel(int x, int y, float pixels[3])  
  {  
       glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,pixels);  
  }  
  void display()  
  {  
       glClearColor(0.0,0.0,0.0, 1.0); 
       
  	   glColor3f(1.0, 0.0, 0.0); 
    glClear(GL_COLOR_BUFFER_BIT);  
    glBegin(GL_LINE_LOOP);
    glVertex2iv(Rect_1); 
    glVertex2iv(Rect_2);
    glVertex2iv(Rect_3);
    glVertex2iv(Rect_4);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2iv(Rect_11); 
    glVertex2iv(Rect_21);
    glVertex2iv(Rect_31);
    glVertex2iv(Rect_41);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2iv(Rect_12); 
    glVertex2iv(Rect_22);
    glVertex2iv(Rect_32);
    glVertex2iv(Rect_42);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glVertex2iv(Trian_1); 
    glVertex2iv(Trian_2);
    glVertex2iv(Trian_3);
    glEnd();
    glFlush(); 
       glFlush();  
  }  
  void boundaryFill4(int x,int y,float fc[3],float  bc[3])  
  {  
       float ic[3];  
       getPixel(x,y,ic);  
       if(( (ic[0]!=bc[0]) || (ic[1]!=bc[1]) || (ic[2]!=bc[2]) ) && 
       	((ic[0]!=fc[0]) || (ic[1]!=fc[1]) || (ic[2]!=fc[2]) ) )  
       {  
            setPixel(x,y,fc);
            boundaryFill4(x+1,y,fc,bc); 
            boundaryFill4(x,y+1,fc,bc);
            boundaryFill4(x-1,y,fc,bc);
            boundaryFill4(x,y-1,fc,bc);
            boundaryFill4(x-1,y-1,fc,bc);
            boundaryFill4(x-1,y+1,fc,bc);
            boundaryFill4(x+1,y-1,fc,bc);
            boundaryFill4(x+1,y+1,fc,bc);
                 
       } 
       else
        return; 
  }  
  void mouse(int btn, int state, int x, int y)  
  {  
 
       float fc_r[3]={0,0,1};
        float fc_t[3]={1,1,0};
        float bc[3]={1,0,0}; 
        int xi = x;  
        int yi = (wh-y);
        if((xi>=Rect_1[0] && xi<=Rect_3[0]) && (yi>=Rect_1[1] && yi<=Rect_3[1]))   
            boundaryFill4(xi,yi,fc_r,bc); 
        else if(checkpoint_triangle(Trian_1,Trian_2,Trian_3,xi,yi))
            boundaryFill4(xi,yi,fc_t,bc);  
  }  
void init()
{
    // Set display window color to as glClearColor(R,G,B,Alpha)
    glClearColor(1, 0., 0., 0.1);
    // Set projection parameters.
    glMatrixMode(GL_PROJECTION);
    // Set 2D Transformation as gluOrtho2D(Min Width, Max Width, Min Height, Max Height)
    gluOrtho2D(0.0, 600, 0.0, 500);
} 
  int main(int argc, char** argv)  
  {  
       glutInit(&argc,argv);  
       glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
       glutInitWindowSize(600,500);  
       glutCreateWindow("Bountry-Fill-Recursive");  
       init(); 
       glutDisplayFunc(display);  
       glutMouseFunc(mouse);  
       glutMainLoop();  
       return 0;  
  }