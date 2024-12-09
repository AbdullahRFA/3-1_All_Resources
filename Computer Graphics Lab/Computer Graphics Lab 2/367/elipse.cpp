#include <graphics.h>

void drawEllipse(int centerX, int centerY, int radiusX, int radiusY)
{
    int x = 0;
    int y = radiusY;

    int aSquare = radiusX * radiusX;
    int bSquare = radiusY * radiusY;

    int decision = bSquare + aSquare * (0.25 - radiusY);

    while (bSquare * x <= aSquare * y)
    {
        putpixel(centerX + x, centerY + y, YELLOW);
        putpixel(centerX - x, centerY + y, YELLOW);
        putpixel(centerX - x, centerY - y, YELLOW);
        putpixel(centerX + x, centerY - y, YELLOW);

        if (decision < 0)
        {
            x++;
            decision += bSquare * (2 * x + 3);
        }
        else
        {
            x++;
            y--;
            decision += bSquare * (2 * x + 3) + aSquare * (-2 * y + 2);
        }
    }

    decision = bSquare * (x + 0.5) * (x + 0.5) + aSquare * (y - 1) * (y - 1) - aSquare * bSquare;

    while (y >= 0)
    {
        putpixel(centerX + x, centerY + y, YELLOW);
        putpixel(centerX - x, centerY + y, YELLOW);
        putpixel(centerX - x, centerY - y, YELLOW);
        putpixel(centerX + x, centerY - y, YELLOW);

        if (decision > 0)
        {
            y--;
            decision += aSquare * (-2 * y + 3);
        }
        else
        {
            y--;
            x++;
            decision += bSquare * (2 * x + 2) + aSquare * (-2 * y + 3);
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int centerX = 320;
    int centerY = 340;
    int radiusX = 200;
    int radiusY = 100;
    drawEllipse(centerX, centerY, radiusX, radiusY);

    getch();
    closegraph();

    return 0;
}


