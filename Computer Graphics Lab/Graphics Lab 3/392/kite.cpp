#include <iostream>
#include <graphics.h>

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x = x1, y = y1;
    int xInc = (x2 >= x1) ? 1 : -1;
    int yInc = (y2 >= y1) ? 1 : -1;

    if (dx >= dy) {
        int p = 2 * dy - dx;
        while (x != x2) {
            putpixel(x, y, WHITE);
            if (p >= 0) {
                y += yInc;
                p -= 2 * dx;
            }
            x += xInc;
            p += 2 * dy;
        }
    } else {
        int p = 2 * dx - dy;
        while (y != y2) {
            putpixel(x, y, WHITE);
            if (p >= 0) {
                x += xInc;
                p -= 2 * dy;
            }
            y += yInc;
            p += 2 * dx;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Kite coordinates
    int topX = 250, topY = 100;
    int leftX = 150, leftY = 250;
    int rightX = 350, rightY = 250;
    int bottomX = 250, bottomY = 400;

    // Draw the kite using Bresenham line algorithm
    drawLine(topX, topY, leftX, leftY);
    drawLine(leftX, leftY, bottomX, bottomY);
    drawLine(bottomX, bottomY, rightX, rightY);
    drawLine(rightX, rightY, topX, topY);

    getch();
    closegraph();

    return 0;
}

