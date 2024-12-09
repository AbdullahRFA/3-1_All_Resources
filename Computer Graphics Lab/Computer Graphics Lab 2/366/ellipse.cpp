#include <iostream>
#include <graphics.h>

void scanConvertEllipse(int xc, int yc, int rx, int ry) {
    int x, y, p;
    int rx2, ry2, twoRx2, twoRy2;

    rx2 = rx * rx;
    ry2 = ry * ry;
    twoRx2 = 2 * rx2;
    twoRy2 = 2 * ry2;

    x = 0;
    y = ry;

    // Region 1
    p = ry2 - (rx2 * ry) + (0.25 * rx2);
    while (twoRx2 * y >= twoRy2 * x) {
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc - x, yc + y, WHITE);

        x++;
        if (p < 0)
            p += ry2 * (2 * x + 1);
        else {
            y--;
            p += ry2 * (2 * x + 1) - twoRx2 * y;
        }
    }

    // Region 2
    p = ry2 * (x + 0.5) * (x + 0.5) + rx2 * (y - 1) * (y - 1) - rx2 * ry2;
    while (y >= 0) {
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc - x, yc + y, WHITE);

        y--;
        if (p > 0)
            p += rx2 * (1 - 2 * y);
        else {
            x++;
            p += rx2 * (1 - 2 * y) + twoRy2 * x;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = 320;  // X coordinate of the center
    int yc = 240;  // Y coordinate of the center
    int rx = 150;  // Major radius
    int ry = 100;  // Minor radius

    scanConvertEllipse(xc, yc, rx, ry);

    delay(5000);  // Delay for 5 seconds
    closegraph();
    return 0;
}
