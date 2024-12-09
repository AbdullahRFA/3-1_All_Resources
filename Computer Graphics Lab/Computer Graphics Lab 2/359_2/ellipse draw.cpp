
#include <iostream>
#include <graphics.h>
#include <math.h>
void drawEllipse(int xc, int yc, int a, int b)
{
    int x = 0;
    int y = b;
    int aSqrt = a * a;
    int bSqrt = b * b;
    int twoaSqrt = 2 * aSqrt;
    int twobSqrt = 2 * bSqrt;
    int xEnd = round(aSqrt / sqrt(aSqrt + bSqrt));
    int p = round(bSqrt - aSqrt * b + 0.25 * aSqrt);

    while (x <= xEnd)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        x++;

        if (p < 0)
        {
            p += twobSqrt * x + bSqrt;
        }
        else
        {
            y--;
            p += twobSqrt * x - twoaSqrt * y + bSqrt;
        }
    }

    p = round(bSqrt * (x + 0.5) * (x + 0.5) + aSqrt * (y - 1) * (y - 1) - aSqrt * bSqrt);

    while (y >= 0)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        y--;

        if (p > 0)
        {
            p += aSqrt - twoaSqrt * y;
        }
        else
        {
            x++;
            p += twobSqrt * x - twoaSqrt * y + aSqrt;
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int xc = 250;  // X-coordinate of the center
    int yc = 250;  // Y-coordinate of the center
    int a = 100;   // Semi-major axis length
    int b = 50;    // Semi-minor axis length
    printf("Enter X-coordinate of the center:  ");
    std::cin>>xc;
    printf("Enter Y-coordinate of the center:  ");
    std::cin>>yc;
    printf("Enter Semi-major axis length:  ");
    std::cin>>a;
    printf("Enter Semi-minor axis length:  ");
    std::cin>>b;
    drawEllipse(xc, yc, a, b);

    delay(50000);
    closegraph();

    return 0;
}
