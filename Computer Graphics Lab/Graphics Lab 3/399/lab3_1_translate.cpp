#include <graphics.h>
#include <cmath>

void translate(int& x, int& y, int tx, int ty) {
    x += tx;
    y += ty;
}

void drawTranslatedLine(int x0, int y0, int x1, int y1, int tx, int ty) {
    translate(x0, y0, tx, ty);
    translate(x1, y1, tx, ty);

    line(x0, y0, x1, y1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    drawTranslatedLine(0, 0, 100, 50, 75, 0);

    getch();
    closegraph();
    return 0;
}

