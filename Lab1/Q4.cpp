#include<bits/stdc++.h>
using namespace std;
float area(float x1, float y1, float x2, float y2, float x3, float y3)
{
	return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
}
bool algo1(float x1,float y1,float x2,float y2,float x3,float y3,float p1,float p2)
{
   float A = area (x1, y1, x2, y2, x3, y3); 
   float A1 = area (p1,p2, x2, y2, x3, y3);  
   float A2 = area (x1, y1,p1,p2, x3, y3); 
   float A3 = area (x1, y1, x2, y2, p1, p2); 
   if(A==A1+A2+A3)
   	return 1;
   else
   	return 0;
}
int min(float x1,float x2,float x3)
{
 if(x1<=x2 && x1<=x3)
   return x1;
 else if(x2<=x1 && x2<=x3)
   return x2;
 return x3;
}
int max(float x1,float x2,float x3)
{
 if(x1>=x2 && x1>=x3)
   return x1;
 else if(x2>=x1 && x2>=x3)
   return x2;
 return x3;
}
int minbound(float x1,float x2,float y1,float y2,float x3,float y3)
{
   int minx=min(x1,x2,x3);
   int miny=min(y1,y2,y3);
   int maxx=max(x1,x2,x3);
   int maxy=max(y1,y2,y3);
   for(int p1=minx;p1<=maxx;p1++)
   {for(int p2=miny;p2<=maxy;p2++)
     if(algo1(x1,y1,x2,y2,x3,y3,p1,p2)==1)
         cout<<"("<<p1<<","<<p2<<")"<<" ";
      cout<<"\n";
   }
}
int opminbound(float x1,float x2,float y1,float y2,float x3,float y3)
{
   int minx=min(x1,x2,x3);
   int miny=min(y1,y2,y3);
   int maxx=max(x1,x2,x3);
   int maxy=max(y1,y2,y3);
   for(int p1=minx;p1<=maxx;p1++)
   {
      cout<<"\n";
      int flag=0;
      for(int p2=miny;p2<=maxy;p2++)
         {
            int ans=algo1(x1,y1,x2,y2,x3,y3,p1,p2);
            if(ans==1)
               {flag=1;cout<<"("<<p1<<","<<p2<<")"<<" ";continue;}
            if(ans==0 && flag==1)
               break;
         }
   }
}
int Bruteforce(float x1,float x2,float y1,float y2,float x3,float y3)
{
   int mincoord=-100;int maxcoord=100;
   for(int p1=mincoord;p1<=maxcoord;p1++)
   {for(int p2=mincoord;p2<=maxcoord;p2++)
     if(algo1(x1,y1,x2,y2,x3,y3,p1,p2)==1)
         cout<<"("<<p1<<","<<p2<<")"<<" ";
   }
   cout<<"\n";
}
int main()
{
	float x1,y1,x2,y2,x3,y3;
	cout<<"Enter points of triangle\n";
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
   cout<<"Min Bounding Answer:\n";
   minbound(x1,x2,y1,y2,x3,y3);
   cout<<"\n";
   // cout<<"optimal Minimum Bounding Answer:\n";
   // opminbound(x1,x2,y1,y2,x3,y3);
   cout<<"\n";
   // Bruteforce(x1,x2,y1,y2,x3,y3);
   // cout<<"\n";
}