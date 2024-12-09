#include<bits/stdc++.h>
#include <iostream>
#include <graphics.h>
#include <conio.h>

void plotEllipsePoints(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

void scanConvertEllipse(int xc, int yc, int rx, int ry)
{
    int rx2 = rx * rx;
    int ry2 = ry * ry;
    int twoRx2 = 2 * rx2;
    int twoRy2 = 2 * ry2;
    int p;
    int x = 0;
    int y = ry;
    int px = 0;
    int py = twoRx2 * y;

    plotEllipsePoints(xc, yc, x, y);

    // Region 1
    p = round(ry2 - (rx2 * ry) + (0.25 * rx2));
    while (px < py)
    {
        x++;
        px += twoRy2;
        if (p < 0)
        {
            p += ry2 + px;
        }
        else
        {
            y--;
            py -= twoRx2;
            p += ry2 + px - py;
        }
        plotEllipsePoints(xc, yc, x, y);
    }

    // Region 2
    p = round(ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2);
    while (y > 0)
    {
        y--;
        py -= twoRx2;
        if (p > 0)
        {
            p += rx2 - py;
        }
        else
        {
            x++;
            px += twoRy2;
            p += rx2 - py + px;
        }
        plotEllipsePoints(xc, yc, x, y);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = 200;  // x-coordinate of the ellipse center
    int yc = 200;  // y-coordinate of the ellipse center
    int rx = 100;  // x-radius of the ellipse
    int ry = 50;   // y-radius of the ellipse

    scanConvertEllipse(xc, yc, rx, ry);

    getch();
    closegraph();
    return 0;
}
