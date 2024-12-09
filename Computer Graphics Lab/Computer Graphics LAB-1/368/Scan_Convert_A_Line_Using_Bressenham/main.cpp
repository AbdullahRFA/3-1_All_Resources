#include <graphics.h>
#include <iostream>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;
    std::cout << "Enter the coordinates of the starting point (x1, y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Enter the coordinates of the ending point (x2, y2): ";
    std::cin >> x2 >> y2;

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x, y;

    if (x1 < x2) {
        x = x1;
        y = y1;
    } else {
        x = x2;
        y = y2;
        x2 = x1;
        y2 = y1;
    }

    int p = 2 * dy - dx;
    putpixel(x, y, WHITE);

    while (x < x2) {
        x++;
        if (p < 0) {
            p += 2 * dy;
        } else {
            y++;
            p += 2 * (dy - dx);
        }
        putpixel(x, y, WHITE);
    }

    delay(5000*3600);
    closegraph();
    return 0;
}
