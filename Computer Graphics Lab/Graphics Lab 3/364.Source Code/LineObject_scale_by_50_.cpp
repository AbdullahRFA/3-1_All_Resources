#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main()
{
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"");

   int x1=0,y1=0,x2=100,y2=50;

   line(x1,y1,x2,y2);// Draw the original line

   // Calculate the scaled coordinates
   int new_x1=x1*0.5;
   int new_y1=y1*0.5;
   int new_x2=x2*0.5;
   int new_y2=y2*0.5;

   line(new_x1,new_y1,new_x2,new_y2);// Draw the scaled line

   getch();
   closegraph();
   return 0;
}
