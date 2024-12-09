#include <iostream>
using namespace std;
#include<graphics.h>

struct Point
{
    double x, y;
};
bool clipLine(Point &p1, Point &p2, double xMin, double yMin, double xMax, double yMax)
{
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double p[4] = {-dx, dx, -dy, dy};
    double q[4] = {p1.x - xMin, xMax - p1.x, p1.y - yMin, yMax - p1.y};
    double t1 = 0, t2 = 1;
    for (int i = 0; i < 4; ++i)
    {
        if (p[i] == 0)
        {
            if (q[i] < 0)
            {
                return false;
            }
        }
        else
        {
            double t = q[i] / p[i];
            if (p[i] < 0 && t > t1)
            {
                t1 = t;
            }
            else if (p[i] > 0 && t < t2)
            {
                t2 = t;
            }
        }
    }

    if (t1 > t2)
    {
        return false;
    }
    p1.x = p1.x + t1 * dx;
    p1.y = p1.y + t1 * dy;
    p2.x = p1.x + (t2 - t1) * dx;
    p2.y = p1.y + (t2 - t1) * dy;

    return true;
}
int main()
{
    Point p[10]={{-4,2},{-1,7},{-1,5},{3,8},{-2,3},{1,2},{1,-2},{3,3},{-4,7},{-2,10} };
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    double xMin = -3, yMin = 1, xMax = 2, yMax = 6;
    setcolor(RED);
    rectangle(xMin,yMin,xMax,yMax);

    for( int i=0; i<10; i+=2)
    {

        if (clipLine(p[i], p[i+1], xMin, yMin, xMax, yMax))
        {
            cout << "Clipped line: (" << p[i].x << ", " << p[i].y << ") to (" << p[i+1].x << ", " << p[i+1].y << ")\n";
        }
        else
        {
            cout << "Line is completely outside the clipping window.\n";
        }
    }

    return 0;
}
