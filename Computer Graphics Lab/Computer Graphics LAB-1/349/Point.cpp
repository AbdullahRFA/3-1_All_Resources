#include<stdio.h>
#include<math.h>
#include <graphics.h>

int main()
{
   int x, y;
   float x1, y1;

   printf("Enter the co-ordinate of the point: ");
   scanf("%f %f", &x1, &y1);
   x=floor(x1);
   y=floor(y1);
   int color = WHITE;

   int gd = DETECT, gm;
   initgraph(&gd, &gm, (char*)"");
   putpixel(x, y, color);
   delay(5000);

   closegraph();
   return 0;
}

