#include <graphics.h>

void drawCircleMidpoint(int xc, int yc, int radius) {
    int x = 0;                      // Initial x-coordinate of the circle's point
    int y = radius;                 // Initial y-coordinate of the circle's point
    int decisionParameter = 1 - radius; // Initial decision parameter

    // Loop until x-coordinate becomes greater than y-coordinate
    while (x <= y) {
        // Plot the circle's points using symmetry
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        // Update x and y based on the decision parameter
        if (decisionParameter < 0) {
            decisionParameter += 2 * x + 3;
        } else {
            decisionParameter += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = 250;   // X-coordinate of the circle's center
    int yc = 250;   // Y-coordinate of the circle's center
    int radius = 100;   // Radius of the circle

    drawCircleMidpoint(xc, yc, radius);

    getch();
    closegraph();
    return 0;
}
