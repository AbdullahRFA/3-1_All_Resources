#include <iostream>
#include <graphics.h>

void drawCircle(int radius, int xc, int yc) {
    int x = 0;
    int y = radius;
    int d = 1 - radius;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    while (x <= y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        if (d < 0) {
            d += 2 * x + 3;
        }
        else {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }

    getch();

    closegraph();
}

int main() {
    int radius;

    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    int xc = 250;
    int yc = 250;
    drawCircle(radius, xc, yc);

    return 0;
}

