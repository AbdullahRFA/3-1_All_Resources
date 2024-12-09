#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <graphics.h>

void drawLineDDA(int x1, int y1, int x2, int y2)
{
   int dx = x2 - x1;
   int dy = y2 - y1;
   int steps;
   if(abs(dx) > abs(dy))
   {
       steps=abs(dx);
   }
   else
   {
       steps=abs(dy);
   }

   float xIncrement = dx/(float)steps;
   float yIncrement = dy/(float)steps;

   float x = x1;
   float y = y1;

   for (int i=0; i<=steps; i++)
   {
      putpixel(round(x), round(y), WHITE);

      x+=xIncrement;
      y+=yIncrement;
   }
}

int main()
{
   float x,y;
   int x1,y1,x2,y2;
   printf("Enter the co-ordinate of the first point of the line: ");
   scanf("%f %f", &x, &y);
   x1=x, y1=y;

   printf("Enter the co-ordinate of the second point of the line: ");
   scanf("%f %f", &x, &y);
   x2=x;y2=y;

   int gd = DETECT, gm;
   initgraph(&gd, &gm, (char*)"");
   drawLineDDA(x1, y1, x2, y2);

   delay(5000);

   closegraph();
   return 0;
}

