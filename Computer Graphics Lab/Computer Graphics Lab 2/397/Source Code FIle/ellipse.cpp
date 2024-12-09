#include <iostream>
#include <graphics.h>
#include <conio.h>

// Function to draw ellipse using midpoint algorithm
void drawEllipse(int xc, int yc, int rx, int ry)
{
    int x, y;
    int p;
    int px, py;

    // Initialize starting point
    x = 0;
    y = ry;

    // Calculate initial decision parameter
    p = (ry * ry) - (rx * rx * ry) + ((rx * rx) / 4);

    // Plot the points of first region
    while ((2 * x * ry * ry) < (2 * y * rx * rx))
    {
        // Plot points in Region 1
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        // Checking and updating decision parameter
        if (p < 0)
        {
            x++;
            px = 2 * ry * ry * x;
            p = p + (px + ry * ry);
        }
        else
        {
            x++;
            y--;
            px = 2 * ry * ry * x;
            py = 2 * rx * rx * y;
            p = p + (px - py + ry * ry);
        }
    }

    // Calculate decision parameter for the second region
    p = ((ry * ry) * (x + 0.5) * (x + 0.5)) +
        ((rx * rx) * (y - 1) * (y - 1)) - (rx * rx * ry * ry);

    // Plot the points of the second region
    while (y >= 0)
    {
        // Plot points in Region 2
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        // Checking and updating decision parameter
        if (p > 0)
        {
            y--;
            py = 2 * rx * rx * y;
            p = p + (rx * rx - py);
        }
        else
        {
            y--;
            x++;
            px = 2 * ry * ry * x;
            py = 2 * rx * rx * y;
            p = p + (px - py + rx * rx);
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Set the center and radii of the ellipse
    int centerX = 250;
    int centerY = 250;
    int radiusX = 100;
    int radiusY = 50;

    // Call the function to draw the ellipse
    drawEllipse(centerX, centerY, radiusX, radiusY);

    getch();
    closegraph();
    return 0;
}
