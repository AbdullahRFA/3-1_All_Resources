#include <iostream>
#include <graphics.h>
#include <cmath>

void rotatePoint(int x, int y, int cx, int cy, float angle, int& newX, int& newY) {
    float radians = angle * M_PI / 180.0;
    float cosine = cos(radians);
    float sine = sin(radians);

    newX = round((x - cx) * cosine - (y - cy) * sine) + cx;
    newY = round((x - cx) * sine + (y - cy) * cosine) + cy;
}

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int steps = dx > dy ? dx : dy;

    float xIncrement = (x2 - x1) / (float)steps;
    float yIncrement = (y2 - y1) / (float)steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);

        x += xIncrement;
        y += yIncrement;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 0, y1 = 0;
    int x2 = 100, y2 = 50;

    int centerX = 0, centerY = 0;
    int rotatedX, rotatedY;

    float rotationAngle = 30.0;

    rotatePoint(x1, y1, centerX, centerY, rotationAngle, rotatedX, rotatedY);
    x1 = rotatedX;
    y1 = rotatedY;

    rotatePoint(x2, y2, centerX, centerY, rotationAngle, rotatedX, rotatedY);
    x2 = rotatedX;
    y2 = rotatedY;

    drawLine(x1, y1, x2, y2);

    getch();
    closegraph();

    return 0;
}
