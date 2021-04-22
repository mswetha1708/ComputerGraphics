
#include <graphics.h> 
#include <stdio.h> 
int main() 
{ 

    int gr = DETECT, gm; 
    initgraph(&gr, &gm,NULL);  
    int arr[]={200,100,300,100,250,13,200,100};
    setcolor(RED);
    drawpoly(4, arr);
    setcolor(GREEN); 
    circle(250,71,58);
    setcolor(GREEN);
    circle(250,71,29); 
    getch(); 
    closegraph(); 
    return 0; 
} 