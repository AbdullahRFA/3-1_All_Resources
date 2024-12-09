#include <iostream>
#include <graphics.h>
#include<bits/stdc++.h>
using namespace std;
void drawEllipse(int xc, int yc, int a, int b)
{
    int x = 0;
    int y = b;
    int a_sqr = a * a;
    int b_sqr = b * b;
    int d = b_sqr + (a_sqr * (0.25 - b));

    while ((2 * b_sqr * x) <= (2 * a_sqr * y))
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (d < 0)
        {
            x++;
            d += (b_sqr * (2 * x + 3));
        }
        else
        {
            x++;
            y--;
            d += ((b_sqr * (2 * x + 3)) + (a_sqr * (2 - 2 * y)));
        }
    }

    d = (b_sqr * (x + 0.5) * (x + 0.5)) + (a_sqr * (y - 1) * (y - 1)) - (a_sqr * b_sqr);

    while (y >= 0)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (d > 0)
        {
            y--;
            d += (a_sqr * (3 - 2 * y));
        }
        else
        {
            y--;
            x++;
            d += ((b_sqr * (2 * x + 2)) + (a_sqr * (3 - 2 * y)));
        }
    }
}

int main()
{
    int xc, yc, a, b;

    printf("*** Ellipse Generating Algorithm ***\n\n");
    printf("Enter the value of Xc: ");
    scanf("%d", &xc);
    printf("Enter the value of Yc: ");
    scanf("%d", &yc);
    printf("Enter X axis length: ");
    scanf("%d", &a);
    printf("Enter Y axis length: ");
    scanf("%d", &b);

    drawEllipse(xc, yc, a, b);
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    drawEllipse(xc, yc, a, b);

    delay(5000);
    getch();
    closegraph();

    return 0;
}
