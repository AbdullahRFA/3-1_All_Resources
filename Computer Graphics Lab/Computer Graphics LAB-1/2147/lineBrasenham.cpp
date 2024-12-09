#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

void drawLine(int x0, int y0, int x1, int y1) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx, sy;

    if (x0 < x1) {
        sx = 1;
    } else {
        sx = -1;
    }

    if (y0 < y1) {
        sy = 1;
    } else {
        sy = -1;
    }

    int err = dx - dy;

    while (x0 != x1 || y0 != y1) {
        putpixel(x0, y0, WHITE);
        int e2 = 2 * err;

        if (e2 > -dy) {
            err = err - dy;
            x0 = x0 + sx;
        }

        if (e2 < dx) {
            err = err + dx;
            y0 = y0 + sy;
        }
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x0,y0,x1,y1;
    printf("Enter the starting coordinate");
    scanf("%d%d",&x0,&y0);
    printf("Enter the end coordinate");
    scanf("%d%d",&x1,&y1);

    drawLine(x0, y0, x1, y1);

    delay(508800);
    closegraph();

    return 0;
}
