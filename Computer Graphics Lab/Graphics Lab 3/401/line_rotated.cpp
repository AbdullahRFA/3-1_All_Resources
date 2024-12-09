#include <iostream>
#include <cmath>
#include <graphics.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


void drawLine(int xStart, int yStart, int xEnd, int yEnd) {
    int dx = abs(xEnd - xStart);
    int dy = abs(yEnd - yStart);
    int xStep = (xStart < xEnd) ? 1 : -1;
    int yStep = (yStart < yEnd) ? 1 : -1;

    int error = dx - dy;

    while (xStart != xEnd || yStart != yEnd) {
        putpixel(xStart, yStart, WHITE);

        int doubleError = error * 2;

        if (doubleError > -dy) {
            error -= dy;
            xStart += xStep;
        }

        if (doubleError < dx) {
            error += dx;
            yStart += yStep;
        }
    }

    putpixel(xEnd, yEnd, WHITE);
}

void rotatePoint(int& x, int& y, double angle) {
    double radian = angle * (M_PI / 180.0);
    double cosine = cos(radian);
    double sine = sin(radian);

    int newX = round(x * cosine - y * sine);
    int newY = round(x * sine + y * cosine);

    x = newX;
    y = newY;
}

void drawRotatedLine(int xStart, int yStart, int xEnd, int yEnd, double angle) {
    rotatePoint(xStart, yStart, angle);
    rotatePoint(xEnd, yEnd, angle);

    drawLine(xStart, yStart, xEnd, yEnd);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xStart = 0;
    int yStart = 0;
    int xEnd = 100;
    int yEnd = 50;
    double rotationAngle = 30.0;

    drawRotatedLine(xStart, yStart, xEnd, yEnd, rotationAngle);

    getch();
    closegraph();

    return 0;
}

