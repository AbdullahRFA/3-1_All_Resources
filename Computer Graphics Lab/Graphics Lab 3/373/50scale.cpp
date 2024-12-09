#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Original line endpoints
    int x1 = 0, y1 = 0;
    int x2 = 100, y2 = 50;

    // Scale factor
    float scaleFactor = 0.5;

    // Scaled line endpoints
    int scaled_x1 = x1 * scaleFactor;
    int scaled_y1 = y1 * scaleFactor;
    int scaled_x2 = x2 * scaleFactor;
    int scaled_y2 = y2 * scaleFactor;

    // Draw the scaled line
    line(scaled_x1, scaled_y1, scaled_x2, scaled_y2);

    getch();
    closegraph();
    
    return 0;
}
