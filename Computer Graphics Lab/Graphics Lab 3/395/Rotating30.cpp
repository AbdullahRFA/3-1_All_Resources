#include <graphics.h>
#include <cmath>

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
    initgraph(&gd, &gm, "");

    int x1 = 0;     // Starting X-coordinate
    int y1 = 0;     // Starting Y-coordinate
    int x2 = 100;   // Ending X-coordinate
    int y2 = 50;     // Ending Y-coordinate

    // Rotate the line by 30 degrees
    double angle = 30 * (3.14159 / 180.0);
    int rotatedX2 = static_cast<int>(x1 + (x2 - x1) * cos(angle) - (y2 - y1) * sin(angle));
    int rotatedY2 = static_cast<int>(y1 + (x2 - x1) * sin(angle) + (y2 - y1) * cos(angle));

    drawLine(x1, y1, rotatedX2, rotatedY2);

    getch();
    closegraph();
    return 0;
}

