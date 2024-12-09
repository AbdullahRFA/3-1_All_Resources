#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Original line endpoints
    int x1 = 0, y1 = 0;
    int x2 = 100, y2 = 50;

    // Translation distance on the x-axis
    int translationX = 75;

    // Translated line endpoints
    int translated_x1 = x1 + translationX;
    int translated_x2 = x2 + translationX;

    // Draw the translated line
    line(translated_x1, y1, translated_x2, y2);

    getch();
    closegraph();

    return 0;
}
