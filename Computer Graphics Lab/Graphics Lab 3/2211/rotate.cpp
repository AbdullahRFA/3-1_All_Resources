#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
void bresenhamline(int x1,int y1 ,int x2,int y2 )
{
    int dx,dy;
    dx=(x2-x1);
    dy=(y2-y1);
    int x=x1,y=y1;
    int dt=2*(abs(dy))-abs(dx);
    int ds=2*abs(dy);
    int d=(2*abs(dy))-abs(dx);
    putpixel(x,y,YELLOW);
    while(x<x2)
    {
        x++;
        if(d<0){d=d+ds;}
        else{y++;d=d+dt;}
        putpixel(x,y,YELLOW);
    }
}


int main()
{
    int x1,x2,y1,y2,dx,dy;
    double c,angle,s;
    cout<<"Enter start point: ";
    cin>>x1>>y1;
    cout<<"Enter end point: ";
    cin>>x2>>y2;
    cout<<"Enter angle: ";
    cin>>angle;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");
    setcolor(YELLOW);
bresenhamline(x1,y1,x2,y2);
c = cos(angle *3.14/180);
    s = sin(angle *3.14/180);
    x1 = floor(x1 * c + y1 * s);
    y1 = floor(-x1 * s + y1 * c);
    x2 = floor(x2 * c + y2 * s);
    y2 = floor(-x2 * s + y2 * c);
    bresenhamline(x1,y1,x2,y2);


    getch();
    closegraph();
    return 0;
}
