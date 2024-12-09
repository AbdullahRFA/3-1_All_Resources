#include <graphics.h>
#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    int steps, xinc, yinc, dx, dy;

    cout << "Enter the starting coordinates:";
    cin >> x1 >> y1;

    cout << "Enter the ending coordinates:";
    cin >> x2 >> y2;
    initgraph(&gd, &gm, "");
    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy)) {
        steps = abs(dx);
    } else {
        steps = abs(dy);
    }

    xinc = dx / steps;
    yinc = dy / steps;

    for (int i = 1; i <= steps; i++) {
        putpixel(x1, y1, CYAN);
        delay(10);
        x1 = x1 + xinc;
        y1 = y1 + yinc;
    }

    getch();
    closegraph();
    return 0;
}
