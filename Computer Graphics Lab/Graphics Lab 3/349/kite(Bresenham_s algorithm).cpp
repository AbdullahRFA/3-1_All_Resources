#include <stdio.h>
#include<graphics.h>
#include <math.h>

void drawLineBresenham(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x, y;
    int p;

    int xStep, yStep;
    if(x1<x2)
    {
        xStep=1;
    }
    else
    {
        xStep=-1;
    }
    if(y1<y2)
    {
        yStep=1;
    }
    else
    {
        yStep=-1;
    }

    if(dx >= dy)
    {
        p = 2*dy-dx;
        y = y1;
        for (x=x1; x!=x2; x+=xStep)
        {
            putpixel(x, y, WHITE);
            if (p >= 0)
            {
                y += yStep;
                p -= 2 * dx;
            }
            p+=2*dy;
        }
    }
    else
    {
        p = 2*dx-dy;
        x = x1;
        for (y=y1; y!=y2; y+=yStep)
        {
            putpixel(x, y, WHITE);
            if (p >= 0)
            {
                x+=xStep;
                p-=2 * dy;
            }
            p+=2*dx;
        }
    }
}

int main()
{
    int x[4] = {50, 100, 50, 0};
    int y[4] = {0, 40, 200, 40};

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    for (int i = 0; i < 4; i++)
    {
        int x0 = x[i];
        int y0 = y[i];
        int x1 = x[(i + 1) % 4];
        int y1 = y[(i + 1) % 4];
        drawLineBresenham(x0, y0, x1, y1);
    }

    delay(5000);
    closegraph();
    return 0;
}

