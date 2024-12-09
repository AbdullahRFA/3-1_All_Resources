
#include <iostream>
#include <graphics.h>
using namespace std;

void drawEllipse(int a, int b) {
    int x = 0;   // x coordinate
    int y = b;   // y coordinate

    int d1 = (b * b) - (a * a * b) + (a * a * 0.25);

    int dx = 2 * b * b * x;
    int dy = 2 * a * a * y;

    while (dx < dy) {
        putpixel(x, y, WHITE);

        if (d1 < 0) {
            x++;
            dx += 2 * b * b;
            d1 += dx + b * b;
        }
        else {
            x++;
            y--;
            dx += 2 * b * b;
            dy -= 2 * a * a;
            d1 += dx - dy + b * b;
        }
    }

    int d2 = ((b * b) * ((x + 0.5) * (x + 0.5))) +
             ((a * a) * ((y - 1) * (y - 1))) -
             (a * a * b * b);

    while (y >= 0) {
        putpixel(x, y, WHITE);

        if (d2 > 0) {
            y--;
            dy -= 2 * a * a;
            d2 += a * a - dy;
        }
        else {
            y--;
            x++;
            dx += 2 * b * b;
            dy -= 2 * a * a;
            d2 += dx - dy + a * a;
        }
    }
}

int main() {


    int a, b;
    cout << "Enter major and minor axis lengths (a and b): ";
    cin >> a >> b;
int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    drawEllipse(a, b);

    getch();
    closegraph();
    return 0;
}
