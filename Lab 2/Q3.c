// C program to create a smiley face 
 
#include <graphics.h> 
#include <stdio.h> 
int main() 
{  
    int gr = DETECT, gm;  
    initgraph(&gr, &gm,NULL); 
    setcolor(YELLOW); 
    circle(300, 200, 80); 
    int border_color = WHITE; 
    floodfill(300,200,border_color);


    setcolor(BLACK); 
      
    circle(330, 175, 10); 
   
    floodfill(330,175,border_color); 

    circle(270, 175, 10); 
    
    floodfill(270,175,border_color);
    setcolor(BLACK); 
    int arr[]={270, 230, 270,235,  330, 235, 330,230,270, 230};
    fillpoly(4, arr); 
    getch(); 
    closegraph(); 
    return 0; 
} 
