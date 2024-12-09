#include <graphics.h>
#include<bits/stdc++.h>

void drawEllipse(int xc, int yc, int rx, int ry)
{
    int gm, gd;
    initgraph(&gm, &gd, ""); // Initialize graphics mode

    int x = 0;
    int y = ry;
    int rxSq = rx * rx;
    int rySq = ry * ry;
    int twoRxSq = 2 * rxSq;
    int twoRySq = 2 * rySq;
    int p;
    int px = 0;
    int py = twoRxSq * y;

    // Region 1
    p = round(rySq - (rxSq * ry) + (0.25 * rxSq));
    while (px < py)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        x++;
        px += twoRySq;
        if (p < 0)
            p += rySq + px;
        else
        {
            y--;
            py -= twoRxSq;
            p += rySq + px - py;
        }
    }

    // Region 2
    p = round(rySq * (x + 0.5) * (x + 0.5) + rxSq * (y - 1) * (y - 1) - rxSq * rySq);
    while (y >= 0)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        y--;
        py -= twoRxSq;
        if (p > 0)
            p += rxSq - py;
        else
        {
            x++;
            px += twoRySq;
            p += rxSq - py + px;
        }
    }

    getch();
    closegraph(); // Close graphics mode
}

int main()
{
    int xc = 300; // X-coordinate of the center
    int yc = 200; // Y-coordinate of the center
    int rx = 100; // Horizontal radius
    int ry = 50;  // Vertical radius

    drawEllipse(xc, yc, rx, ry);

    return 0;
}

