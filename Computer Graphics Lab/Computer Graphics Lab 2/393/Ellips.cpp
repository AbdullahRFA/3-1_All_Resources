#include <iostream>
#include <graphics.h>
#include <conio.h>

voiddrawEllipse(int xc, intyc, intrx, intry)
{
int x, y;
int p;
intpx, py;
    x = 0;
    y = ry;
    p = (ry * ry) - (rx * rx * ry) + ((rx * rx) / 4);

while ((2 * x * ry * ry) < (2 * y * rx * rx))
    {
putpixel(xc + x, yc - y, WHITE);
putpixel(xc - x, yc + y, WHITE);
putpixel(xc + x, yc + y, WHITE);
putpixel(xc - x, yc - y, WHITE);
if (p < 0)
        {
x++;
px = 2 * ry * ry * x;
            p = p + (px + ry * ry);
        }
else
        {
x++;
y--;
px = 2 * ry * ry * x;
py = 2 * rx * rx * y;
            p = p + (px - py + ry * ry);
        }
    }
    p = ((ry * ry) * (x + 0.5) * (x + 0.5)) +
        ((rx * rx) * (y - 1) * (y - 1)) - (rx * rx * ry * ry);
while (y >= 0)
    {
putpixel(xc + x, yc - y, WHITE);
putpixel(xc - x, yc + y, WHITE);
putpixel(xc + x, yc + y, WHITE);
putpixel(xc - x, yc - y, WHITE);

if (p > 0)
        {
y--;
py = 2 * rx * rx * y;
            p = p + (rx * rx - py);
        }
else
        {
y--;
x++;
px = 2 * ry * ry * x;
py = 2 * rx * rx * y;
            p = p + (px - py + rx * rx);
        }
    }
}

int main()
{
intgd = DETECT, gm;
initgraph(&gd, &gm, "");
intcenterX = 250;
intcenterY = 250;
intradiusX = 100;
intradiusY = 50;
drawEllipse(centerX, centerY, radiusX, radiusY);

getch();
closegraph();
return 0;
}

