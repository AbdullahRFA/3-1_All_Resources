#include <graphics.h>

void drawKite(int x, int y, int width, int height) {
    int x1 = x;
    int x2 = x + width / 2;
    int x3 = x;
    int x4 = x - width / 2;
    int y1 = y - height / 2;
    int y2 = y;
    int y3 = y + height / 2;
    int y4 = y;

    // Draw the lines
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x4, y4);
    line(x4, y4, x1, y1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x = 320; // X-coordinate of the kite's center
    int y = 240; // Y-coordinate of the kite's center
    int width = 150; // Width of the kite
    int height = 300; // Height of the kite

    drawKite(x, y, width, height);

    getch();
    closegraph();
    return 0;
}
