#include<bits/stdc++.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
using namespace std;
int main()
{
    int gd = DETECT ,gm;
    float x, y,dx,dy,step;
    int x0, x1, y0, y1,i;
    initgraph(&gd, &gm, "");
    setbkcolor(WHITE);
    cout<<"Enter the two end points of the line: ";
    cin>>x0>>y0>>x1>>y1;
    dx = (float)(x1 - x0);
    dy = (float)(y1 - y0);
    if(dx>=dy){
        step = dx;
    }
    else{
        step = dy;
    }
    dx = dx/step;
    dy = dy/step;
    x = x0;
    y = y0;
    i = 1;
    while(i<= step)
    {
        putpixel(x, y, RED);
        x += dx;
        y += dy;
        i=i+1;
    }
    getch();
    closegraph();
    return 0;
}
