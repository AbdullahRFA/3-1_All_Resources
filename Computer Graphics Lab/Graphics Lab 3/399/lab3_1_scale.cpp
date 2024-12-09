#include <graphics.h>
#include <cmath>

void scale(int& x, int& y, double factor) {
    x = round(x * factor);
    y = round(y * factor);
}

void drawScaledLine(int x0, int y0, int x1, int y1, double scale_factor) {
    scale(x0, y0, scale_factor);
    scale(x1, y1, scale_factor);

    line(x0, y0, x1, y1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    drawScaledLine(0, 0, 100, 50, 0.5);

    getch();
    closegraph();
    return 0;

}

