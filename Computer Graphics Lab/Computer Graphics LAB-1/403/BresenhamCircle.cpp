#include <iostream>
#include <cmath>
#include <graphics.h>
 using namespace std;
void drawCircleBresenham(int xc, int yc, int radius) {
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
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int xc, yc, radius;
    cout << "Enter the coordinates of the center (xc, yc): ";
    cin >> xc >> yc;
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    drawCircleBresenham(xc, yc, radius);
    delay(500000000);
    closegraph();
    return 0;
}
