
#include <iostream>
#include <graphics.h>
using namespace std;

void drawCircle(int xc, int yc, int radius) {
    int x = 0;
    int y = radius;
    int p = 1 - radius;

    while (x <= y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
    }
}

int main() {

    int xc, yc, radius;
    cout << "Enter center coordinates (xc and yc): ";
    cin >> xc >> yc;
    cout << "Enter radius: ";
   cin >> radius;
int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    drawCircle(xc, yc, radius);

    getch();
    closegraph();
    return 0;
}

