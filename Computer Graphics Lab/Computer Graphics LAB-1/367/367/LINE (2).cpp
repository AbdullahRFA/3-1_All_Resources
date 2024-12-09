#include <stdio.h>
#include <graphics.h>

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "FIRST");

    int x1 = 100, y1 = 100;
    int x2 = 444, y2 = 333;

    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++)
    {
        putpixel(x, y, BLUE);

        x += xInc;
        y += yInc;
    }

    getch();
    closegraph();
    return 0;
}
