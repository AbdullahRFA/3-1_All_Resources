#include <graphics.h>
#include <cmath>

void rotate(int& x, int& y, double angle) {
    double radians = angle * (M_PI / 180.0);
    double cosAngle = cos(radians);
    double sinAngle = sin(radians);

    int newX = round(x * cosAngle - y * sinAngle);
    int newY = round(x * sinAngle + y * cosAngle);

    x = newX;
    y = newY;
}

void drawLine(int x0, int y0, int x1, int y1, double angle) {
    rotate(x0, y0, angle);
    rotate(x1, y1, angle);

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        putpixel(x0, y0, WHITE);

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

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    drawLine(0, 0, 100, 50, 30);

    getch();
    closegraph();
    return 0;
}

