#include <iostream>
#include <graphics.h>


void plotEllipsePoints(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
}

void drawEllipse(int xc, int yc, int rx, int ry)
{
    int x = 0;
    int y = ry;


    int rxSq = rx * rx;
    int rySq = ry * ry;
    int twoRxSq = 2 * rxSq;
    int twoRySq = 2 * rySq;
    int p;
    int px = 0;
    int py = twoRxSq * y;


    plotEllipsePoints(xc, yc, x, y);


    p = rySq - (rxSq * ry) + (0.25 * rxSq);
    while (px < py)
    {
        x++;
        px += twoRySq;

        if (p < 0)
        {
            p += rySq + px;
        }
        else
        {
            y--;
            py -= twoRxSq;
            p += rySq + px - py;
        }

        plotEllipsePoints(xc, yc, x, y);
    }


    p = rySq * (x + 0.5) * (x + 0.5) + rxSq * (y - 1) * (y - 1) - rxSq * rySq;
    while (y > 0)
    {
        y--;
        py -= twoRxSq;

        if (p > 0)
        {
            p += rxSq - py;
        }
        else
        {
            x++;
            px += twoRySq;
            p += rxSq - py + px;
        }

        plotEllipsePoints(xc, yc, x, y);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = 250;
    int yc = 250;
    int rx = 150;
    int ry = 100;

    drawEllipse(xc, yc, rx, ry);


    getch();
    closegraph();

    return 0;
}
