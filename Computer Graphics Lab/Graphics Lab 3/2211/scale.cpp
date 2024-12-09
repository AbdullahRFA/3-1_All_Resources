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
    double sf;
    int x3,y3,x4,y4;
    cout<<"Enter start point: ";
    cin>>x1>>y1;
    cout<<"Enter end point: ";
    cin>>x2>>y2;
    cout<<"Enter the scaling factor:";
    cin>>sf;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");
    setcolor(YELLOW);
bresenhamline(x1,y1,x2,y2);
 //x3=x1*(1+sf);
 x3=x1+(x1*sf);
 y3=y1+(y1*sf);
 x4=x2+(x2*sf);
 y4=y2-(y2*sf);
 //line(x3,y3,x4,y4);
   //y3=y1*(1+sf);
   //x4=x2*(1+sf);
   //y4=y2*(1+sf);
bresenhamline(x3,y3,x4,y4);
//scale(x1,y1,x2,y2,sf);

    getch();
    closegraph();
    return 0;
}

