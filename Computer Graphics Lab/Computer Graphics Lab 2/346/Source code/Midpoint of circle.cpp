#include<bits/stdc++.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
using namespace std;
 int main()
 {
     int xc,yc,x,y,r,gd=DETECT,gm,d;
     cout<<"Enter radius of a circle: ";
     cin>>r;
     x=0;
     y=r;
     d=1-r;
     initgraph(&gd,&gm,"");
     cout<<"Enter the center coordinates of the circle: ";
     cin>>xc>>yc;
     do
     {
         putpixel(xc+x,yc+y,4);
         putpixel(xc+x,yc-y,4);
         putpixel(xc-x,yc+y,4);
         putpixel(xc-x,yc-y,4);
         putpixel(xc+y,yc+x,4);
         putpixel(xc+y,yc-x,4);
         putpixel(xc-y,yc+x,4);
         putpixel(xc-y,yc-x,4);
         if(d<0)
         {
             x=x+1;
             y=y;
             d=d+2*x+2;
         }
         else
         {
             x=x+1;
             y=y-1;
             d=d+2*(x-y)+1;
         }}
         while(x<y);
         getch();
         closegraph();
     }
