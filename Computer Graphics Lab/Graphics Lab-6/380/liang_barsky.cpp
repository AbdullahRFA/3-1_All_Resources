#include <bits/stdc++.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>
using namespace std;

int main()
{
    int i, gd = DETECT, gm;
    int x1[5], y1[5], x2[5], y2[5], xmin, xmax, ymin, ymax, xx1, xx2, yy1, yy2, dx, dy;
    float t1, t2, p[4], q[4], temp;

    // Initialize five pairs of points
    x1[0] = 100;
    y1[0] = 120;
    x2[0] = 300;
    y2[0] = 300;

    x1[1] = 50;
    y1[1] = 200;
    x2[1] = 400;
    y2[1] = 200;

    x1[2] = 150;
    y1[2] = 50;
    x2[2] = 150;
    y2[2] = 400;

    x1[3] = 50;
    y1[3] = 50;
    x2[3] = 350;
    y2[3] = 350;

    x1[4] = 200;
    y1[4] = 150;
    x2[4] = 200;
    y2[4] = 400;

    xmin = 100;
    ymin = 100;
    xmax = 250;
    ymax = 250;

    initgraph(&gd, &gm, "c:\\turboc3\\bgi");
    rectangle(xmin, ymin, xmax, ymax);

    for (int j = 0; j < 5; j++)
    {
        dx = x2[j] - x1[j];
        dy = y2[j] - y1[j];
        p[0] = -dx;
        p[1] = dx;
        p[2] = -dy;
        p[3] = dy;
        q[0] = x1[j] - xmin;
        q[1] = xmax - x1[j];
        q[2] = y1[j] - ymin;
        q[3] = ymax - y1[j];
        for (i = 0; i < 4; i++)
        {
            if (p[i] == 0)
            {
                cout << "line is parallel to one of the clipping boundary\n";
                if (q[i] >= 0)
                {
                    if (i < 2)
                    {
                        if (y1[j] < ymin)
                        {
                            y1[j] = ymin;
                        }
                        if (y2[j] > ymax)
                        {
                            y2[j] = ymax;
                        }
                        line(x1[j], y1[j], x2[j], y2[j]);
                    }
                    if (i > 1)
                    {
                        if (x1[j] < xmin)
                        {
                            x1[j] = xmin;
                        }
                        if (x2[j] > xmax)
                        {
                            x2[j] = xmax;
                        }
                        line(x1[j], y1[j], x2[j], y2[j]);
                    }
                }
            }
        }
        t1 = 0;
        t2 = 1;
        for (i = 0; i < 4; i++)
        {
            temp = q[i] / p[i];
            if (p[i] < 0)
            {
                if (t1 <= temp)
                    t1 = temp;
            }
            else
            {
                if (t2 > temp)
                    t2 = temp;
            }
        }
        if (t1 < t2)
        {
            xx1 = x1[j] + t1 * p[1];
            xx2 = x1[j] + t2 * p[1];
            yy1 = y1[j] + t1 * p[3];
            yy2 = y1[j] + t2 * p[3];
            line(xx1, yy1, xx2, yy2);
        }
    }
    delay(5000);
    closegraph();
}
