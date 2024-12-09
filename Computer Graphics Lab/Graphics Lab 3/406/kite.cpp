#include <graphics.h>

void drawLine(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;

    int err = dx - dy;
    int prev_x = x0, prev_y = y0;

    while (true) {
        putpixel(prev_x, prev_y, WHITE);

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

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x_center = 400 / 2;
    int y_center = 400 / 2;

    int x_top = x_center;
    int y_top = y_center - 100;

    int x_bottom = x_center;
    int y_bottom = y_center + 100;

    int x_left = x_center - 100;
    int y_left = y_center;

    int x_right = x_center + 100;
    int y_right = y_center;

    drawLine(x_top, y_top, x_left, y_left);
    drawLine(x_left, y_left, x_bottom, y_bottom);
    drawLine(x_bottom, y_bottom, x_right, y_right);
    drawLine(x_right, y_right, x_top, y_top);
    drawLine(x_top, y_top, x_bottom, y_bottom);
    drawLine(x_left, y_left, x_right, y_right);
    drawLine(x_bottom, y_bottom, x_bottom+40, y_bottom+40);
    drawLine(x_bottom, y_bottom, x_bottom-40, y_bottom+40);
    drawLine(x_bottom+40, y_bottom+40, x_bottom-40, y_bottom+40);

    delay(100000);
    closegraph();

    return 0;
}
