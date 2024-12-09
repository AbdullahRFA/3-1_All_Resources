#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;
int main()
{


    int xc,yc,a,b;
    cout<<"Enter the center of the ellipse (x,y) = ";
    cin>>xc>>yc;
    cout<<"Enter the lengths of semi major axis and minor axis (a,b) = ";
    cin>>a>>b;

    int x = 0;
    int y = b;

    int aa = a * a;
    int bb = b * b;
    int aa2 = 2 * aa;
    int bb2 = 2 * bb;
    int aa4 = 4 * aa2;
    int bb4 = 4 * bb2;
    int d1 = bb - aa * b + 0.25 * aa;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    while (bb4 * x < aa4 * y)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (d1 < 0)
        {
            x++;
            d1 += bb2 * x + bb;
        }
        else
        {
            x++;
            y--;
            d1 += bb2 * x - aa2 * y + aa + bb;
        }
    }

    int d2 = bb * (x + 0.5) * (x + 0.5) + aa * (y - 1) * (y - 1) - aa * bb;
    while (y >= 0)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (d2 > 0)
        {
            y--;
            d2 -= aa2 * y + aa;
        }
        else
        {
            y--;
            x++;
            d2 += bb2 * x - aa2 * y + aa + bb;
        }
    }

    getch();
    return 0;
}

