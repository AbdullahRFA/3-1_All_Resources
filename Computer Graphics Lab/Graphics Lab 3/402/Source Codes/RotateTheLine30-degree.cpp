#include <graphics.h>
#include <math.h>
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    // Scan Convert a line object from (0, 0) to (100, 50)
    line(0, 0, 100, 50);
    // Rotate the line by 30 degrees
    int angle = 30;
    float radian = angle * (M_PI / 180.0);
    int x0 = 0, y0 = 0, x1 = 100, y1 = 50;
    int new_x0 = round(x0 * cos(radian) - y0 * sin(radian));
    int new_y0 = round(x0 * sin(radian) + y0 * cos(radian));
    int new_x1 = round(x1 * cos(radian) - y1 * sin(radian));
    int new_y1 = round(x1 * sin(radian) + y1 * cos(radian));
    line(new_x0, new_y0, new_x1, new_y1);
    getch();
    closegraph();
    return 0;
}
