#include <iostream>
#include <graphics.h>

// Bresenham's line algorithm
void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        putpixel(x1, y1, WHITE);

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); // Initialize graphics mode

    int x = getmaxx()/6; // Get the center x-coordinate of the window
    int y = getmaxy()/6; // Get the center y-coordinate of the window

    // Draw the kite shape using Bresenham's algorithm
    drawLine(x, y - 50, x - 50, y);
    drawLine(x - 50, y, x, y + 100);
    drawLine(x, y + 100, x + 50, y);
    drawLine(x + 50, y, x, y - 50);
    //drawLine(x, y - 50, x, y + 50);

    getch();
    closegraph(); // Close graphics mode

    return 0;
}
