#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main()
{
    float x1,y1,x2,y2,x,y;
    cout<<"Enter starting point (x,y) = ";
    cin>>x1>>y1;
    cout<<"Enter Ending point (x,y) = ";
    cin>>x2>>y2;

    int dx = x2-x1;
    int dy = y2-y1;

    if(dx>0)x=1;
    else x=-1;
    if(dy>0)y=1;
    else y=-1;

    dx=abs(dx);
    dy=abs(dy);

    int gd = DETECT, gm;

    initgraph(&gd,&gm,"");


    while(1)
    {
        putpixel(x1,y1,WHITE);

        if(x1==x2 && y1==y2)
            break;

        int P = 2*(dy-dx);

        if(P> -dy)
        {
            P=P-dy;
            x1=x1+x;
        }
        if(P<dx)
        {
            P=P+dx;
            y1=y+y1;
        }
    }
    getch();
    closegraph();




}
