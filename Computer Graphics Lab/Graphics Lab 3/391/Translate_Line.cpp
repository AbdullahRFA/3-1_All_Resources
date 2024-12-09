#include <iostream>
#include <graphics.h>
#include <cmath>

void plotPixel(int x, int y) {
    putpixel(x, y, WHITE);
}

void drawLine(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        plotPixel(x0, y0);

        if (x0 == x1 && y0 == y1) {
            break;
        }

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

void translateLine(int& x0, int& y0, int& x1, int& y1, int dx) {

    int newX0 = x0 + dx;
    int newY0 = y0;

    int newX1 = x1 + dx;
    int newY1 = y1;

    x0 = newX0;
    y0 = newY0;
    x1 = newX1;
    y1 = newY1;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x0 = 0, y0 = 0;
    int x1 = 100, y1 = 50;

    drawLine(x0, y0, x1, y1);

    translateLine(x0, y0, x1, y1, 75);

    drawLine(x0, y0, x1, y1);



    getch();
    closegraph();
    return 0;
}

