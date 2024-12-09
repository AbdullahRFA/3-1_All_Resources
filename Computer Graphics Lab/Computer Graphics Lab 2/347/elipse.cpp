#include<graphics.h>
#include<iostream>
using namespace std;

void elipse(double xc,double yc,double a,double b)
{
    double p=b*b-a*a*b+a*a/4;
    double x=0, y=b;
    while(2.0*b*b*x <= 2.0*a*a*y)
    {
        x++;
        if(p < 0)
        {
            p = p+2*b*b*x+b*b;
        }
        else
        {
            y--;
            p = p+2*b*b*x-2*a*a*y-b*b;
        }
        putpixel(xc+x,yc+y,RED);
        putpixel(xc+x,yc-y,RED);
        putpixel(xc-x,yc+y,RED);
        putpixel(xc-x,yc-y,RED);
    }


    p=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;
    while(y > 0)
    {
        y--;
        if(p <= 0)
        {
            x++;
            p = p+2*b*b*x-2*a*a*y+a*a;
        }
        else
        {
            p = p-2*a*a*y+a*a;
        }
        putpixel(xc+x,yc+y,RED);
        putpixel(xc+x,yc-y,RED);
        putpixel(xc-x,yc+y,RED);
        putpixel(xc-x,yc-y,RED);
    }
}

int main()
{
    int gd = DETECT, gm;
    double xc,yc,x,y, a,b;

   initgraph(&gd, &gm,"C:\\TURBOC3\\BGI");

    cout<<"Enter coordinates of centre: ";
    cin>>xc>>yc;
    cout<<"Enter length of major and minor axix a,b: ";
    cin>>a>>b;

    elipse(xc, yc, a, b);
    getch();
    closegraph();
}
