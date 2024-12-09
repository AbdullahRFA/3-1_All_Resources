
#include <bits/stdc++.h>
#include<iostream>
#include <graphics.h>
void drawCircle(int xc, int yc, int radius)
{
    int x = 0;
    int y = radius;
    int decision = 1 - radius;
    while (y >= x)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        if (decision <= 0)
        {
            x++;
            decision += 2 * x + 1;
        }
        else
        {
            y--;
            x++;
            decision += 2 * (x - y) + 1;
        }
    }
}

int main()
{
    //cout<<"____Mid-Point Circle Algorithm_____"<<endl;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int xc, yc, radius;
    std::cout << "Enter the center coordinates (xc, yc): ";
    std::cin >> xc >> yc;
    std::cout << "Enter the radius: ";
    std::cin >> radius;

    drawCircle(xc, yc, radius);

    delay(5000);
    closegraph();

    return 0;
}