
#include <iostream>
#include <graphics.h>

void translateLine(int x1, int y1, int x2, int y2, float translateX) {
    int newX1 = x1 + translateX;
    int newY1 = y1;
    int newX2 = x2 + translateX;
    int newY2 = y2;

    line(newX1, newY1, newX2, newY2);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 0, y1 = 0, x2 = 100, y2 = 50;

    line(x1, y1, x2, y2);

    float translateX = 0.75 * x2; // 75% of x2
    translateLine(x1, y1, x2, y2, translateX);

    getch();
    closegraph();

    return 0;
}
