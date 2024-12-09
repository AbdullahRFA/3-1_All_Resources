#include <stdio.h>
#include<math.h>
#include <graphics.h>

void drawEillpseMidPoint(int xc, int yc, int a, int b)
{
    int x = 0;
    int y = b;
    int aa=a*a, bb=b*b;
    int aa2=aa*2, bb2=bb*2;
    int fx=0, fy=aa2*y;
    int p= bb - aa*b +0.25*aa;
    while (fx<=fy)
    {
        putpixel(xc + x, yc + y, YELLOW);
        putpixel(xc - x, yc + y, YELLOW);
        putpixel(xc + x, yc - y, YELLOW);
        putpixel(xc - x, yc - y, YELLOW);
        x++;
        fx=fx+bb2;

        if (p<0)
        {
            p = p+ fx +bb;
        }
        else
        {
            y--;
            fy=fy-aa2;
            p = p+ fx +bb-fy;
        }
    }

    putpixel(xc + x, yc + y, YELLOW);
    putpixel(xc - x, yc + y, YELLOW);
    putpixel(xc + x, yc - y, YELLOW);
    putpixel(xc - x, yc - y, YELLOW);
    p= bb*(x+0.5)*(x+0.5) + aa*(y-1)*(y-1) - bb*aa;
    while (y>=0)
    {
        y--;
        fy=fy-aa2;
        if (p>=0)
        {
            p = p- fy +aa;
        }
        else
        {
            x++;
            fx=fx+bb2;
            p = p+ fx -fy +aa;
        }
        putpixel(xc + x, yc + y, YELLOW);
        putpixel(xc - x, yc + y, YELLOW);
        putpixel(xc + x, yc - y, YELLOW);
        putpixel(xc - x, yc - y, YELLOW);
    }

    return;
}

int main()
{
    int xc, yc, radius,a,b;

    printf("Enter the coordinates of the center of the ellipse: ");
    scanf("%d %d", &xc, &yc);

    printf("Enter the length of the major axis: ");
    scanf("%d", &a);

    printf("Enter the length of the minor axis: ");
    scanf("%d", &b);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    drawEillpseMidPoint(xc, yc, a, b);

    delay(5000);

    closegraph();
    return 0;
}



