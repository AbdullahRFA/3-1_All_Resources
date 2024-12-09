#include <stdio.h>
#include<math.h>
#include <graphics.h>

void drawMidPoint(int xc, int yc, int radius)
{
    int x = 0;
    int y = radius;
    int p = 1 - radius;

    while (x<=y)
    {
        putpixel(xc + x, yc + y, YELLOW);
        putpixel(xc - x, yc + y, YELLOW);
        putpixel(xc + x, yc - y, YELLOW);
        putpixel(xc - x, yc - y, YELLOW);
        putpixel(xc + y, yc + x, YELLOW);
        putpixel(xc - y, yc + x, YELLOW);
        putpixel(xc + y, yc - x, YELLOW);
        putpixel(xc - y, yc - x, YELLOW);

        if (p<0)
        {
            p = p+ 2*x+ 3;
        }
        else
        {
            p =p+2*(x-y)+5;
            y--;
        }
        x++;
    }
}

int main()
{
    int xc, yc, radius;

    printf("Enter the coordinates of the center of the circle: ");
    scanf("%d %d", &xc, &yc);

    printf("Enter the radius: ");
    scanf("%d", &radius);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    drawMidPoint(xc, yc, radius);

    delay(5000);

    closegraph();
    return 0;
}


