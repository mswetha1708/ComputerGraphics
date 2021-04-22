#include<bits/stdc++.h>
using namespace std;
float area(float x1, float y1, float x2, float y2, float x3, float y3)
{
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
}
void algo1(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4,float p1,float p2)
{
   float A = area (x1, y1, x2, y2, x3, y3); 
   float A1 = area (p1,p2, x2, y2, x3, y3);  
   float A2 = area (x1, y1,p1,p2, x3, y3); 
   float A3 = area (x1, y1, x2, y2, p1, p2); 
   float A4= area (x1, y1, x2, y2, p1, p2);
   if(A-(A1+A2+A3+A4)<=0.00001 || A-(A1+A2+A3+A4)>=0.00001)
      cout<<"Inside/on boundary"<<endl;
   else
      cout<<"Outside"<<endl;
}
int main()
{
	float x1,y1,x2,y2,x3,y3,x4,y4,p1,p2;
	cout<<"Enter points of rectangle\n";
	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
	cout<<"Enter the points\n";
	cin>>p1>>p2;
   algo1(x1,y1,x2,y2,x3,y3,x4,y4,p1,p2);//COnsidering dot product on the same side.
}
