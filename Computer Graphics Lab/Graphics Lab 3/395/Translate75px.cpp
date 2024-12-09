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

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 0;     // Starting X-coordinate
    int y1 = 0;     // Starting Y-coordinate
    int x2 = 100;   // Ending X-coordinate
    int y2 = 50;     // Ending Y-coordinate

    // Translate the line by 75 pixels in both x and y directions
    int translatedX1 = x1 + 75;
    int translatedY1 = y1 + 75;
    int translatedX2 = x2 + 75;
    int translatedY2 = y2 + 75;

    drawLine(translatedX1, translatedY1, translatedX2, translatedY2);

    getch();
    closegraph();
    return 0;
}

