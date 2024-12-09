#include <iostream>
#include <graphics.h>
using namespace std;
void LineBresenham(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x, y;

    if (x1 < x2)
    {
        x = x1;
        y = y1;
    }
    else
    {
        x = x2;
        y = y2;
        x2 = x1;
        y2 = y1;
    }

    int p = 2 * dy - dx;
    putpixel(x, y, WHITE);

    while (x < x2)
    {
        x++;

        if (p < 0)
        {
            p += 2 * dy;
        }
        else
        {
            y++;
            p += 2 * (dy - dx);
        }

        putpixel(x, y, WHITE);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1, y1, x2, y2;

    cout << "Enter the starting point (x1, y1): ";
    cin >> x1 >> y1;

    cout << "Enter the ending point (x2, y2): ";
    cin >> x2 >> y2;

    LineBresenham(x1, y1, x2, y2);

    getch();
    closegraph();

    return 0;
}

