// Scanline Polygon fill Algorithm 
#include <stdio.h> 
#include <math.h> 
#include <GL/glut.h> 
#include<iostream>
#define Ht 800 
#define Wd 600 
#define maxVer 10000 
 using namespace std;
typedef struct edgebucket  
{ 
    int ymax;   //max y-coordinate of edge 
    float xofymin;  //x-coordinate of lowest edge point updated only in aet 
    //float slopeinverse;
    float delx;
    float dely;
    int sign; 
}EdgeBucket; 
  
typedef struct edgetabletup 
{
    int countEdgeBucket;    //no. of edgebuckets 
    EdgeBucket buckets[maxVer]; 
}EdgeTableTuple; 
  
EdgeTableTuple EdgeTable[Ht], ActiveEdgeTuple; 
  
  
/* Function to sort an array using insertion sort*/
void insertionSort(EdgeTableTuple *ett) 
{ 
    int i,j; 
    EdgeBucket temp;  
  
    for (i = 1; i < ett->countEdgeBucket; i++)  
    { 
        temp.ymax = ett->buckets[i].ymax; 
        temp.xofymin = ett->buckets[i].xofymin; 
        temp.delx = ett->buckets[i].delx; 
        temp.dely = ett->buckets[i].dely;
        temp.sign = ett->buckets[i].sign;  
        j = i - 1; 
  
    while ((temp.xofymin < ett->buckets[j].xofymin) && (j >= 0))  
    { 
        ett->buckets[j + 1].ymax = ett->buckets[j].ymax; 
        ett->buckets[j + 1].xofymin = ett->buckets[j].xofymin; 
        ett->buckets[j + 1].delx = ett->buckets[j].delx;
        ett->buckets[j + 1].dely = ett->buckets[j].dely;
        ett->buckets[j + 1].sign = ett->buckets[j].sign; 
        j = j - 1; 
    } 
    ett->buckets[j + 1].ymax = temp.ymax; 
    ett->buckets[j + 1].xofymin = temp.xofymin; 
    ett->buckets[j + 1].delx = temp.delx;
    ett->buckets[j + 1].dely = temp.dely;
    ett->buckets[j + 1].sign = temp.sign; 
    } 
} 
  
  
void storeEdgeInTuple (EdgeTableTuple *receiver,int ym,int xm,float delx,float dely,int sign) 
{ 
    (receiver->buckets[(receiver)->countEdgeBucket]).ymax = ym; 
    (receiver->buckets[(receiver)->countEdgeBucket]).xofymin = (float)xm; 
    (receiver->buckets[(receiver)->countEdgeBucket]).delx = delx;
    (receiver->buckets[(receiver)->countEdgeBucket]).dely = dely;
    (receiver->buckets[(receiver)->countEdgeBucket]).sign = sign; 
    printf("%f,%f,%d\n",delx,dely,sign);
    // sort the buckets 
    insertionSort(receiver); 
          
    (receiver->countEdgeBucket)++;  
      
} 
  
void storeEdgeInTable (int x1,int y1, int x2, int y2) 
{ 
    float m,minv,delx,dely; 
    int sign;
    int ymaxTS,xwithyminTS, scanline; //ts stands for to store 
      
    if (x2==x1) 
    { 
        minv=0.000000; 
    } 
    else
    { 
    //m = ((float)(y2-y1))/((float)(x2-x1)); 
     dely=y2-y1;
     delx=x2-x1;
    // horizontal lines are not stored in edge table 
    if (y2==y1) 
        return; 
    if(((delx >0)&&(dely>0)) || (delx<0) && (dely<0))
     sign=1;
    else
      sign=-1;
    delx=abs(delx);
    dely=abs(dely);
          
    //minv = (float)1.0/m;
    } 
      
    if (y1>y2) 
    { 
        scanline=y2; 
        ymaxTS=y1; 
        xwithyminTS=x2; 
    } 
    else
    { 
        scanline=y1; 
        ymaxTS=y2; 
        xwithyminTS=x1;      
    } 
    // the assignment part is done..now storage.. 
    storeEdgeInTuple(&EdgeTable[scanline],ymaxTS,xwithyminTS,delx,dely,sign); 
      
      
} 
  
void removeEdgeByYmax(EdgeTableTuple *Tup,int yy) 
{ 
    int i,j; 
    for (i=0; i< Tup->countEdgeBucket; i++) 
    { 
        if (Tup->buckets[i].ymax == yy) 
        { 
            printf("\nRemoved at %d",yy); 
              
            for ( j = i ; j < Tup->countEdgeBucket -1 ; j++ ) 
                { 
                Tup->buckets[j].ymax =Tup->buckets[j+1].ymax; 
                Tup->buckets[j].xofymin =Tup->buckets[j+1].xofymin; 
                Tup->buckets[j].delx = Tup->buckets[j+1].delx;
                Tup->buckets[j].dely = Tup->buckets[j+1].dely; 
                Tup->buckets[j].sign = Tup->buckets[j+1].sign;
                } 
                Tup->countEdgeBucket--; 
            i--; 
        } 
    } 
}      
  
