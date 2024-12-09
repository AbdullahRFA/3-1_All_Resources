#include<bits/stdc++.h>
#include<graphics.h>
int main()
{
    int gd=DETECT,gm,i;
    float x,y,dx,dy,step;
    int x0,y0,y1,x1;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    setbkcolor(WHITE);
    x0=100,y0=200,x1=500,y1=300;
    dx=float(x1-x0);
    dy=float(y1-y0);
    if(dx>=dy) step=dx;
    else step=dy;
    dx=dx/step;
    dy=dy/step;
    x=x0,y=y0;
    printf("%f\n",step);
    i=1;
    while(i<=step)
    {
        putpixel(x,y,RED);
        x+=dx;
        y+=dy; i++;
    }
    getch();
    closegraph();
}
