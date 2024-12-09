
#include <graphics.h>

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;
    int err2;

    while (true) {
        putpixel(x1, y1, WHITE);

        if (x1 == x2 && y1 == y2)
            break;

        err2 = 2 * err;

        if (err2 > -dy) {
            err -= dy;
            x1 += sx;
        }

        if (err2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = getmaxx() / 2;  // X-coordinate of the center of the screen
    int y = getmaxy() / 2;  // Y-coordinate of the center of the screen

    int length = 100;  // Length of the kite's sides
    int halfLength = length / 2;

    // Draw the lines of the kite
    drawLine(x, y - length, x - halfLength, y);
    drawLine(x, y - length, x + halfLength, y);
    drawLine(x - halfLength, y, x, y + length);
    drawLine(x + halfLength, y, x, y + length);

    delay(5000);
    closegraph();
    return 0;
}
