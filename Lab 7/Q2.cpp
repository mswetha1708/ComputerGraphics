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

void midpt(int x1,int y1,int a,int b)
{
  vector<vector<int>> A;
glBegin(GL_POINTS);
int x=0;
int y=b;
double d2;
double sa=sqrt(a);
double sb=sqrt(b);
double d1=sb-(sa*b)+0.25*sa;
vector<int> R;
R.push_back(x);
R.push_back(y);
A.push_back(R);
while(sa*(y-0.5) >sb*(x+1))
{if (d1 < 0) 
  {
    d1+=sb*(x<<1)+3;
  }
  else
  {
    d1+=sb*((x<<1)+3)+sa*(-(y<<1)+2);
    y--;
  }
x=x+1;
vector<int> Temp1;
Temp1.push_back(x);
Temp1.push_back(y);
A.push_back(Temp1);
}
d2=sb*sqrt(x+0.5)+sa*sqrt(y-1)-(sa*sb);
vector<int> T;
T.push_back(x);
T.push_back(y);
A.push_back(T);
while(y>0)
{if (d2 < 0) 
  {
    d2+=sb*((x<<1)+2)+sa*(-(y<<1)+3);
    x++;
  }
  else
  {
    d2+=sa*(-(y<<1)+3);
  }
y--;
vector<int> Temp;
Temp.push_back(x);
Temp.push_back(y);
A.push_back(Temp);
}
for(int i=0;i<A.size();i++)
{
  glVertex2i(A[i][0]+x1,A[i][1]+y1);
  glVertex2i(A[i][0]+x1,-1*(A[i][1])+y1);
  glVertex2i(-1*(A[i][0])+x1,1*(A[i][1])+y1);
  glVertex2i(-1*(A[i][0])+x1,-1*(A[i][1])+y1);
}
glEnd();
}
void chaos() {
  glPointSize(5.0);
  glClearColor(0.0, 0.0, 0.0, 1.0); 
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 0.0);
  midpt(500,250,50,200);
  midpt(100,250,150,20);
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







#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int N = 100000000;
    int i, j, processes, rank, N_per_process, tag=100;
    MPI_Status status;
    MPI_Init(&argc,&argv);
    int *A = (int *) malloc(sizeof(int) * N);
    int *B = (int *) malloc(sizeof(int) * N);
    int *C = (int *) malloc(sizeof(int) * N);

    int *AP, *BP, *CP;
    int *buff;

    for (i=0; i<N; i++) {
        A[i] = i;
        B[i] = i;
    }
    MPI_Comm_size(MPI_COMM_WORLD, &processes);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    double time1=MPI_Wtime();
    N_per_process = N / processes;
    buff = (int *) malloc(sizeof(int) * N_per_process);

    if (rank == 0) {
        for (i=0; i<processes-1; i++) {
            // Divided A & B and send it to other processes evenly
            for (j=0; j<N_per_process; j++) {
                buff[j] = A[(N_per_process * i) +j];
            }
            MPI_Send(buff, N_per_process, MPI_INT, i+1, tag, MPI_COMM_WORLD);

            for (j=0; j<N_per_process; j++) {
                buff[j] = B[(N_per_process * i) +j];
            }
            MPI_Send(buff, N_per_process, MPI_INT, i+1, tag, MPI_COMM_WORLD);
        }

        // Receive C from other processes in pieces & combine
        for (i=0; i<processes-1; i++) {
            MPI_Recv(buff, N_per_process, MPI_INT, i+1, tag, MPI_COMM_WORLD, &status);
            for (j=0; j<N_per_process; j++) {
                C[(N_per_process * i) + j] = buff[j];
            }
        }
        // Remaining part of Vector
        for ( i=N - N_per_process; i < N; i++) {
            C[i] = A[i] * B[i];
        }
        // for (i=0; i<N; i++) {
        //     printf("%d, ", C[i]);
        // }
        // printf("\n");
    } else {
        AP = (int *) malloc(sizeof(int) * N_per_process);
        BP = (int *) malloc(sizeof(int) * N_per_process);
        CP = (int *) malloc(sizeof(int) * N_per_process);

        MPI_Recv(AP, N_per_process, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);
        MPI_Recv(BP, N_per_process, MPI_INT, 0, tag, MPI_COMM_WORLD, &status);

        for (i=0; i<N_per_process; i++) {
            CP[i] = AP[i] * BP[i];
        }
        MPI_Send(CP, N_per_process, MPI_INT, 0, tag, MPI_COMM_WORLD);
    }
    double time2=MPI_Wtime();
    printf("%f",time2-time1);
    MPI_Finalize();
    return 0;
}







