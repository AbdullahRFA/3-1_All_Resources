#include<graphics.h>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
   int gd = DETECT, gm;

   initgraph(&gd, &gm, "C:\\TC\\BGI");
float x = 200, y = 200;
        putpixel (x, y, WHITE);


   getch();
   closegraph();
   return 0;
}
