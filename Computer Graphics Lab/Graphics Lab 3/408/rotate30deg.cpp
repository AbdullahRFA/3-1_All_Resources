#include<stdio.h>
#include<math.h>
#include <graphics.h>
void drawLine(int x1, int y1, int x2, int y2) {
    int Gdriver=DETECT,Gmode;
    initgraph(&Gdriver,&Gmode,"");
    int dx = x2 - x1;
    int dy = y2 - y1;
    int x = x1;
    int y = y1;

    int dx1 = dx > 0 ? 1 : -1;
    int dy1 = dy > 0 ? 1 : -1;

    dx = dx > 0 ? dx : -dx;
    dy = dy > 0 ? dy : -dy;

    int dx2 = dx << 1;
    int dy2 = dy << 1;

    if (dx > dy) {
        int fraction = dy2 - dx;
        while (x != x2) {
            if (fraction >= 0) {
                y += dy1;
                fraction -= dx2;
            }
            x += dx1;
            fraction += dy2;
            putpixel(x,y,WHITE);
        }
    } else {
        int fraction = dx2 - dy;
        while (y != y2) {
            if (fraction >= 0) {
                x += dx1;
                fraction -= dy2;
            }
            y += dy1;
            fraction += dx2;
            putpixel(x,y,WHITE);
        }
    }
    delay(10000);
    closegraph();
}
int main() {
    int x1 = 0, y1 = 0;
    int x2 = 100, y2 = 50;
    double theta=30.0*3.1415/180.00;
    int new_x2 = (int)(x1 + (x2 - x1) * cos(theta) - (y2 - y1) * sin(theta));
    int new_y2 = (int)(y1 + (x2 - x1) * sin(theta) + (y2 - y1) * cos(theta));
    drawLine(x1,y1,new_x2,new_y2);
    return 0;
}

