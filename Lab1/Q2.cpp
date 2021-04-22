#include<bits/stdc++.h>
using namespace std;
void find(float x1,float y1,float x2,float y2,float p1,float p2)
{
   float m=(y2-y1)*1.0/(x2-x1);
   float C=y1-m*x1;
   float res=p2-m*p1-C; 
   if(res==0)
   	cout<<"On the line"<<endl;
   else if(res>0)
   	cout<<"Above line"<<endl;
   else
   	cout<<"Below Line"<<endl;
}
int main()
{
	float x1,y1,x2,y2,p1,p2;
	cout<<"Enter points of line\n";
	cin>>x1>>y1>>x2>>y2;
	cout<<"Enter the points\n";
	cin>>p1>>p2;
	find(x1,y1,x2,y2,p1,p2);//Using equation of the line.
}