#include<stdio.h>
#include<math.h>
#include<graphics.h>

int main()
{
    int x,y,p,h,k,a,b,fx,fy;
    printf("Enter the coordinates of the center: ");
    scanf("%d%d",&h,&k);
    printf("Enter the lengths of major and minor axes: ");
    scanf("%d%d",&a,&b);
    x=0;
    y=b;
    fx=0;
    fy=2*b*a*a;
    p=b*b-a*a*b+0.25*a*a;
    initwindow(1000,600);
    while(fx<fy)
    {
        putpixel(x+h,y+k,LIGHTBLUE);
        putpixel(-x+h,y+k,LIGHTBLUE);
        putpixel(-x+h,-y+k,LIGHTBLUE);
        putpixel(x+h,-y+k,LIGHTBLUE);
        x++;
        fx+=(2*b*b);
        if(p<0)p+=(fx+b*b);
        else
        {
            y--;
            fy-=(a*a*2);
            p+=(fx+b*b-fy);
        }
    }
    putpixel(x+h,y+k,LIGHTBLUE);
    putpixel(-x+h,y+k,LIGHTBLUE);
    putpixel(-x+h,-y+k,LIGHTBLUE);
    putpixel(x+h,-y+k,LIGHTBLUE);
    p=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
    while(y>0)
    {
        y--;
        fy-=(a*a*2);
        if(p>=0)
        {
            p-=(fy+a*a);
        }
        else
        {
            x++;
            fx+=(2*b*b);
            p+=(fx-fy+a*a);
        }
        putpixel(x+h,y+k,LIGHTBLUE);
        putpixel(-x+h,y+k,LIGHTBLUE);
        putpixel(-x+h,-y+k,LIGHTBLUE);
        putpixel(x+h,-y+k,LIGHTBLUE);
    }
    getch();
    return 0;
}

