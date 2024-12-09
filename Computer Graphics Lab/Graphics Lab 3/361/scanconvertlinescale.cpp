#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<algorithm>
using namespace std;

int main()
{
    int xp,yp,ds,dt,d,xp1,xp2,yp1,yp2,dx,dy;
    double x1,y1,x2,y2,sf,sx,sy;
    printf("Enter the coordinates of the starting point of the line: ");
    scanf("%lf%lf",&x1,&y1);
    printf("Enter the coordinates of the ending point of the line: ");
    scanf("%lf%lf",&x2,&y2);
    printf("Enter the scaling factor: ");
    scanf("%lf",&sf);
    sx=sf;
    sy=sf;
    xp1=floor((x1*sx)+0.5);
    yp1=floor((y1*sy)+0.5);
    xp2=floor((x2*sx)+0.5);
    yp2=floor((y2*sy)+0.5);
    dx=xp2-xp1;
    dy=yp2-yp1;
    dt=2*(dy-dx);
    ds=2*dy;
    d=2*dy-dx;
    initwindow(1000,600);
    putpixel(xp1,yp1,LIGHTBLUE);
    xp=xp1;
    yp=yp1;
    while(xp<xp2)
    {
        xp++;
        if(d<0)
        {
            d+=ds;
        }
        else
        {
            yp++;
            d+=dt;
        }
        putpixel(xp,yp,LIGHTBLUE);
    }
    getch();
    return 0;
}

