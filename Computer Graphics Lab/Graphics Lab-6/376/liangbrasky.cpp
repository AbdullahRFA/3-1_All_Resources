#include <iostream>
#include <cmath>
#include <graphics.h>

using namespace std;

const int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;

int x_min, y_min, x_max, y_max;

int computeCode(int x, int y) {
    int code = 0;
    if (x < x_min)
        code |= LEFT;
    if (x > x_max)
        code |= RIGHT;
    if (y < y_min)
        code |= BOTTOM;
    if (y > y_max)
        code |= TOP;
    return code;
}

void liangBarsky(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;

    while (true) {
        if (!(code1 | code2)) {
            accept = true;
            break;
        } else if (code1 & code2) {
            break;
        } else {
            int codeOut = code1 ? code1 : code2;
            int x, y;

            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            } else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            } else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        line(x1, y1, x2, y2);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    cout << "Enter the coordinates of the clipping window (x_min y_min x_max y_max): ";
    cin >> x_min >> y_min >> x_max >> y_max;

    rectangle(x_min, y_min, x_max, y_max);

    int x1, y1, x2, y2;
    cout << "Enter the endpoints of the line (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    line(x1, y1, x2, y2);

    delay(10000);
    closegraph();
    return 0;
}
