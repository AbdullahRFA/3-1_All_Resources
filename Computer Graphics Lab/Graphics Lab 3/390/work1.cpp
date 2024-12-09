#include <graphics.h>
#include <cmath>

void drawLine(int x0, int y0, int x1, int y1) {
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

void rotateLine(int& x, int& y, double angle) {
    double radian = angle * (3.14159 / 180.0);
    int newX = round(x * cos(radian) - y * sin(radian));
    int newY = round(x * sin(radian) + y * cos(radian));
    x = newX;
    y = newY;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x0 = 0;
    int y0 = 0;
    int x1 = 100;
    int y1 = 150;

    // Rotation by 30 degrees
    rotateLine(x0, y0, 30);
    rotateLine(x1, y1, 30);

    drawLine(x0, y0, x1, y1);

    getch();
    closegraph();

    return 0;
}
