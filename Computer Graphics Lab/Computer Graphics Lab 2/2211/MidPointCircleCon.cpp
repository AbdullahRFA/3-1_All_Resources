#include<iostream>
#include<graphics.h>
using namespace std;

void drawcircle(int xc,int yc,int x,int y)
{
    putpixel(xc+x,yc+y,YELLOW);
    putpixel(xc+x,yc-y,YELLOW);
    putpixel(xc-x,yc+y,YELLOW);
    putpixel(xc-x,yc-y,YELLOW);
    putpixel(xc+y,yc+x,YELLOW);
    putpixel(xc+y,yc-x,YELLOW);
    putpixel(xc-y,yc+x,YELLOW);
    putpixel(xc-y,yc-x,YELLOW);
}
int main()
{
    int xc,yc,r,x,y,p;
    cout<<"Enter center coordinates (xc, yc) and radious(r): ";
    cin>>xc>>yc>>r;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");
    setcolor(YELLOW);
    x=0;y=r;
    p=1-r;
    while(x<=y)
    {
        drawcircle(xc,yc,x,y);
        x++;
        if(p<0)
        {
            p=p+(2*x)+1;
        }
        else
        {
            y--;
            p=p+2*(x-y)+1;
        }
        drawcircle(xc,yc,x,y);
    }
    getch();
    closegraph();
    return 0;


}
