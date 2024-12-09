#include <graphics.h>
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int x = 100; // X-coordinate of the point
    int y = 100; // Y-coordinate of the point

    putpixel(x, y, WHITE); // Draw the point at (x, y) with white color

    delay(5000); // Delay to show the output

    closegraph();
    return 0;
}
