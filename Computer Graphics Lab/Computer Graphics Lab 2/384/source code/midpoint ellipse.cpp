#include<bits/stdc++.h>
#include<graphics.h>

void setpix(int sx,int sy,int dx,int dy)
{
    putpixel(sx+dx,sy+dy,WHITE);
    putpixel(sx+dx,sy-dy,WHITE);
    putpixel(sx-dx,sy+dy,WHITE);
    putpixel(sx-dx,sy-dy,WHITE);
}

int main()
{
    float x,y,r,a,b;
    int sx,sy,sa,sb;
    printf("Enter center point(x,y): ");
    scanf("%f %f",&x,&y);
    sx = floor(x);
    sy = floor(y);
    printf("Enter major axis: ");
    scanf("%f",&a);
    printf("Enter minor axis: ");
    scanf("%f",&b);
    sa = floor(a);
    sb = floor(b);
    int dx = 0;
    int dy = sb;
    int aa,bb,aa2,bb2;
    aa = sa*sa;
    bb = sb*sb;
    aa2 = aa * 2;
    bb2 = bb * 2;
    int fx = 0,fy = aa2*sb;
    int d = bb - aa*b + round(0.25*aa);
    int gd= DETECT, gm;
    initgraph(&gd,&gm,"");
    while(fx < fy)
    {
        setpix(sx,sy,dx,dy);
        dx++;
        fx += bb2;
        if(d < 0)
        {
            d += fx + bb;
        }
        else
        {
            dy--;
            fy -= aa2;
            d += fx + bb - fy;

        }
    }
    setpix(sx,sy,dx,dy);
    d = round(bb *(dx+0.5) * (dx+0.5)) + (aa * (dy-1) * (dy-1)) - aa*bb;
    while(dy > 0)
    {
        dy--;
        fy -= aa2;
        if(d >= 0)
        {
            d = d - fy + aa;
        }
        else
        {
            dx++;
            fx += bb2;
            d = d + fx - fy + aa;
        }
        setpix(sx,sy,dx,dy);
    }
    getch();
    closegraph();
    return 0;
}



