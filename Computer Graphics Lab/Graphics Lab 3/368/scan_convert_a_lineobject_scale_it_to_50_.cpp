#include <graphics.h>

void drawScaledLine(int x1, int y1, int x2, int y2, float scaleFactor) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Scale the coordinates
    int scaledX1 = x1 * scaleFactor;
    int scaledY1 = y1 * scaleFactor;
    int scaledX2 = x2 * scaleFactor;
    int scaledY2 = y2 * scaleFactor;

    // Scan convert the scaled line using Bresenham's algorithm
    int dx = abs(scaledX2 - scaledX1);
    int dy = abs(scaledY2 - scaledY1);
    int p = 2 * dy - dx;
    int twoDy = 2 * dy;
    int twoDyMinusDx = 2 * (dy - dx);
    int x, y, xEnd;

    if (scaledX1 > scaledX2) {
        x = scaledX2;
        y = scaledY2;
        xEnd = scaledX1;
    } else {
        x = scaledX1;
        y = scaledY1;
        xEnd = scaledX2;
    }

    while (x <= xEnd) {
        // Plot the scaled coordinates
        putpixel(x, y, WHITE);

        // Move to the next pixel
        x++;

        // Update the decision parameter
        if (p < 0)
            p += twoDy;
        else {
            y++;
            p += twoDyMinusDx;
        }
    }

    delay(5000*3600); // Delay to show the output
    closegraph();
}

int main() {
    int x1 = 0, y1 = 0;
    int x2 = 100, y2 = 50;
    float scaleFactor = 0.5;

    drawScaledLine(x1, y1, x2, y2, scaleFactor);

    return 0;
}

