#include<bits/stdc++.h>
#include<graphics.h>

int main()
{
    float x,y;
    int x1,y1;
    printf("Enter point(x,y): ");
    scanf("%f %f",&x,&y);
    x1 = floor(x);
    y1 = floor(y);
    int gd= DETECT, gm;
    initgraph(&gd,&gm,"");
    putpixel(x1,y1,WHITE);
    getch();
    closegraph();
    return 0;
}
