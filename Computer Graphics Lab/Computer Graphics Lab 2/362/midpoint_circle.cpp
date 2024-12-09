#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;
// Function to draw a circle using Midpoint Circle Algorithm
void drawCircle(int xc, int yc, int radius)
{
    int x = 0;
    int y = radius;
    int p = 1 - radius;

    // Set initial point
    putpixel(xc + x, yc + y, WHITE);

    while (x < y)
    {
        x++;

        if (p < 0)
        {
            p += 2 * x + 1;
        }
        else
        {
            y--;
            p += 2 * (x - y) + 1;
        }

        // Plotting points in all octants
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc,yc,radius;
    cin>> xc>> yc>> radius;
//    int xc = 250;   // X-coordinate of the center of the circle
//    int yc = 250;   // Y-coordinate of the center of the circle
//    int radius = 100;   // Radius of the circle

    drawCircle(xc, yc, radius);

    delay(50000000000);
    closegraph();

    return 0;
}

