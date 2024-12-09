#include <iostream>
#include <graphics.h>

void drawCircle(int xc, int yc, int radius)
{
    int x = 0;
    int y = radius;
    int d = 1 - radius;

    while (x <= y)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        if (d < 0)
        {
            d += 2 * x + 3;
        }
        else
        {
            d += 2 * (x - y) + 5;
            y--;
        }

        x++;
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = 250;  // X-coordinate of the center
    int yc = 250;  // Y-coordinate of the center
    int radius = 100;
    printf("Enter X-coordinate of the center:  ");
    std::cin>>xc;
    printf("Enter Y-coordinate of the center:  ");
    std::cin>>yc;
    printf("Enter radius:  ");
    std::cin>>radius;
    drawCircle(xc, yc, radius);

    delay(5000);
    closegraph();

    return 0;
}
