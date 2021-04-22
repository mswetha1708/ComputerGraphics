#include<bits/stdc++.h>
using namespace std;
float area(float x1, float y1, float x2, float y2, float x3, float y3)
{
	return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
}
void algo1(float x1,float y1,float x2,float y2,float x3,float y3,float p1,float p2)
{
   float A = area (x1, y1, x2, y2, x3, y3); 
   float A1 = area (p1,p2, x2, y2, x3, y3);  
   float A2 = area (x1, y1,p1,p2, x3, y3); 
   float A3 = area (x1, y1, x2, y2, p1, p2); 
   if(A==A1+A2+A3)
   	cout<<"Inside/on boundary"<<endl;
   else
   	cout<<"Outside"<<endl;
}
int crossproduct(float x1,float y1,float x2,float y2,float p1,float p2)
{
   return (y2-y1)*(p1-x1)-(x2-x1)*(p2-y1);
}
void algo2(float x1,float y1,float x2,float y2,float x3,float y3,float p1,float p2)
{
   bool r1= crossproduct(x1,y1,x2,y2,p1,p2)>=0;
   bool r2=crossproduct(x2,y2,x3,y3,p1,p2)>=0;
   bool r3=crossproduct(x3,y3,x1,y1,p1,p2)>=0;
   if((r1 && r2 && r3)==0)//All crossproduct outside the plane
      cout<<"Inside/on boundary"<<endl;
   else
      cout<<"Outside"<<endl;
}
int main()
{
	float x1,y1,x2,y2,x3,y3,p1,p2;
	cout<<"Enter points of triangle\n";
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	cout<<"Enter the points\n";
	cin>>p1>>p2;
	algo1(x1,y1,x2,y2,x3,y3,p1,p2);//Considering sum of area
    //algo2(x1,y1,x2,y2,x3,y3,p1,p2);//COnsidering dot product on the same side.
}