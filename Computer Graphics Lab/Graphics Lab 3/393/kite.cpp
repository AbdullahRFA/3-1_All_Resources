#include <iostream>
#include <graphics.h>
#include<math.h>
void drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        putpixel(x1, y1, WHITE);

        if (x1 == x2 && y1 == y2) {
            break;
        }

        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

double dist(double x1,double y1,double x2,double y2)
{
    double d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    return d;
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int centerX = getmaxx() / 2;
    int centerY = getmaxy() / 2;
    int width = 300;
    int height = 300;
    int topX = centerX;
    int topY = centerY - height / 2;
    int leftX = centerX - width / 2;
    int leftY = centerY;
    int rightX = centerX + width / 2;
    int rightY = centerY;
    int bottomX = centerX;
    int bottomY = centerY + height / 2;

    drawLine(topX, topY, leftX, leftY);
    drawLine(leftX, leftY, bottomX, bottomY);
    drawLine(bottomX, bottomY, rightX, rightY);
    drawLine(rightX, rightY, topX, topY);
    drawLine(bottomX,bottomY,bottomX-50,bottomY+50);
    drawLine(bottomX,bottomY,bottomX+50,bottomY+50);
    drawLine(bottomX-50,bottomY+50,bottomX+50,bottomY+50);
    drawLine(topX,topY,bottomX,bottomY);
    arc(bottomX,bottomY,45,135,dist(leftX,leftY,bottomX,bottomY));

    delay(20000);
    closegraph();
    return 0;
}
