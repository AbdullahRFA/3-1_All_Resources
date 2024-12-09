#include<bits/stdc++.h>
#include<graphics.h>

void brasenham(int x1,int y1,int x2,int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (x1 != x2 || y1 != y2)
    {
        putpixel(x1, y1, WHITE);

        int err2 = 2 * err;

        if (err2 > -dy) {
            err -= dy;
            x1 += sx;
        }

        if (err2 < dx) {
            err += dx;
            y1 += sy;
        }
    }

    putpixel(x1, y1, WHITE);

}

int main()
{
    float x1,y1,x2,y2,rx1,rx2,ry1,ry2,m1,b1,m,b,angle;
    int sx1,sy1,sx2,sy2;
    int gd= DETECT, gm;
    initgraph(&gd,&gm,"");
    brasenham(200, 100, 300, 175);
    brasenham(300, 175, 200, 300);
    brasenham(200, 300, 100, 175);
    brasenham(100, 175, 200, 100);
    getch();
    closegraph();
    return 0;
}
