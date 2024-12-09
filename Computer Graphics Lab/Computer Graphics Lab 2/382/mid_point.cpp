#include <iostream>
#include <graphics.h>

void drawCircle(int xc, int yc, int radius)
{
    int x = 0;
    int y = radius;
    int p = 1 - radius;

    while (x <= y)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc + x, yc - y, WHITE);

        if (p < 0)
        {
            p += 2 * x + 3;
        }
        else
        {
            p += 2 * (x - y) + 5;
            y--;
        }

        x++;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc, yc, radius;

    std::cout << "Enter the x-coordinate of the center: ";
    std::cin >> xc;
    std::cout << "Enter the y-coordinate of the center: ";
    std::cin >> yc;
    std::cout << "Enter the radius: ";
    std::cin >> radius;

    drawCircle(xc, yc, radius);

    delay(5000);
    closegraph();

    return 0;
}
