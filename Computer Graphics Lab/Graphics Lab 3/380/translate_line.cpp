
#include <stdio.h>
#include <math.h>
#include <graphics.h>

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

void translateLine(int *x1, int *y1, int *x2, int *y2, int dx, int dy) {
    *x1 += dx;
    *y1 += dy;
    *x2 += dx;
    *y2 += dy;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 0, y1 = 0;
    int x2 = 100, y2 = 50;
    int translation = 75;

    drawLine(x1, y1, x2, y2);
    translateLine(&x1, &y1, &x2, &y2, translation, 0);
    drawLine(x1, y1, x2, y2);

    getch();
    closegraph();

    return 0;
}
