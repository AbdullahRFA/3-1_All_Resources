#include <graphics.h>
#include <iostream>

void drawEllipse(int xc, int yc, int rx, int ry) {
    int x = 0, y = ry;
    int p = ry * ry - rx * rx * ry + rx * rx / 4;
    while (2 * x * ry * ry <= 2 * y * rx * rx) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        if (p < 0) {
            x = x + 1;
            p = p + 2 * ry * ry * x + ry * ry;
        } else {
            x = x + 1;
            y = y - 1;
            p = p + 2 * ry * ry * x - 2 * rx * rx * y - ry * ry;
        }
    }
    p = ry * ry * (x + 0.5) * (x + 0.5) + rx * rx * (y - 1) * (y - 1) - rx * rx * ry * ry;
    while (y >= 0) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        if (p > 0) {
            y = y - 1;
            p = p - 2 * rx * rx * y + rx * rx;
        } else {
            y = y - 1;
            x = x + 1;
            p = p + 2 * ry * ry * x - 2 * rx * rx * y + rx * rx;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    // Accepting user input for ellipse parameters
    int centerX, centerY, radiusX, radiusY;
    std::cout << "Enter the center coordinates (xc, yc) of the ellipse: ";
    std::cin >> centerX >> centerY;
    std::cout << "Enter the radius along the x-axis (rx): ";
    std::cin >> radiusX;
    std::cout << "Enter the radius along the y-axis (ry): ";
    std::cin >> radiusY;

    drawEllipse(centerX, centerY, radiusX, radiusY);

    getch();
    closegraph();
    return 0;
}
