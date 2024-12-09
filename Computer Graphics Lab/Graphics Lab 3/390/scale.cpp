#include <graphics.h>

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

void scaleLine(int& x0, int& y0, int& x1, int& y1, double scaleFactor) {
    x0 = static_cast<int>(x0 * scaleFactor);
    y0 = static_cast<int>(y0 * scaleFactor);
    x1 = static_cast<int>(x1 * scaleFactor);
    y1 = static_cast<int>(y1 * scaleFactor);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x0 = 0;
    int y0 = 0;
    int x1 = 100;
    int y1 = 150;

    // Scale to 50%
    double scaleFactor = 0.5;
    scaleLine(x0, y0, x1, y1, scaleFactor);

    drawLine(x0, y0, x1, y1);

    getch();
    closegraph();

    return 0;
}

