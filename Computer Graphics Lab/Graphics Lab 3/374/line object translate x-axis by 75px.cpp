#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define PI acos(-1)

int main()
{
    int gd=0,gm,x1,y1,x2,y2,x11,x22,y11,y22,trans;
    double s,c, angle;
    initgraph(&gd, &gm, "");

    printf("Enter coordinates of line: ");
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

    line(x1,y1,x2,y2);


    printf("Enter translation value: ");
    scanf("%d", &trans);

    x11=x1+trans;

    x22=x2+trans;

    printf("%d %d %d %d", x11, y1, x22, y2);
    line(x11, y1,x22, y2);

    getch();
    closegraph();
    return 0;
}

