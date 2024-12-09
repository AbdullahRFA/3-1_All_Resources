#include <iostream>
#include <graphics.h>
#include <bits/stdc++.h>
int col=WHITE;
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

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    bLine(200,100,300,200);
    bLine(300,200,200,300);
    bLine(200,300,100,200);
    bLine(100,200,200,100);
    //bLine(195,135,150,77);
    delay(10000);
    return 0;
}
