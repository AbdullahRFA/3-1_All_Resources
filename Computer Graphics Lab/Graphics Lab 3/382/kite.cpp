#include <iostream>
#include <cmath>
#include <graphics.h>

const int WIDTH = 800;
const int HEIGHT = 250;

void setPixel(int x, int y)
{
    std::cout << "\033[" << y << ";" << x << "H*";
}

void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true)
    {
        putpixel(x1, y1,BLUE);

        if (x1 == x2 && y1 == y2)
            break;

        int err2 = 2 * err;

        if (err2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }

        if (err2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int midX = WIDTH / 2;
    int midY = HEIGHT / 2;

    // Draw the vertical line
    drawLine(midX, 0, midX, midY);

    // Draw the upper diagonal line
    drawLine(midX, midY, midX + midY, midY * 2);

    // Draw the lower diagonal line
    drawLine(midX, midY, midX - midY, midY * 2);

    // Draw the horizontal line
    drawLine(midX - midY, midY * 2, midX + midY, midY * 2);
    delay(100000);
    closegraph();

    return 0;
}
