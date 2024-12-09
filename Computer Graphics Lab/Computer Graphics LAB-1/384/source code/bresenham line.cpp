#include<bits/stdc++.h>
#include<graphics.h>

int main()
{
    float x1,y1,x2,y2,m1,b1,m,b;
    int sx1,sy1,sx2,sy2;
    printf("Enter first point(x1,y1): ");
    scanf("%f %f",&x1,&y1);
    sx1 = floor(x1);
    sy1 = floor(y1);
    printf("Enter second point(x2,y2): ");
    scanf("%f %f",&x2,&y2);
    sx2 = floor(x2);
    sy2 = floor(y2);
    int steps,k,dx,dy;
    float x_inc,y_inc;
    dx = abs(sx2-sx1);
    dy = abs(sy2-sy1);
    int err = dx-dy;
    if(sx1 < sx2)
    {
        x_inc = 1;
    }
    else
    {
        x_inc = -1;
    }
    if(sy1 < sy2)
    {
        y_inc = 1;
    }
    else
    {
        y_inc = -1;
    }
    int gd= DETECT, gm;
    initgraph(&gd,&gm,"");
    while(1)
    {
        putpixel(sx1,sy1,WHITE);
        if(sx1 == sx2 && sy1 == sy2)
        {
            break;
        }
        int newerr = 2 * err;
        if(newerr > -dy)
        {
            err -= dy;
            sx1 += x_inc;
        }
        if(newerr < dx)
        {
            err += dx;
            sy1 += y_inc;
        }
    }
    getch();
    closegraph();
    return 0;
}

