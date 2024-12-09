#include <graphics.h>
#include<windows.h>
#include <iostream>

int main() {
    //DWORD screenWidth=GetSystemMetrics(SM_CXSCREEN);
    //DWORD screenHeight=GetSystemMetrics(SM_CYSCREEN);
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc, yc, radius;
    std::cout << "Enter the coordinates of the center (xc, yc): ";
    std::cin >> xc >> yc;
    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

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
            d += 4 * x + 6;
        } else {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }

    delay(500000);

    closegraph();
    return 0;
}
