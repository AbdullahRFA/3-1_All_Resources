#include <graphics.h>
#include <iostream>
#include <conio.h>
using namespace std;

void drawline(int x0, int y0, int x1, int y1) {
    int dx, dy, p, x, y;
    dx = x1 - x0;
    dy = y1 - y0;
    x = x0;
    y = y0;
    p = 2 * dy - dx;

    while (x < x1) {
        if (p >= 0) {
            putpixel(x, y, BLUE);
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        } else {
            putpixel(x, y, BLUE);
            p = p + 2 * dy;
        }
        x = x + 1;
        delay(10);
    }
}

int main() {
    int gd = DETECT, gm, error, x0, y0, x1, y1;

    cout << "Enter coordinates of first point:";
    cin >> x0 >> y0;

    cout << "Enter coordinates of second point:";
    cin >> x1 >> y1;
    initgraph(&gd, &gm, "");
    drawline(x0, y0, x1, y1);

    getch();
    closegraph();
    return 0;
}
