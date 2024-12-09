#include<stdio.h>
#include<math.h>
#include<graphics.h>

int main()
{
    int x,y,p,r,h,k;
    //double x,y;
    printf("Enter the coordinates of the center: ");
    scanf("%d%d",&h,&k);
    printf("Enter the radius of the circle: ");
    scanf("%d",&r);
    x=0;
    y=r;
    p=1-r;
    initwindow(1000,600);
    while(x<=y)
    {
        putpixel(x+h,y+k,LIGHTBLUE);
        putpixel(y+h,x+k,LIGHTBLUE);
        putpixel(-y+h,x+k,LIGHTBLUE);
        putpixel(-x+h,y+k,LIGHTBLUE);
        putpixel(-x+h,-y+k,LIGHTBLUE);
        putpixel(-y+h,-x+k,LIGHTBLUE);
        putpixel(y+h,-x+k,LIGHTBLUE);
        putpixel(x+h,-y+k,LIGHTBLUE);
        if(p<0)p+=(2*x+3);
        else
        {
            p+=(2*(x-y)+5);
            y--;
        }
        x++;
    }
    getch();
    return 0;
}
