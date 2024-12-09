#include <iostream>
#include <graphics.h>
#include <cmath>

void rotatePoint(int& x, int& y, float angle) {
    float radian = angle * 3.14159 / 180.0;
    float newX = x * cos(radian) - y * sin(radian);
    float newY = x * sin(radian) + y * cos(radian);
    x = (int)newX;
    y = (int)newY;
}

void rotateLine(int x1, int y1, int x2, int y2, float angle) {
    rotatePoint(x1, y1, angle);
    rotatePoint(x2, y2, angle);
    line(x1, y1, x2, y2);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Original line coordinates
    int x1 = 0, y1 = 0, x2 = 100, y2 = 50;

    // Draw the original line
    line(x1, y1, x2, y2);

    // Rotate the line by 30 degrees
    rotateLine(x1, y1, x2, y2, 30);

    getch();
    closegraph();

    return 0;
}

