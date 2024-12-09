#include <graphics.h>

void drawTranslatedLine(int x1, int y1, int x2, int y2, int translation) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Translate the coordinates
    int translatedX1 = x1 + translation;
    int translatedY1 = y1;
    int translatedX2 = x2 + translation;
    int translatedY2 = y2;

    // Scan convert the translated line using Bresenham's algorithm
    int dx = abs(translatedX2 - translatedX1);
    int dy = abs(translatedY2 - translatedY1);
    int p = 2 * dy - dx;
    int twoDy = 2 * dy;
    int twoDyMinusDx = 2 * (dy - dx);
    int x, y, xEnd;

    if (translatedX1 > translatedX2) {
        x = translatedX2;
        y = translatedY2;
        xEnd = translatedX1;
    } else {
        x = translatedX1;
        y = translatedY1;
        xEnd = translatedX2;
    }

    while (x <= xEnd) {
        // Plot the translated coordinates
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

    delay(100000); // Delay to show the output
    closegraph();
}

int main() {
    int x1 = 0, y1 = 0;
    int x2 = 100, y2 = 50;
    int translation = 75;

    drawTranslatedLine(x1, y1, x2, y2, translation);

    return 0;
}

