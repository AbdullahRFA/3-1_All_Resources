#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
void drawLine(int x0,int y0,int x1,int y1)
{
    int dx=x1-x0;
    int dy=y1-y0;

    int sx=(x0<x1)? 1:-1;
    int sy=(y0<y1)? 1:-1;
    int errorr= dx-dy;
//    int x=x1;
//    int y=y1;

    while(true)
    {
        putpixel(x0,y0,WHITE);
        if(x0==x1 && y0==y1) break;
        int dt= 2*errorr;
        if(dt>-dy)
        {
            errorr-=dy;
            x0+=sx;
        }
        if(dt<dx)
        {
            errorr+=dx;
            y0+=sy;
        }
    }
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    int x0,y0,x1,y1;
    cout<<"starting point : ";
    cin>>x0>>y0;
    cout<<"ending point : ";
    cin>>x1>>y1;
    //cout<<"line coordinates: "<<endl;
    drawLine(x0,y0,x1,y1);
    delay(50000000);
    closegraph();
    return 0;

    return 0;
}
