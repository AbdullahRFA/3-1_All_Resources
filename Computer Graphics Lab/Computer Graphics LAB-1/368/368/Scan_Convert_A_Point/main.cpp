#include <graphics.h>
#include <iostream>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x, y;
    std::cout << "Enter the coordinates of the point (x, y): ";
    std::cin >> x >> y;

    putpixel(x, y, YELLOW);

    delay(5000000);
    closegraph();
    return 0;
}
