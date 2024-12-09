#include <iostream>
#include <graphics.h>
using namespace std;
const int x_MAX = 300;
const int x_MIN = 50;
const int y_MAX = 500;
const int y_MIN = 250;
bool clipT(double s, double u, double& t1, double& t2)
{
    double r;
    if (s < 0.0)
        {
        r = u / s;
        if (r > t2)
           {
                return false;
           }
        if (r > t1)
        {
            t1 = r;
        }
    }
    else if (s > 0.0)
    {
        r = u / s;
        if (r < t1)
          {
                return false;
          }
        if (r < t2)
         {
             t2 = r;
         }
    }
    else if (u < 0.0)
    {
        return false;
    }
    return true;
}
void liangBarskyClip(double x1, double y1, double x2, double y2)
{
    double t1 = 0.0, t2 = 1.0, dx = x2 - x1, dy;
    if (clipT(-dx, x1 - x_MIN, t1, t2) && clipT(dx, x_MAX - x1, t1, t2))
        {
        dy = y2 - y1;
        if (clipT(-dy, y1 - y_MIN, t1, t2) &&
            clipT(dy, y_MAX - y1, t1, t2))
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
    rectangle(x_MIN, y_MIN, x_MAX, y_MAX);
   line(0, 300, 150, 550);
    line(150, 450, 350, 600);
    line(100, 350, 250, 300);
    line(250, 100, 350, 350);
    line(0, 550, 100, 700);
    int fillGd = DETECT, fillGm;
    initgraph(&fillGd, &fillGm, " ");
    initwindow(1000, 1000);
    rectangle(x_MIN, y_MIN, x_MAX, y_MAX);
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
