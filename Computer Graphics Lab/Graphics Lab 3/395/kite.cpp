#include <graphics.h>

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

void drawKite() {
    int centerX = 320;  // X-coordinate of the kite's center
    int centerY = 240;  // Y-coordinate of the kite's center
    int width = 100;    // Width of the kite
    int height = 150;   // Height of the kite

    int topX = centerX;
    int topY = centerY - (height / 2);
    int bottomX = centerX;
    int bottomY = centerY + (height / 2);
    int leftX = centerX - (width / 2);
    int leftY = centerY;
    int rightX = centerX + (width / 2);
    int rightY = centerY;

    drawLine(topX, topY, leftX, leftY);     // Top to left
    drawLine(topX, topY, rightX, rightY);   // Top to right
    drawLine(bottomX, bottomY, leftX, leftY);   // Bottom to left
    drawLine(bottomX, bottomY, rightX, rightY); // Bottom to right
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    drawKite();

    getch();
    closegraph();
    return 0;
}

