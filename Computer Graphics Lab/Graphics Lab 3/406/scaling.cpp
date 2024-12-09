#include <graphics.h>

void drawLine(int x0, int y0, int x1, int y1, char color) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;

    int err = dx - dy;
    int prev_x = x0, prev_y = y0;

    while (true) {
            if(color == 'w')
        putpixel(prev_x, prev_y, WHITE);
    else putpixel(prev_x, prev_y, RED);

        if (prev_x == x1 && prev_y == y1) {
            break;
        }

        int e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            prev_x += sx;
        }

        if (e2 < dx) {
            err += dx;
            prev_y += sy;
        }
    }
}

void scaleLine(int *x0, int *y0, int *x1, int *y1, double scaling) {
    *x0 = static_cast<int>(*x0 * scaling);
    *y0 = static_cast<int>(*y0 * scaling);
    *x1 = static_cast<int>(*x1 * scaling);
    *y1 = static_cast<int>(*y1 * scaling);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x0 = 0, y0 = 0;
    int x1 = 100, y1 = 50;

    drawLine(x0, y0, x1, y1, 'w');

    // Scale the line to 50%
    double scaling = 0.5;

    scaleLine(&x0, &y0, &x1, &y1, scaling);

    setcolor(RED);
     //x0 = 150, y0 = 50;
    drawLine(x0, y0, x1, y1, 'r');

    delay(100000);
    closegraph();

    return 0;
}
