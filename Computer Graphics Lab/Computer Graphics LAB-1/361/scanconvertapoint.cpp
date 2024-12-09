#include<stdio.h>
#include<graphics.h>
#include<math.h>

int main()
{
    double x,y;
    int xp,yp;
    printf("Enter the coordinates of the point: ");
    scanf("%lf%lf",&x,&y);
    xp=floor(x);
    yp=floor(y);
    initwindow(1000,600);
    putpixel(xp,yp,YELLOW);
    getch();
    return 0;
}
