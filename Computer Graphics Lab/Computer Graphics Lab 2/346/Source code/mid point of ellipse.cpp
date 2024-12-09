#include<bits/stdc++.h>
#include <graphics.h>
using namespace std;
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, " ");
    int xc, yc, rx, ry,x,y,Srx,Sry,TSrx,TSry,d;
    cout << "Enter the coordinates of the center: ";
    cin >> xc >> yc;
    cout << "Enter the major radius &  minor radius: ";
    cin >> rx>> ry;
    x=0;
    y=ry;
    Srx = rx * rx;
    Sry = ry * ry;
    TSrx = 2 * Srx;
    TSry = 2 * Sry;
    int px = 0;
    int py = TSrx * y;
    d = round(Sry - (Srx * ry) + (0.25 * Srx));
    while (px < py)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        x++;
        px += TSry;
        if (d < 0)
        {
            d += Sry + px;
        }
        else
        {
            y--;
            py -= TSrx;
            d += Sry + px - py;
        }
    }
    d = round(Sry * (x + 0.5) * (x + 0.5) + Srx * (y - 1) * (y - 1) - Srx * Sry);
    while (y >= 0)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        y--;
        py -= TSrx;
        if (d > 0)
        {
            d += Srx - py;
        }
        else
        {
            x++;
            px += TSry;
            d += Srx - py + px;
        }
    }
    getch();
    closegraph();
    return 0;
}
