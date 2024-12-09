#include <graphics.h>
#include <iostream>
#include <cmath>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 0, y1 = 0, x2 = 100, y2 = 50;

    // Original line
    line(x1, y1, x2, y2);

    // Rotate by 30 degrees
    float theta = 30 * (M_PI / 180);  // Convert degrees to radians
    int new_x1 = round(x1 * cos(theta) - y1 * sin(theta));
    int new_y1 = round(x1 * sin(theta) + y1 * cos(theta));
    int new_x2 = round(x2 * cos(theta) - y2 * sin(theta));
    int new_y2 = round(x2 * sin(theta) + y2 * cos(theta));

    // Rotated line
    line(new_x1, new_y1, new_x2, new_y2);

    delay(5000*3600);
    closegraph();
    return 0;
}

