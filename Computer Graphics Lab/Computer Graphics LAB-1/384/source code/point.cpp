#include<bits/stdc++.h>
#include<graphics.h>

int main()
{
    float x,y;
    printf("Enter point(x,y): ");
    scanf("%f %f",&x,&y);
    int sx,sy;
    sx = floor(x);
    sy = floor(y);
    int gd= DETECT, gm;
    initgraph(&gd,&gm,"");
    putpixel(sx,sy,WHITE);
    getch();
    closegraph();
    return 0;
}
