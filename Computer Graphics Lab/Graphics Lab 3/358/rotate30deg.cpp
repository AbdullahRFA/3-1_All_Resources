#include <iostream>
#include <graphics.h>
#include <cmath>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 0, y1 = 0;
    int x2 = 100, y2 = 50;

    // Calculate the slope of the line
    float m = static_cast<float>(y2 - y1) / (x2 - x1);

    // Determine the number of steps required
    int n;
    int dx = x2 - x1;
    int dy = y2 - y1;

    if (abs(dx) > abs(dy))
        n = abs(dx);
    else
        n = abs(dy);

    // Determine the increment values for each axis
    float x_inc = static_cast<float>(dx) / n;
    float y_inc = static_cast<float>(dy) / n;

    // Generate the intermediate points along the original line
    float x = x1, y = y1;
    for (int i = 0; i <= n; i++) {
        putpixel(static_cast<int>(x), static_cast<int>(y), WHITE);

        // Increment the coordinates
        x += x_inc;
        y += y_inc;
    }

    // Reset the coordinates to the initial point
    x = x1, y = y1;

    // Generate the intermediate points along the rotated line
    for (int i = 0; i <= n; i++) {
        // Apply rotation by 30 degrees
        float theta = 30 * 3.14159 / 180; // convert to radians
        float x_rot = x * cos(theta) - y * sin(theta);
        float y_rot = x * sin(theta) + y * cos(theta);

        // Draw the rotated point
        putpixel(static_cast<int>(x_rot), static_cast<int>(y_rot), YELLOW);

        // Increment the coordinates
        x += x_inc;
        y += y_inc;
    }

    delay(5000);
    closegraph();
    return 0;
}
