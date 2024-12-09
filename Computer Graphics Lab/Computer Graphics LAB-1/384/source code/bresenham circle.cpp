#include<bits/stdc++.h>
#include<graphics.h>

int main()
{
    float x,y,r;
    int sx,sy,sr;
    printf("Enter center point(x,y): ");
    scanf("%f %f",&x,&y);
    sx = floor(x);
    sy = floor(y);
    printf("Enter radius: ");
    scanf("%f",&r);
    sr = floor(r);
    int dx = 0;
    int dy = sr;
    int d = 3 - (2 * sr);
    int gd= DETECT, gm;
    initgraph(&gd,&gm,"");
    while(dx <= dy)
    {
        putpixel(sx+dx,sy+dy,WHITE);
        putpixel(sx-dx,sy+dy,WHITE);
        putpixel(sx+dx,sy-dy,WHITE);
        putpixel(sx-dx,sy-dy,WHITE);
        putpixel(sx+dy,sy+dx,WHITE);
        putpixel(sx-dy,sy+dx,WHITE);
        putpixel(sx+dy,sy-dx,WHITE);
        putpixel(sx-dy,sy-dx,WHITE);
        if(d < 0)
        {
            d += (4*dx) + 6;
        }
        else
        {
            d += (4 * (dx - dy)) + 10;
            dy--;
        }
        dx++;
    }
    getch();
    closegraph();
    return 0;
}

