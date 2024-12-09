#include <graphics.h>
#include <iostream>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc, yc, a, b;
    std::cout << "Enter the coordinates of the center (xc, yc): ";
    std::cin >> xc >> yc;
    std::cout << "Enter the major axis length (a): ";
    std::cin >> a;
    std::cout << "Enter the minor axis length (b): ";
    std::cin >> b;

    int x = 0;
    int y = b;
    int a_squared = a * a;
    int b_squared = b * b;
    int p = b_squared - a_squared * b + a_squared / 4;

    while (2 * b_squared * x < 2 * a_squared * y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (p < 0) {
            p += 2 * b_squared * x + 3 * b_squared;
        } else {
            p += 2 * b_squared * x - 2 * a_squared * y + 2 * a_squared + 3 * b_squared;
            y--;
        }
        x++;
    }

    p = b_squared * (x + 0.5) * (x + 0.5) + a_squared * (y - 1) * (y - 1) - a_squared * b_squared;

    while (y >= 0) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (p > 0) {
            p += a_squared - 2 * a_squared * y + 3 * a_squared;
        } else {
            p += 2 * b_squared * x - 2 * a_squared * y + 2 * b_squared + 3 * a_squared;
            x++;
        }
        y--;
    }

    delay(5000*3600);
    closegraph();
    return 0;
}
