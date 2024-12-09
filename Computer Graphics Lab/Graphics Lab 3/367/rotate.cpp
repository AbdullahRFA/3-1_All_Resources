#include <graphics.h>
#include <cmath>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 0, y1 = 0;
    int x2 = 100, y2 = 50;

    // Calculate the slope and intercept of the line
    float dx = x2 - x1;
    float dy = y2 - y1;
    float slope = dy / dx;

    // Determine the number of steps to take based on the greater difference (dx or dy)
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // Calculate the increment values for x and y
    float xIncrement = dx / steps;
    float yIncrement = dy / steps;

    // Scan convert the line
    float x = x1, y = y1;
    for (int i = 0; i <= steps; ++i) {
        putpixel(round(x), round(y), WHITE);
        x += xIncrement;
        y += yIncrement;
    }

    delay(5000);
    closegraph();
    return 0;
}
