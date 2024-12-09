#include <iostream>
#include <graphics.h>  // You may need to install a graphics library like "graphics.h" for drawing pixels

void drawCircle(int xc, int yc, int radius)
{
    int x = 0;
    int y = radius;
    int d = 1 - radius;

    while (x <= y)
    {
        // Plot the symmetric pixels in each octant
        putpixel(xc + x, yc + y, WHITE);  // Octant 1
        putpixel(xc - x, yc + y, WHITE);  // Octant 2
        putpixel(xc + x, yc - y, WHITE);  // Octant 8
        putpixel(xc - x, yc - y, WHITE);  // Octant 7
        putpixel(xc + y, yc + x, WHITE);  // Octant 3
        putpixel(xc - y, yc + x, WHITE);  // Octant 4
        putpixel(xc + y, yc - x, WHITE);  // Octant 6
        putpixel(xc - y, yc - x, WHITE);  // Octant 5

        // Update the decision parameter and coordinates
        if (d <= 0)
        {
            d += 2 * x + 1;
            x++;
        }
        else
        {
            d += 2 * (x - y) + 1;
            x++;
            y--;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");  // Initialize graphics mode

    int centerX = 200;  // x-coordinate of the center
    int centerY = 200;  // y-coordinate of the center
    int radius = 100;   // radius of the circle

    drawCircle(centerX, centerY, radius);

    getch();  // Wait for a key press
    closegraph();  // Close graphics mode

    return 0;
}

