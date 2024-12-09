#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;
void drawEllipseScanConversion(int centerX, int centerY, int a, int b) {
    int x = 0;
    int y = b;

    int aSq = a * a;
    int bSq = b * b;

    int twoASq = 2 * aSq;
    int twoBSq = 2 * bSq;

    int decision = bSq - aSq * b + aSq / 4;

    while (twoBSq * x < twoASq * y) {
        putpixel(centerX + x, centerY + y, WHITE);
        putpixel(centerX - x, centerY + y, WHITE);
        putpixel(centerX + x, centerY - y, WHITE);
        putpixel(centerX - x, centerY - y, WHITE);

        if (decision <= 0) {
            x++;
            decision += twoBSq * x + bSq;
        } else {
            x++;
            y--;
            decision += twoBSq * x - twoASq * y + bSq;
        }
    }

    decision = bSq * (x + 0.5) * (x + 0.5) + aSq * (y - 1) * (y - 1) - aSq * bSq;

    while (y >= 0) {
        putpixel(centerX + x, centerY + y, WHITE);
        putpixel(centerX - x, centerY + y, WHITE);
        putpixel(centerX + x, centerY - y, WHITE);
        putpixel(centerX - x, centerY - y, WHITE);

        if (decision > 0) {
            y--;
            decision += aSq - twoASq * y;
        } else {
            y--;
            x++;
            decision += twoBSq * x - twoASq * y + aSq;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int centerX, centerY, a, b;
    cout << "Enter center coordinates (x, y): ";
    cin >> centerX >> centerY;
    cout << "Enter semi-major axis (a): ";
    cin >> a;
    cout << "Enter semi-minor axis (b): ";
    cin >> b;

    drawEllipseScanConversion(centerX, centerY, a, b);

    getch();
    closegraph();
    return 0;
}
