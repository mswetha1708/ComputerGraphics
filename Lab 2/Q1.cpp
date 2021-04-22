
// C++ Implementation for drawing line 
#include <graphics.h> 
 #include<bits/stdc++.h> 
using namespace std; 
void point()
{

    putpixel(350, 100, YELLOW);  
    getch();
    closegraph();
}
void line()
{

 
    line(150, 150, 450, 150); 
    getch();
    closegraph();     
}
void circle()
{ 
    circle(250, 200, 50); 
    getch();
    closegraph();  
}
void ellipse()
{ 
    ellipse(100,100, 0, 360,40,50);
    getch();
    closegraph();    
}
void Triangle()
{ 
    int arr[] = {320, 150, 400, 250,  
                 250, 350, 320, 150};  
    drawpoly(4, arr); 
    getch();
    closegraph();   
    
}
void Rectangle()
{
  
    rectangle(100,100,400,400);
    getch();  
    closegraph();    ;
}
int main() 
{ 

    int ch;
    // XInitThreads();
    do{cout<<"\n1.Point\n.2.Line\n3.Circle\n4.Ellipse\n5.Triangle\n6.Rectangle\n";
    cin>>ch;
    int gd = DETECT, gm; 
    initgraph(&gd, &gm,NULL);
    switch(ch)
    {
        case 1:point();;break;
        case 2:line();break;
        case 3:circle();break;
        case 4:ellipse();break;
        case 5:Triangle();break;
        case 6:Rectangle();break;
        case 7:cout<<"EXIT";break;
        default:cout<<"Invalid Choice";
    }}while(ch!=7);
} 
