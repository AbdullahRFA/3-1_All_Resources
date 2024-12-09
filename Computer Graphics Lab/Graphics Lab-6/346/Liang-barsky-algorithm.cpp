#include <iostream>
#include <graphics.h>
using namespace std;
const int x_max = 300;//R.x=2
const int x_min = 50;//L.x=-3
const int y_max = 500;//R.y=6
const int y_min = 250;//L.y=1
bool clipT(double p, double q, double& t1, double& t2)
{
    double r;
    if (p < 0.0)
        {
        r = q / p;
        if (r > t2)
           {
                return false;
           }
        if (r > t1)
        {
            t1 = r;
        }
    }
    else if (p > 0.0)
    {
        r = q / p;
        if (r < t1)
          {
                return false;
          }
        if (r < t2)
         {
             t2 = r;
         }
    }
    else if (q < 0.0)
    {
        return false;
    }
    return true;
}
void liangBarskyClip(double x1, double y1, double x2, double y2)
{
    double t1 = 0.0, t2 = 1.0, dx = x2 - x1, dy;
    if (clipT(-dx, x1 - x_min, t1, t2) && clipT(dx, x_max - x1, t1, t2))
        {
        dy = y2 - y1;
        if (clipT(-dy, y1 - y_min, t1, t2) &&
            clipT(dy, y_max - y1, t1, t2))
            {
            if (t2 < 1.0)
                {
                x2 = x1 + t2 * dx;
                y2 = y1 + t2 * dy;
            }
            if (t1 > 0.0)
            {
                x1 = x1 + t1 * dx;
                y1 = y1 + t1 * dy;
            }
            line(x1, y1, x2, y2);
        }
    }
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    initwindow(1000, 1000);
     setcolor(RED);
    rectangle(x_min, y_min, x_max, y_max);
    setcolor(YELLOW);
   line(0, 300, 150, 550);//A(-4,2), B(-1,7) 0, 300, 150, 550
    line(150, 450, 350, 600);//C(-1,5), D(3,8)  150, 450, 350, 600
    line(250, 100, 350, 350);//G(1,-2), H(3,3)  250, 100, 350, 350
    line(0, 550, 100, 700);//I(-4,7), J(-2,10)   0, 550, 100, 700
    int fillGd = DETECT, fillGm;
    initgraph(&fillGd, &fillGm, " ");
    initwindow(1000, 1000);
     setcolor(WHITE);
    rectangle(x_min, y_min, x_max, y_max);
    setcolor(YELLOW);
    liangBarskyClip(0, 300, 150, 550);
    liangBarskyClip(150, 450, 350, 600);
    liangBarskyClip(100, 350, 250, 300);
    liangBarskyClip(250, 100, 350, 350);
    liangBarskyClip(0, 550, 100, 700);
    getch();
    closegraph();
     closegraph();

}
