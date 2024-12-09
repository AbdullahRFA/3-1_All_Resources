#include <graphics.h>
#include <cmath>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 0, y1 = 0;
    int x2 = 100, y2 = 50;

    // Calculate the scaling factors
    float scaleX = 0.5f;
    float scaleY = 0.5f;

    // Apply scaling transformation to each point of the line
    float scaledX1 = x1 * scaleX;
    float scaledY1 = y1 * scaleY;

    float scaledX2 = x2 * scaleX;
    float scaledY2 = y2 * scaleY;

    // Draw the scaled line
    line(round(scaledX1), round(scaledY1), round(scaledX2), round(scaledY2));

    delay(5000);
    closegraph();
    return 0;
}

