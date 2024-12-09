#include<bits/stdc++.h>
#include<graphics.h>
#include<math.h>
int main()
{
    int gd=0,gm,x1,y1,x2,y2;
    double s,c, tr;
    initgraph(&gd, &gm,"");
    printf("Enter coordinates of line: ");
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

    line(x1,y1,x2,y2);

    printf("Enter transformation value: ");
    scanf("%lf", &tr);

    x1+=tr;
    x2+=tr;

    line(x1, y1 ,x2, y2);
    getch();
    closegraph();
    return 0;
}

