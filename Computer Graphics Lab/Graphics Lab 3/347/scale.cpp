#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

int main()
{
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    int x1=0,y1=0,x2=100,y2=50;
    line(x1,y1,x2,y2);
    int x1_scaled = x1 * 0.5;
    int y1_scaled = y1 * 0.5;
    int x2_scaled = x2 * 0.5;
    int y2_scaled = y2 * 0.5;

    setcolor(RED);
    line(x1_scaled,y1_scaled,x2_scaled,y2_scaled);

    getch();
    closegraph();
}

