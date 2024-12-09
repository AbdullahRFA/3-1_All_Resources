#include <iostream>
#include <cmath>
#include <graphics.h>

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int slopeX = (x2 > x1) ? 1 : -1;
    int slopeY = (y2 > y1) ? 1 : -1;
    int error = dx - dy;

    int x = x1;
    int y = y1;

    while (true) {
        putpixel(x, y, WHITE);

        if (x == x2 && y == y2)
            break;

        int doubleError = 2 * error;

        if (doubleError > -dy) {
            error -= dy;
            x += slopeX;
        }

        if (doubleError < dx) {
            error += dx;
            y += slopeY;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100, y1 = 100;
    int x2 = 500, y2 = 300;

    drawLineBresenham(x1, y1, x2, y2);

    getch();
    closegraph();

    return 0;
}
