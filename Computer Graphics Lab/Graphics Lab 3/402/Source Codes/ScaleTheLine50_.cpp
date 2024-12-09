#include <graphics.h>
#include <math.h>
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    // Scan Convert a line object from (0, 0) to (100, 50)
    line(0, 0, 100, 50);
    // Scale the line to 50%
    float scale = 0.5;
    int new_x0 = round(new_x0 * scale);
    int new_y0 = round(new_y0 * scale);
    int new_x1 = round(new_x1 * scale);
    int new_y1 = round(new_y1 * scale);
    line(new_x0, new_y0, new_x1, new_y1);
    getch();
    closegraph();
    return 0;
}
