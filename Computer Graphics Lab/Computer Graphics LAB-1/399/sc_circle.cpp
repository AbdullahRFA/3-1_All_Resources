#include <iostream>
#include <graphics.h>

void Circle(int xc, int yc, int radius)
{

    int y = radius;int x = 0;
    int d = 3 - 2 * radius;

    while (x <= y)
    {
        putpixel(xc + x, yc + y, BLUE);
        putpixel(xc - x, yc + y, BLUE);
        putpixel(xc + x, yc - y, BLUE);
        putpixel(xc - x, yc - y, BLUE);
        putpixel(xc + y, yc + x, BLUE);
        putpixel(xc - y, yc + x, BLUE);
        putpixel(xc + y, yc - x, BLUE);
        putpixel(xc - y, yc - x, BLUE);

        if (d < 0)
            d += 4 * x + 6;
        else
        {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "third");

    int xc = 300, yc = 300;
    int radius = 150;

    Circle(xc, yc, radius);

    getch();
    closegraph();
    return 0;
}


