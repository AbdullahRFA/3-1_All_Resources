#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define PI acos(-1)

int main()
{
    int gd=0,gm,x1,y1,x2,y2,x11,x22,y11,y22;
    double s,c, angle;
    initgraph(&gd, &gm, "");

    printf("Enter coordinates of line: ");
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

    line(x1,y1,x2,y2);


    printf("Enter rotation angle: ");
    scanf("%lf", &angle);

    c = cos(angle * PI /180);
    s = sin(angle * PI /180);

    //x11 = floor(x1 * c + y1 * s);
    //y11 = floor(-x1 * s + y1 * c);

    x22 = floor(x2 * c + y2 * s);
    y22 = floor(-x2 * s + y2 * c);

    printf("%d %d %d %d", x1, y1, x22, y22);
    line(x1, y1,x22, y22);

    getch();
    closegraph();
    return 0;
}
