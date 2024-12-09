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
    m = (sy2-sy1)/(sx2-sx1);
    b = sy1 - (m * sx1);
    int steps,k;
    float x_inc,y_inc;
    if(abs(sx2-sx1) > abs(sy2-sy1))
    {
        steps=abs(sx2-sx1);
    }
    else
    {
        steps=abs(sy2-sy1);
    }
    x_inc = (sx2-sx1) / (float)steps;
    y_inc = (sy2-sy1) / (float)steps;
    int gd= DETECT, gm;
    initgraph(&gd,&gm,"");
    putpixel(sx1,sy1,WHITE);
    for(k = 0;k < steps;k++)
    {
        sx1 += x_inc;
        sy1 += y_inc;
        putpixel(round(sx1),round(sy1),WHITE);
    }
    getch();
    closegraph();
    return 0;
}
