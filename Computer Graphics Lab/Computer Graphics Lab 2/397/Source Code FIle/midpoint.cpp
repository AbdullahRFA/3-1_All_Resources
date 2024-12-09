#include <iostream>
#include <graphics.h>

// Function to plot points in all octants
void plotPoints(int xc, int yc, int x, int y)
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

// Midpoint Circle Drawing Algorithm
void midpointCircle(int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int p = 1 - r;

    // Plot the first point
    plotPoints(xc, yc, x, y);

    while (x < y)
    {
        x++;

        if (p < 0)
            p += 2 * x + 1;
        else
        {
            y--;
            p += 2 * (x - y) + 1;
        }

        // Plot points in all octants
        plotPoints(xc, yc, x, y);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = 320;  // X-coordinate of the center
    int yc = 240;  // Y-coordinate of the center
    int r = 100;   // Radius of the circle

    midpointCircle(xc, yc, r);

    delay(5000);
    closegraph();

    return 0;
}

