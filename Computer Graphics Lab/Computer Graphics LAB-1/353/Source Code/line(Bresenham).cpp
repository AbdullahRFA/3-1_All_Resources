#include<bits/stdc++.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
using namespace std;
int main()
{
    int gd = DETECT ,gm;
    float x, y,dx,dy,step;
    int x0, x1, y0, y1,i,p;
    initgraph(&gd, &gm, "");
    setbkcolor(WHITE);
    cout<<"Enter co-ordinates for first point: ";
    cin>>x0>>y0;
    cout<<"Enter co-ordinates for second point: ";
    cin>>x1>>y1;
    dx = (float)(x1 - x0);
    dy = (float)(y1 - y0);
    p=(2*dy)-dx;
    x = x0;
    y = y0;
    i = 1;
    while(x<x1)
    {
         if(p>=0)
        {
            putpixel(x,y,BLUE);
            y=y+1;
            p=p+(2*dy)-(2*dx);
        }
        else
        {
            putpixel(x,y,7);
            p=p+2*dy;}
            x=x+1;
    }
    getch();
    closegraph();
    return 0;
}

