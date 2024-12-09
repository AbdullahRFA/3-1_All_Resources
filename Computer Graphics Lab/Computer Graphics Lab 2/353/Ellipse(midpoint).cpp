#include <iostream>
#include <graphics.h>
using namespace std;
void drawEllipse(int xc, int yc, int rx, int ry)
{
    int x = 0;
    int y = ry;
    int d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    int dx = 2 * ry * ry * x;
    int dy = 2 * rx * rx * y;
    while (dx < dy)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }
    int d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);

    while (y >= 0)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        if (d2 > 0)
        {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
}
int main()
{
    int xc, yc, rx, ry;
    cout << "Enter the center coordinates (x,y): ";
    cin >> xc >> yc;
    cout << "Enter the major radius (rx): ";
    cin >> rx;
    cout << "Enter the minor radius (ry): ";
    cin >> ry;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    drawEllipse(xc, yc, rx, ry);
    delay(10000);
    getch();
    closegraph();
    return 0;
}