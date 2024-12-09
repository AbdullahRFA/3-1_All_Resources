#include <graphics.h>
#include <cmath>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 0, y1 = 0;
    int x2 = 100, y2 = 50;

    // Calculate the rotation angle in radians
    float angle = 30.0f * M_PI / 180.0f;

    // Apply rotation transformation to each point of the line
    float rotatedX1 = x1 * cos(angle) - y1 * sin(angle);
    float rotatedY1 = x1 * sin(angle) + y1 * cos(angle);

    float rotatedX2 = x2 * cos(angle) - y2 * sin(angle);
    float rotatedY2 = x2 * sin(angle) + y2 * cos(angle);

    // Draw the rotated line
    line(round(rotatedX1), round(rotatedY1), round(rotatedX2), round(rotatedY2));

    delay(5000);
    closegraph();
    return 0;
}

