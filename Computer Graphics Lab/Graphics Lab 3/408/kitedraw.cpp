#include <stdio.h>
#include <graphics.h>
void drawLine(int x1, int y1, int x2, int y2) {
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
            putpixel(x,y,BLUE);
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
            putpixel(x,y,BLUE);
        }
    }
}

int main() {
    int Gdriver=DETECT,Gmode;
    initgraph(&Gdriver,&Gmode,"");
    int x1 = 0, y1 = 0;
    int x2 = 100, y2 = 50;
   // printf("Scan converting a line from (%d, %d) to (%d, %d):\n", x1, y1, x2, y2);
    drawLine(50,0,100,50);
    drawLine(100,50,30,240);
    drawLine(70,240,0,50);
    drawLine(0,50,50,0);
    drawLine(70,240,30,240);
    drawLine(50,0,50,200);
    delay(10000);
    closegraph();
    return 0;
}


