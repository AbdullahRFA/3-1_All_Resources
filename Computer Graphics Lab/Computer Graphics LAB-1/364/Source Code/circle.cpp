#include <bits/stdc++.h>
#include <graphics.h>
void drawCircle(int xc, int yc, int radius)
{
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;
    while (x <= y)
    {
        putpixel(xc + x, yc + y, GREEN);
        putpixel(xc - x, yc + y, GREEN);
        putpixel(xc + x, yc - y, GREEN);
        putpixel(xc - x, yc - y, GREEN);
        putpixel(xc + y, yc + x, GREEN);
        putpixel(xc - y, yc + x, GREEN);
        putpixel(xc + y, yc - x, GREEN);
        putpixel(xc - y, yc - x, GREEN);
      if (d < 0)
            d += 4 * x + 6;
else
        {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "hello");
    int xc = 200, yc = 200;
    int radius = 200;
    drawCircle(xc, yc, radius);
    getch();
    closegraph();
    return 0;
}
