#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main()
{
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"");

   int x1=0,y1=0,x2=100,y2=50;

   line(x1,y1,x2,y2);// Draw the original line

   // Convert degrees to radians
   float angle=30.0;
   float theta=angle*M_PI/180.0;

   // Calculate the rotated coordinates
   int new_x1=round(x1*cos(theta)-y1*sin(theta));
   int new_y1=round(x1*sin(theta)+y1*cos(theta));
   int new_x2=round(x2*cos(theta)-y2*sin(theta));
   int new_y2=round(x2*sin(theta)+y2*cos(theta));

   // Draw the rotated line
   line(new_x1,new_y1,new_x2,new_y2);

   getch();
   closegraph();
   return 0;
}