#include <iostream>
#include <graphics.h>
using namespace std;

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        putpixel(x1, y1, WHITE);

        if (x1 == x2 && y1 == y2)
            break;

        int err2 = 2 * err;

        if (err2 > -dy) {
            err -= dy;
            x1 += sx;
        }

        if (err2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

int main() {
    int x1 = 100, y1 = 100;
    int x2 = 400, y2 = 300;
    cout<<"Enter X1 value and Y1 vale : ";
    cin>>x1>>y1;
    cout<<"Enter X2 value Y2 value : ";
    cin>>x2>>y2;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    drawLineBresenham(x1, y1, x2, y2);

    delay(200000);
    closegraph();

    return 0;
}

