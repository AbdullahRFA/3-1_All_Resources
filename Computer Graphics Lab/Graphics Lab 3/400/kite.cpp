#include <iostream>
#include <graphics.h>

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x = x1;
    int y = y1;
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int error = dx - dy;

    while (true) {
        putpixel(x, y, WHITE);

        if (x == x2 && y == y2)
            break;

        int e2 = 2 * error;
        if (e2 > -dy) {
            error -= dy;
            x += sx;
        }
        if (e2 < dx) {
            error += dx;
            y += sy;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Coordinates of the kite shape
    int x1 = 100, y1 = 100;
    int x2 = 200, y2 = 200;
    int x3 = 300, y3 = 100;
    int x4 = 200, y4 = 0;

    // Draw lines to form the kite shape
    drawLineBresenham(x1, y1, x2, y2);
    drawLineBresenham(x2, y2, x3, y3);
    drawLineBresenham(x3, y3, x4, y4);
    drawLineBresenham(x4, y4, x1, y1);

    getch();
    closegraph();

    return 0;
}

