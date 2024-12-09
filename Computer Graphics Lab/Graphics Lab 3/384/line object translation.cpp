#include<bits/stdc++.h>
#include<graphics.h>

void brasenham(int sx1,int sy1,int sx2,int sy2)
{
    int steps,k,dx,dy;
    float x_inc,y_inc;
    dx = abs(sx2-sx1);
    dy = abs(sy2-sy1);
    int dt = 2*(dy-dx);
    int ds = 2*dy;
    int d = (2*dy) - dx;

    putpixel(sx1,sy1,WHITE);
    while(sx1 < sx2)
    {
        sx1++;
        if(d < 0)
        {
            d += ds;
        }
        else
        {
            sy1++;
            d += dt;
        }
        putpixel(sx1,sy1,WHITE);
    }

}

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
    int gd= DETECT, gm;
    initgraph(&gd,&gm,"");
    brasenham(sx1,sy1,sx2,sy2);
    //delay(1000);
    //brasenham(sx1 + 75,sy1,sx2 + 75,sy2);
    getch();
    closegraph();
    return 0;
}

