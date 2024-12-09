#include<stdio.h>
#include<graphics.h>
#include<math.h>

void bresenhamLine(double x1, double y1, double x2, double y2)
{
    int xp1,xp2,yp1,yp2,xp,yp,dx,dy,steps,i;
    double xi,yi,x,y;
    xp1=floor(x1+0.5);
    yp1=floor(y1+0.5);
    xp2=floor(x2+0.5);
    yp2=floor(y2+0.5);
    dx=xp2-xp1;
    dy=yp2-yp1;
    if(abs(dx)>abs(dy))steps=abs(dx);
    else steps=abs(dy);
    xi=dx/(double)steps;
    yi=dy/(double)steps;
    x=xp1;
    y=yp1;
    putpixel(xp1,yp1,LIGHTBLUE);
    for(i=0;i<steps;i++)
    {
        x+=xi;
        y+=yi;
        xp=floor(x+0.5);
        yp=floor(y+0.5);
        putpixel(xp,yp,LIGHTBLUE);
    }
}

int main()
{
    int gd=DETECT,gm;
    double xa,xb,xc,xd,ya,yb,yc,yd;
    printf("Enter the coordinates of point A: ");
    scanf("%lf%lf",&xa,&ya);
    printf("Enter the coordinates of point B: ");
    scanf("%lf%lf",&xb,&yb);
    printf("Enter the coordinates of point C: ");
    scanf("%lf%lf",&xc,&yc);
    printf("Enter the coordinates of point D: ");
    scanf("%lf%lf",&xd,&yd);
    initwindow(1000,600);
    bresenhamLine(xb,yb,xa,ya);
    bresenhamLine(xa,ya,xd,yd);
    bresenhamLine(xb,yb,xc,yc);
    bresenhamLine(xc,yc,xd,yd);
    getch();
    return 0;
}
