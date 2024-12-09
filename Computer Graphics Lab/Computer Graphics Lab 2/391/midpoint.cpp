#include <iostream>
#include <graphics.h>

void drawCircle(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

void midpointCircle(int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int d = 1 - r;

    drawCircle(xc, yc, x, y);

    while (y > x)
    {
        if (d < 0)
        {
            d += 2 * x + 3;
        }
        else
        {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;

        drawCircle(xc, yc, x, y);
    }
}

int main()
{
    int xc = 320;  // X-coordinate of the center
    int yc = 240;  // Y-coordinate of the center
    int r = 100;   // Radius of the circle

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    midpointCircle(xc, yc, r);

    delay(5000);
    closegraph();

    return 0;
}

