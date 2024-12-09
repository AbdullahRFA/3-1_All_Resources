#include <graphics.h>

void drawEllipseMidpoint(int xc, int yc, int rx, int ry) {
    int x = 0;              // Initial x-coordinate of the ellipse's point
    int y = ry;             // Initial y-coordinate of the ellipse's point

    // Initialize decision parameters
    int decisionParameter1 = ry * ry - rx * rx * ry + rx * rx / 4;
    int decisionParameter2;

    // Region 1
    while (2 * ry * ry * x < 2 * rx * rx * y) {
        // Plot points in Region 1
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        // Update x and decision parameters
        x++;
        decisionParameter1 += 2 * ry * ry * x + ry * ry;
        if (decisionParameter1 >= 0) {
            y--;
            decisionParameter1 -= 2 * rx * rx * y;
        }
    }

    // Region 2
    decisionParameter2 = ry * ry * (x + 0.5) * (x + 0.5) +
                         rx * rx * (y - 1) * (y - 1) - rx * rx * ry * ry;
    while (y >= 0) {
        // Plot points in Region 2
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        // Update y and decision parameters
        y--;
        decisionParameter2 -= 2 * rx * rx * y - rx * rx;
        if (decisionParameter2 <= 0) {
            x++;
            decisionParameter2 += 2 * ry * ry * x;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = 250;   // X-coordinate of the ellipse's center
    int yc = 250;   // Y-coordinate of the ellipse's center
    int rx = 150;   // X-axis radius of the ellipse
    int ry = 100;   // Y-axis radius of the ellipse

    drawEllipseMidpoint(xc, yc, rx, ry);

    getch();
    closegraph();
    return 0;
}

