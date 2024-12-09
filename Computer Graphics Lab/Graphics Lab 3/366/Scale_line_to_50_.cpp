#include <iostream>
#include <graphics.h>

void scaleLine(int x1, int y1, int x2, int y2, float scaleFactor) {
    int newX1 = x1 * scaleFactor;
    int newY1 = y1 * scaleFactor;
    int newX2 = x2 * scaleFactor;
    int newY2 = y2 * scaleFactor;

    line(newX1, newY1, newX2, newY2);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 0, y1 = 0, x2 = 100, y2 = 50;


    float scaleFactor = 0.5;
    scaleLine(x1, y1, x2, y2, scaleFactor);

    getch();
    closegraph();

    return 0;
}
