#include <iostream>
#include <graphics.h>

using namespace std;

void drawLine(int x1, int y1, int x2, int y2, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
    setcolor(WHITE);
}

void liangBarsky(int x1, int y1, int x2, int y2, int xmin, int ymin, int xmax, int ymax) {
    int p[4], q[4];
    int dx = x2 - x1, dy = y2 - y1;
    p[0] = -dx; q[0] = x1 - xmin;
    p[1] = dx; q[1] = xmax - x1;
    p[2] = -dy; q[2] = y1 - ymin;
    p[3] = dy; q[3] = ymax - y1;

    float u1 = 0, u2 = 1;

    for (int i = 0; i < 4; i++) {
        if (p[i] == 0) {
            if (q[i] < 0) {
                return; // Line lies completely outside the window
            }
        } else {
            float t = (float)q[i] / p[i];
            if (p[i] < 0) {
                u1 = max(u1, t);
            } else {
                u2 = min(u2, t);
            }
        }
    }

    if (u1 > u2) {
        return; // Line lies completely outside the window
    }

    int cx1 = x1 + u1 * dx;
    int cy1 = y1 + u1 * dy;
    int cx2 = x1 + u2 * dx;
    int cy2 = y1 + u2 * dy;

    drawLine(x1, y1, cx1, cy1, RED);
    drawLine(cx1, cy1, cx2, cy2, GREEN);
    drawLine(cx2, cy2, x2, y2, RED);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 50, y1 = 50, x2 = 300, y2 = 250;
    int xmin = 80, ymin = 80, xmax = 200, ymax = 250;

    rectangle(xmin, ymin, xmax, ymax);
    liangBarsky(x1, y1, x2, y2, xmin, ymin, xmax, ymax);

    getch();
    closegraph();
    return 0;
}
