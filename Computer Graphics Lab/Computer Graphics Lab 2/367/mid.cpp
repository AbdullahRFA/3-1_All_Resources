#include <graphics.h>

void drawCircle(int centerX, int centerY, int radius)
{
    int x = 0;
    int y = radius;
    int decision = 1 - radius;

    while (y >= x)
    {
        putpixel(centerX + x, centerY + y, YELLOW);
        putpixel(centerX + y, centerY + x, YELLOW);
        putpixel(centerX - y, centerY + x, YELLOW);
        putpixel(centerX - x, centerY + y, YELLOW);
        putpixel(centerX - x, centerY - y, YELLOW);
        putpixel(centerX - y, centerY - x, YELLOW);
        putpixel(centerX + y, centerY - x, YELLOW);
        putpixel(centerX + x, centerY - y, YELLOW);

        if (decision < 0)
        {
            decision += 2 * x + 3;
        }
        else
        {
            decision += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int centerX = 444;
    int centerY = 222;
    int radius = 100;
    drawCircle(centerX, centerY, radius);

    getch();
    closegraph();

    return 0;
}