float delc=0,c=0;
int findnextedgepoint(int x,float delx,float dely,int sign)
{
       
    if(delx < dely)
    {
      delc=delx;
      c=c+delc;
      if(c>dely)
      {
        c=c-dely;
        return (x+sign);
      }  
      else
      return x;      
    }
    else
    {
        delc=dely;
        while(c<delx)
        {
            c=c+delc;
            x=x+sign;
        }
        c=c-delx;
        return x;
    }

}
void updatexbynextedgepoint(EdgeTableTuple *Tup) 
{ 
    int i; 
    printf("\nentered\n");
    for (i=0; i<Tup->countEdgeBucket; i++) 
    { 
        int x=(Tup->buckets[i]).xofymin;
        (Tup->buckets[i]).xofymin =findnextedgepoint((Tup->buckets[i]).xofymin,(Tup->buckets[i]).delx,
                               (Tup->buckets[i]).dely,(Tup->buckets[i]).sign); 
        Tup->buckets[i].dely-=1;
        if(Tup->buckets[i].sign==1)
            Tup->buckets[i].delx=abs(Tup->buckets[i].delx+x-(Tup->buckets[i]).xofymin);
        else if(Tup->buckets[i].sign==-1)
            Tup->buckets[i].delx=abs(x-(Tup->buckets[i].delx)-(Tup->buckets[i]).xofymin);
        
    } 
} 
  
  
void ScanlineFill() 
{ 
  
    int i, j, x1, ymax1, x2, ymax2, FillFlag = 0, coordCount; 
    for (i=0; i<Ht; i++)
    { 
        for (j=0; j<EdgeTable[i].countEdgeBucket; j++) 
        { 
            storeEdgeInTuple(&ActiveEdgeTuple,EdgeTable[i].buckets[j]. 
                     ymax,EdgeTable[i].buckets[j].xofymin, 
                    EdgeTable[i].buckets[j].delx,EdgeTable[i].buckets[j].dely,EdgeTable[i].buckets[j].sign); 
        }  
        removeEdgeByYmax(&ActiveEdgeTuple, i); 
        insertionSort(&ActiveEdgeTuple); 
        j = 0;  
        FillFlag = 0; 
        coordCount = 0; 
        x1 = 0; 
        x2 = 0; 
        ymax1 = 0; 
        ymax2 = 0; 
        while (j<ActiveEdgeTuple.countEdgeBucket) 
        { 
            if (coordCount%2==0) 
            { 
                x1 = (int)(ActiveEdgeTuple.buckets[j].xofymin); 
                ymax1 = ActiveEdgeTuple.buckets[j].ymax; 
                coordCount++;
            } 
            else
            { 
                x2 = (int)ActiveEdgeTuple.buckets[j].xofymin; 
                ymax2 = ActiveEdgeTuple.buckets[j].ymax; 
                FillFlag = 0; 
                coordCount++; 
                FillFlag = 1; 
            if(FillFlag) 
            {  
                glColor3f(1.0f,1.0f,0.0f); 
                cout<<"Hi";
                glBegin(GL_LINES); 
                glVertex2i(x1,i); 
                glVertex2i(x2,i); 
                glEnd(); 
                glFlush();       
                for(int i=0;i<10000000;i++);
            } 
        }     
        j++; 
    }  
    updatexbynextedgepoint(&ActiveEdgeTuple); 
} 
  
} 
  
  
void myInit(void) 
{ 
    glClearColor(0,0,0,0); 
    glMatrixMode(GL_PROJECTION); 
      
    glLoadIdentity(); 
    gluOrtho2D(0,Ht,0,Wd); 
    glClear(GL_COLOR_BUFFER_BIT); 
} 
  
void display(void) 
{ 
    for (int i=0; i<Ht; i++) 
        EdgeTable[i].countEdgeBucket = 0;
      
    ActiveEdgeTuple.countEdgeBucket = 0; 
    //initEdgeTable(); 
    int X[16]={113,250,270,113};
    int Y[16]={321,390,160,321};
    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_LINE_LOOP); 
                glVertex2i(113,321); 
                glVertex2i(250,390);
                 glVertex2i(270,160); 
                glVertex2i(113,321); 
        glEnd(); 
    
            storeEdgeInTable(113,321,250,390);
            storeEdgeInTable(250,390,270,160);
            storeEdgeInTable(270,160,113,321);
            
    ScanlineFill(); 
    glFlush();
} 
  
int main(int argc, char** argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
    glutInitWindowSize(Ht,Wd); 
    glutInitWindowPosition(100, 150); 
    glutCreateWindow("Poly-fill using scanlines"); 
    myInit(); 
    glutDisplayFunc(display); 
    glutMainLoop(); 
   
    return 0;
} 