#include <iostream>
#include <graphics.h>

void drawLine(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        putpixel(x0, y0, WHITE);

        if (x0 == x1 && y0 == y1)
            break;

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

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;

    int topX = centerX;
    int topY = centerY - 100;
    int leftX = centerX - 100;
    int leftY = centerY;
    int bottomX = centerX;
    int bottomY = centerY + 100;
    int rightX = centerX + 100;
    int rightY = centerY;

    drawLine(topX, topY, leftX, leftY);
    drawLine(leftX, leftY, bottomX, bottomY);
    drawLine(bottomX, bottomY, rightX, rightY);
    drawLine(rightX, rightY, topX, topY);

    delay(5000);
    closegraph();

    return 0;
}