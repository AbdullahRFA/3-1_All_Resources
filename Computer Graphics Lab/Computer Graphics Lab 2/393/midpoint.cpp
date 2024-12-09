#include <iostream>
#include <graphics.h>
voidplotPoints(int xc, intyc, int x, int y)
{
putpixel(xc + x, yc + y, WHITE);
putpixel(xc - x, yc + y, WHITE);
putpixel(xc + x, yc - y, WHITE);
putpixel(xc - x, yc - y, WHITE);
putpixel(xc + y, yc + x, WHITE);
putpixel(xc - y, yc + x, WHITE);
putpixel(xc + y, yc - x, WHITE);
putpixel(xc - y, yc - x, WHITE);
}
voidmidpointCircle(int xc, intyc, int r)
{
int x = 0;
int y = r;
int p = 1 - r;
plotPoints(xc, yc, x, y);
while (x < y)
    {
x++;

if (p < 0)
            p += 2 * x + 1;
else
        {
y--;
            p += 2 * (x - y) + 1;
        }
plotPoints(xc, yc, x, y);
    }
}

int main()
{
intgd = DETECT, gm;
initgraph(&gd, &gm, "");

int xc = 320;
intyc = 240;
int r = 100;
midpointCircle(xc, yc, r);

delay(5000);
closegraph();

return 0;
}

