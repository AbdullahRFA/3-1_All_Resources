#include <stdio.h>
#include<math.h>
#include <graphics.h>

void drawLineBresenham(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x, y;
    int p;

    int xStep, yStep;
    if(x1<x2)
    {
        xStep=1;
    }
    else
    {
        xStep=-1;
    }
    if(y1<y2)
    {
        yStep=1;
    }
    else
    {
        yStep=-1;
    }

    if(dx >= dy)
    {
        p = 2*dy-dx;
        y = y1;
        for (x=x1; x!=x2; x+=xStep)
        {
            putpixel(x, y, WHITE);
            if (p >= 0)
            {
                y += yStep;
                p -= 2 * dx;
            }
            p+=2*dy;
        }
    }
    else
    {
        p = 2*dx-dy;
        x = x1;
        for (y=y1; y!=y2; y+=yStep)
        {
            putpixel(x, y, WHITE);
            if (p >= 0)
            {
                x+=xStep;
                p-=2 * dy;
            }
            p+=2*dx;
        }
    }
}

int main()
{
    int x1, y1, x2, y2;
    float x, y;

    printf("Enter the coordinates of the first point: ");
    scanf("%f %f", &x, &y);
    x1=x, y1=y;

    printf("Enter the coordinates of the second point: ");
    scanf("%f %f", &x, &y);
    x2=x, y2=y;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    drawLineBresenham(x1, y1, x2, y2);

    delay(5000);

    closegraph();
    return 0;
}

