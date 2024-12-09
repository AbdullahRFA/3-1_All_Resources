#include <iostream>
#include <graphics.h>
using namespace std;
const int xmax = 300;
const int xmin = 50;
const int ymax = 500;
const int ymin = 250;
bool clipT(double p, double q, double& t1, double& t2)
{
    double r;
    if (p<0.0)
        {
        r=q/p;
        if (r>t2)
           {
                return false;
           }
        if (r>t1)
        {
            t1=r;
        }
    }
    else if (p>0.0)
    {
        r=q/p;
        if (r<t1)
          {
                return false;
          }
        if (r<t2)
         {
             t2=r;
         }
    }
    else if (q<0.0)
    {
        return false;
    }
    return true;
}
void liangBarskyClip(double x1, double y1, double x2, double y2)
{
    double t1=0.0, t2=1.0, dx=x2 - x1,dy;
    if (clipT(-dx,x1-xmin,t1,t2) && clipT(dx,xmax-x1,t1,t2))
        {
        dy=y2-y1;
        if (clipT(-dy,y1-ymin,t1,t2) &&
            clipT(dy,ymax-y1,t1,t2))
            {
            if (t2<1.0)
                {
                x2=x1+t2*dx;
                y2=y1+t2*dy;
            }
            if (t1>0.0)
            {
                x1+=t1*dx;
                y1+=t1*dy;
            }
            line(x1,y1,x2,y2);
        }
    }
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    initwindow(1000, 1000);
    rectangle(xmin, ymin, xmax, ymax);
   line(0, 300, 150, 550);
    line(150, 450, 350, 600);
    line(100, 350, 250, 300);
    line(250, 100, 350, 350);
    line(0, 550, 100, 700);
    int fillGd = DETECT, fillGm;
    initgraph(&fillGd, &fillGm, " ");
    initwindow(1000, 1000);
    rectangle(xmin,ymin,xmax,ymax);
    liangBarskyClip(0, 300, 150, 550);
    liangBarskyClip(150, 450, 350, 600);
    liangBarskyClip(100, 350, 250, 300);
    liangBarskyClip(250, 100, 350, 350);
    liangBarskyClip(0, 550, 100, 700);
    getch();
    closegraph();
    closegraph();
    return 0;
}
