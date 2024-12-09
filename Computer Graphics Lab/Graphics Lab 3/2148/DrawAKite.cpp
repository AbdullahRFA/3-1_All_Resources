#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
void drawline(int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y;
    dx=x1-x0;
    dy=y1-y0;
    x=x0;
    y=y0;
    p=2*dy-dx;
    while(x<x1)
    {
        if(p>=0)
        {
            putpixel(x,y,9);
            y=y+1;
            p=p+2*dy-2*dx;
        }
        else
        {
            putpixel(x,y,9);
            p=p+2*dy;
        }
        x=x+1;
    }
}
void kite()
{
    line(200,200,300,100);
    line(300,100,400,200);
    line(400,200,300,300);
    line(300,100,300,300);
    line(300,300,200,200);
    arc(300,300,45,135,140);
    setfillstyle(SOLID_FILL,12);

    floodfill(301,105,WHITE);
    setfillstyle(SOLID_FILL,12);

    floodfill(299,105,WHITE);
    setfillstyle(SOLID_FILL,WHITE);

    floodfill(299,275,WHITE);
    setfillstyle(SOLID_FILL,WHITE);

    floodfill(301,275,WHITE);
    line(300,300,250,350);
    line(250,350,350,350);
    line(300,300,350,350);
    setfillstyle(SOLID_FILL,GREEN);

    floodfill(300,310,WHITE);
}

int main()
{
    int gd=DETECT, gm;
    initgraph(&gd,&gm,"");

    kite();
    getch();
    //closegraph();
    return 0;
}
