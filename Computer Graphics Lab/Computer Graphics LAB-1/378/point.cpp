#include <iostream>
#include <graphics.h>

void drawPoint(int x, int y) {
    putpixel(x, y, WHITE);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = 100;
    int y = 100;

    drawPoint(x, y);

    getch();
    closegraph();

    return 0;
}

