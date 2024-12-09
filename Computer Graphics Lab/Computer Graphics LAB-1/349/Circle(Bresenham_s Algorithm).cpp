#include <stdio.h>
#include<math.h>
#include <graphics.h>

void drawCircleBresenham(int xc, int yc, int radius)
{
    int x = 0;
    int y = radius;
    int p = 3- 2*radius;

    while (x<=y)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        if (p<0)
        {
            p += 4*x+6;
        }
        else
        {
            p += 4*(x-y)+10;
            y--;
        }
        x++;
    }
}

int main()
{
    int xc, yc, radius;

    printf("Enter the center coordinates: ");
    scanf("%d %d", &xc, &yc);

    printf("Enter the radius: ");
    scanf("%d", &radius);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    drawCircleBresenham(xc, yc, radius);

    delay(5000);

    closegraph();
    return 0;
}

