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

void translateLine(int& x0, int& y0, int& x1, int& y1, int tx) {
    x0 += tx;
    x1 += tx;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x0 = 0;
    int y0 = 0;
    int x1 = 100;
    int y1 = 150;

    // Translate on the x-axis by 75 pixels
    int tx = 75;
    translateLine(x0, y0, x1, y1, tx);

    drawLine(x0, y0, x1, y1);

    getch();
    closegraph();

    return 0;
}

