#include <graphics.h>
#include <iostream>
using namespace std;

int round(float n)
{
    if (n - (int)n < 0.5)
        return (int)n;
    return (int)(n + 1);
}


void DDALine(int x0, int y0, int x1, int y1)
{

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    int dx = x1 - x0;
    int dy = y1 - y0;

    int step;


    if (abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);

    float x_incr = (float)dx / step;
    float y_incr = (float)dy / step;

    float x = x0;
    float y = y0;


    cleardevice();

    for (int i = 0; i < step; i++)
    {
        putpixel(round(x), round(y), WHITE);
        delay(10);
        x += x_incr;
        y += y_incr;
    }

    getch();
    closegraph();
}

int main()
{

    int x1, y1, x2, y2;

    cout << "\nEnter the starting x-coordinate: ";
    cin >> x1;

    cout << "Enter the starting y-coordinate: ";
    cin >> y1;

    cout << "\nEnter the ending x-coordinate: ";
    cin >> x2;

    cout << "Enter the ending y-coordinate: ";
    cin >> y2;

    DDALine(x1, y1, x2, y2);

    return 0;
}
