
// Scanline Polygon fill Algorithm 

#include <stdio.h> 
#include <math.h> 
#include<iostream>
#include <GL/glut.h> 
#define Ht 800 
#define Wd 600 
#define maxVer 10000 
using namespace std;
typedef struct edgebucket 
{ 
	int ymax; //max y-coordinate 
	float xofymin; //x-coordinate of lowest 
	float slopeinverse; 
}EdgeBucket; 

typedef struct edgetabletup 
{ 
	
	int countEdgeBucket; 
	EdgeBucket buckets[maxVer]; 
}EdgeTableTuple; 

EdgeTableTuple EdgeTable[Ht], ActiveEdgeTuple; 


// Scanline Function 
void initEdgeTable() 
{ 
	int i; 
	for (i=0; i<Ht; i++) 
	{ 
		EdgeTable[i].countEdgeBucket = 0; 
	} 
	
	ActiveEdgeTuple.countEdgeBucket = 0; 
} 
 
void insertionSort(EdgeTableTuple *ett) 
{ 
	int i,j; 
	EdgeBucket temp; 

	for (i = 1; i < ett->countEdgeBucket; i++) 
	{ 
		temp.ymax = ett->buckets[i].ymax; 
		temp.xofymin = ett->buckets[i].xofymin; 
		temp.slopeinverse = ett->buckets[i].slopeinverse; 
		j = i - 1; 

	while ((temp.xofymin < ett->buckets[j].xofymin) && (j >= 0)) 
	{ 
		ett->buckets[j + 1].ymax = ett->buckets[j].ymax; 
		ett->buckets[j + 1].xofymin = ett->buckets[j].xofymin; 
		ett->buckets[j + 1].slopeinverse = ett->buckets[j].slopeinverse; 
		j = j - 1; 
	} 
	ett->buckets[j + 1].ymax = temp.ymax; 
	ett->buckets[j + 1].xofymin = temp.xofymin; 
	ett->buckets[j + 1].slopeinverse = temp.slopeinverse; 
	} 
} 


void storeEdgeInTuple (EdgeTableTuple *receiver,int ym,int xm,float slopInv) 
{ 
	(receiver->buckets[(receiver)->countEdgeBucket]).ymax = ym; 
	(receiver->buckets[(receiver)->countEdgeBucket]).xofymin = (float)xm; 
	(receiver->buckets[(receiver)->countEdgeBucket]).slopeinverse = slopInv; 
			
	// sort the buckets 
	insertionSort(receiver); 
		
	(receiver->countEdgeBucket)++; 
	
	
} 

void storeEdgeInTable (int x1,int y1, int x2, int y2) 
{ 
	float m,minv; 
	int ymaxTS,xwithyminTS, scanline; 
	
	if (x2==x1) 
	{ 
		minv=0.000000; 
	} 
	else
	{ 
	m = ((float)(y2-y1))/((float)(x2-x1)); 
	
	// horizontal lines are not stored in edge table 
	if (y2==y1) 
		return; 
		
	minv = (float)1.0/m; 
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
	storeEdgeInTuple(&EdgeTable[scanline],ymaxTS,xwithyminTS,minv); 
	
	
} 

void removeEdgeByYmax(EdgeTableTuple *Tup,int yy) 
{ 
	int i,j; 
	for (i=0; i< Tup->countEdgeBucket; i++) 
	{ 
		if (Tup->buckets[i].ymax == yy) 
		{ 	
			for ( j = i ; j < Tup->countEdgeBucket -1 ; j++ ) 
				{ 
				Tup->buckets[j].ymax =Tup->buckets[j+1].ymax; 
				Tup->buckets[j].xofymin =Tup->buckets[j+1].xofymin; 
				Tup->buckets[j].slopeinverse = Tup->buckets[j+1].slopeinverse; 
				} 
				Tup->countEdgeBucket--; 
			i--; 
		} 
	} 
}	 


void updatexbyslopeinv(EdgeTableTuple *Tup) 
{ 
	int i; 
	
	for (i=0; i<Tup->countEdgeBucket; i++) 
	{ 
		(Tup->buckets[i]).xofymin =(Tup->buckets[i]).xofymin + (Tup->buckets[i]).slopeinverse; 
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
					EdgeTable[i].buckets[j].slopeinverse); 
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
	updatexbyslopeinv(&ActiveEdgeTuple); 
} 


printf("\nEnd"); 

} 
void display(void) 
{ 
	initEdgeTable(); 
	glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_LINE_LOOP); 
				glVertex2i(180,180); 
				glVertex2i(180,200);
				 glVertex2i(190,250); 
				glVertex2i(200,200);
				glVertex2i(210,250); 
				glVertex2i(220,190);
				glVertex2i(230,185); 
				glVertex2i(260,250);
				glVertex2i(260,180); 
				glVertex2i(180,180); 
		glEnd(); 
	
			storeEdgeInTable(180,180,180,200);
			storeEdgeInTable(180,200,190,250);
			storeEdgeInTable(190,250,200,200);
			storeEdgeInTable(200,200,210,250);
			storeEdgeInTable(210,250,220,190);
			storeEdgeInTable(220,190,230,185);
			storeEdgeInTable(230,185,260,250);
			storeEdgeInTable(260,250,260,180);
			storeEdgeInTable(260,180,180,180);
			
	ScanlineFill();//actual calling of scanline filling.. 
	glFlush();
	 
} 
void init()
{
    //glClearColor(1.0,1.0,1.0,0.1); 
    glClearColor(0.0,0.0,0.0, 1.0); 
    glMatrixMode(GL_PROJECTION);   
    glLoadIdentity(); 
    gluOrtho2D(0,Ht,0,Wd); 
    glClear(GL_COLOR_BUFFER_BIT); 
} 

int main(int argc, char** argv) 
{  
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowSize(Ht,Wd); 
	glutInitWindowPosition(600, 500); 
	glutCreateWindow("Fill"); 
	init(); 
	glutDisplayFunc(display); 
	glutMainLoop(); 
	return 0;
} 







