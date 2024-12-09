#include <iostream>
#include <graphics.h>

void scanConvertLine(int xStart, int yStart, int xEnd, int yEnd) {
    int dx = xEnd - xStart;
    int dy = yEnd - yStart;
    int xStep = 1;
    int yStep = 1;

    int p = 2 * dy - dx;

    int x = xStart;
    int y = yStart;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    while (x <= xEnd) {

        putpixel(x, y, WHITE);

        if (p < 0) {
            x += xStep;
            p += 2 * dy;
        } else {
            x += xStep;
            y += yStep;
            p += 2 * dy - 2 * dx;
        }
    }

    getch();
    closegraph();
}

int main() {
    int xStart = 0;
    int yStart = 0;
    int xEnd = 100;
    int yEnd = 50;

    scanConvertLine(xStart, yStart, xEnd, yEnd);

    return 0;
}
