#include<bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#include <graphics.h>

using namespace std;

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) {
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

void drawKite(int x, int y, int width, int height) {
    int x1 = x;
    int y1 = y + height / 2;
    int x2 = x + width / 2;
    int y2 = y;
    int x3 = x + width;
    int y3 = y + height / 2;
    int x4 = x + width / 2;
    int y4 = y + height;

    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x3, y3);
    drawLine(x3, y3, x4, y4);
    drawLine(x4, y4, x1, y1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = 100;
    int y = 100;
    int width = 200;
    int height = 300;

    drawKite(x, y, width, height);

    getch();
    closegraph();

    return 0;
}
