#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main()
 {
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"C:\\TC\\BGI");

   int x1=0,y1=0,x2=100,y2=50;// Define line endpoints

   int translation_amount=(x2-x1)*0.75;// Calculate translation amount for x-axis

   // Translate line on the x-axis
   x1+=translation_amount;
   x2+=translation_amount;

   // Implement line scan conversion algorithm
   int dx=x2-x1;
   int dy=y2-y1;
   int steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
   float xIncrement=dx/(float)steps;
   float yIncrement=dy/(float)steps;
   float x=x1,y=y1;

   for (int i=0;i<=steps;i++)
        {
      putpixel(x,y,WHITE);
      x+=xIncrement;
      y+=yIncrement;
   }

   getch();
   closegraph();
   return 0;
}
