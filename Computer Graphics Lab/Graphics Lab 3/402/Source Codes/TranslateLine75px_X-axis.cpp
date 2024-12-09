#include <graphics.h>
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    // Scan Convert a line object from (0, 0) to (100, 50)
    line(0, 0, 100, 50);
    // Translate the line on the x-axis by 75 pixels
    int x0, y0, x1, y1;
    x0 = 0; y0 = 0; x1 = 100; y1 = 50;
    int translation_x = 75;
    x0 += translation_x;
    x1 += translation_x;
    line(x0, y0, x1, y1);
    getch();
    closegraph();
    return 0;
}
