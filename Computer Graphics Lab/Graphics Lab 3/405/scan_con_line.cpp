#include <graphics.h>
#include <bits/stdc++.h>

int col=WHITE;

using namespace std;

void bLine(int x1, int y1, int x2, int y2)
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
    putpixel(x, y, col);

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

        putpixel(x, y, col);
    }
}

void rotateLine(int& x0, int& y0, int& x1, int& y1, double angle)
{
    double radian = angle * (M_PI / 180.0);
    int newX0 = round(x0 * cos(radian) - y0 * sin(radian));
    int newY0 = round(x0 * sin(radian) + y0 * cos(radian));
    int newX1 = round(x1 * cos(radian) - y1 * sin(radian));
    int newY1 = round(x1 * sin(radian) + y1 * cos(radian));

    x0 = newX0;
    y0 = newY0;
    x1 = newX1;
    y1 = newY1;
}



void scaleLine(int& x0, int& y0, int& x1, int& y1, double scaleFactor)
{
    x0 = round(x0 * scaleFactor);
    y0 = round(y0 * scaleFactor);
    x1 = round(x1 * scaleFactor);
    y1 = round(y1 * scaleFactor);
}

void translateLine(int& x0, int& y0, int& x1, int& y1, int tx)
{
    x0 += tx;
    x1 += tx;
}


int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x0 = 0;   // X-coordinate of the starting point
    int y0 = 0;   // Y-coordinate of the starting point
    int x1 = 100; // X-coordinate of the ending point
    int y1 = 50;  // Y-coordinate of the ending point

    //bLine(x0, y0, x1, y1);

    delay(1000);
    rotateLine(x0, y0, x1, y1,30);
    bLine(x0, y0, x1, y1);
    delay(1000);
    scaleLine(x0, y0, x1, y1,.50);
    col=RED;
    bLine(x0, y0, x1, y1);
    translateLine(x0, y0, x1, y1,75);
    col=GREEN;
    bLine(x0, y0, x1, y1);
    delay(1000);
    delay(1000000);
    closegraph();
    return 0;
}
