#include <iostream>
#include <graphics.h>
using namespace std;
void drawCircle( int centerX, int centerY, int radius)
{
    int x = 0;
    int y = radius;
    int d = 1 - radius;

    while (y > x)
    {
        putpixel(centerX + x, centerY + y, WHITE);
        putpixel(centerX + y, centerY + x, WHITE);
        putpixel(centerX - x, centerY + y, WHITE);
        putpixel(centerX - y, centerY + x, WHITE);
        putpixel(centerX + x, centerY - y, WHITE);
        putpixel(centerX + y, centerY - x, WHITE);
        putpixel(centerX - x, centerY - y, WHITE);
        putpixel(centerX - y, centerY - x, WHITE);

        if (d < 0)
        {
            d += 2 * x + 3;
        } else
        {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
}

int main()
{
    int x, y, r;

    cout << "\nEnter the x-coordinate of the center: ";
    cin >> x;

    cout << "Enter the y-coordinate of the center: ";
    cin >> y;

    cout << "\nEnter the Radius of the circle: ";
    cin >> r;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    drawCircle(x,y,r);

    delay(5000);

    getch();
    closegraph();
    return 0;
}
