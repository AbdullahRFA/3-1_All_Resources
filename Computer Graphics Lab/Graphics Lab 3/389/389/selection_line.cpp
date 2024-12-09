
#include <iostream>
#include <graphics.h>

void scaleLine(int x1, int y1, int x2, int y2, float scale) {
    int newX1 = x1 * scale;
    int newY1 = y1 * scale;
    int newX2 = x2 * scale;
    int newY2 = y2 * scale;

    line(newX1, newY1, newX2, newY2);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Original line coordinates
    int x1 = 0, y1 = 0, x2 = 100, y2 = 50;

    // Draw the original line
    line(x1, y1, x2, y2);

    // Scale the line to 50%
    float scale = 0.5;
    scaleLine(x1, y1, x2, y2, scale);

    getch();
    closegraph();

    return 0;
}
