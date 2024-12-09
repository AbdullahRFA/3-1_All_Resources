#include <math.h>
#include <conio.h>
#include <graphics.h>
#include<bits/stdc++.h>
#define PI acos(-1)
using namespace std;
void drawline(double x0, double y0, double x1, double y1)
{
    double dx, dy, p, x, y;
    dx=x1-x0;
    dy=y1-y0;
    x=x0;
    y=y0;
    p=2*dy-dx;
    while(x<x1)
    {
        if(p>=0)
        {
            putpixel(x,y,RED);
            y=y+1;
            p=p+2*dy-2*dx;
        }
        else
        {
            putpixel(x,y,RED);
            p=p+2*dy;
        }
        x=x+1;
    }
}

int main()
{
    int gd=0,gm,x1,y1,x2,y2,x3,x4,y3,y4;
    double s,c, angle;
    initgraph(&gd,&gm,"C:\\Tc\\BGI");
    x1=0,y1=0,x2=100,y2=150;
    printf("(x1,y1)=(%d, %d) and (x2,y2)=(%d,%d)\n",x1,y1,x2,y2);
    drawline(x1,y1,x2,y2);
    setcolor(CYAN);
    angle=30;
    c = cos(angle * PI /180);
    s = sin(angle * PI /180);
    x3 = floor(x1 * c + y1 * s);
    y3 = floor(-x1 * s + y1 * c);
    x4 = floor(x2 * c + y2 * s);
    y4 = floor(-x2 * s + y2 * c);
    printf("After 30degree rotation keeping (x1,y1) unchanged (x2,y2)=(%d, %d)",x4,y4);
    drawline(x1,y1,x4,y4);
    getch();
    closegraph();
    return 0;
}

