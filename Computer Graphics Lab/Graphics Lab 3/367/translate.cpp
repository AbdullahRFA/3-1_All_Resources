
#include <graphics.h>
#include <cmath>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 0, y1 = 0;
    int x2 = 100, y2 = 50;

    // Translation offset on the X-axis
    int translationX = 75;

    // Apply translation transformation to each point of the line
    int translatedX1 = x1 + translationX;
    int translatedY1 = y1;

    int translatedX2 = x2 + translationX;
    int translatedY2 = y2;

    // Draw the translated line
    line(translatedX1, translatedY1, translatedX2, translatedY2);

    delay(5000);
    closegraph();
    return 0;
}
