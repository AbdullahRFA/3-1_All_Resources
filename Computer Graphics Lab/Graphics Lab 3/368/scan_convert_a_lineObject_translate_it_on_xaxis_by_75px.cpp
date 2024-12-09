#include <graphics.h>
#include <iostream>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 0, y1 = 0, x2 = 100, y2 = 50;

    // Original line
    line(x1, y1, x2, y2);

    // Translate on x-axis by 75 pixels
    int translate_x = 75;
    int new_x1 = x1 + translate_x;
    int new_y1 = y1;
    int new_x2 = x2 + translate_x;
    int new_y2 = y2;

    // Translated line
    line(new_x1, new_y1, new_x2, new_y2);

    delay(5000);
    closegraph();
    return 0;
}
