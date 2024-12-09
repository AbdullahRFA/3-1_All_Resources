#include<bits/stdc++.h>
using namespace std;
#include<graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100; // x-coordinate of the starting point
    int y1 = 100; // y-coordinate of the starting point
    int x2 = 300; // x-coordinate of the ending point
    int y2 = 200; // y-coordinate of the ending point

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while (true) {
        putpixel(x1, y1, WHITE);

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }

//    delay(5000); // Pause for 5 seconds
    getch();
    closegraph();
    return 0;
}

