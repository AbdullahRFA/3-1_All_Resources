#include <bits/stdc++.h>
#include<graphics.h>
using namespace std;
void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true)
    {
        //cout << "(" << x1 << ", " << y1 << ")\n";
        putpixel(x1,y1,WHITE);
        putpixel(x2,y2,WHITE);
        if (x1 == x2 && y1 == y2)
        {
            break;
        }
        ///etuk e ki koreche?
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void drawKite()
{
    int width = 100; // width of the kite
    int height = 200; // height of the kite

    int x1 = 0;
    int y1 = height / 2;
    int x2 = width / 2;
    int y2 = 0;
    int x3 = width;
    int y3 = height / 2;
    int x4 = width / 2;
    int y4 = height;
    int x5 = width/2;
    int y5 = height/2;

    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2, x3, y3);
    drawLine(x3, y3, x4, y4);
    drawLine(x4, y4, x1, y1);
    drawLine(x1, y1, x5, y5);
    drawLine(x2, y2, x5, y5);
    drawLine(x3, y3, x5, y5);
    drawLine(x4, y4, x5, y5);

}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    drawKite();
    getch();
    closegraph();
    return 0;
}

