#include<conio.h>
#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,x_mid,y_mid,r,d;
    int g_mode,g_driver=DETECT;
    //clrscr();
    initgraph(&g_driver,&g_mode,"C:\\TURBOC3\\BGI");
    printf("*********** MID POINT Circle drawing algorithm ********\n\n");
    printf("\nEnter the coordinates= ");
    scanf("%d %d",&x_mid,&y_mid);
    printf("\n now enter the radius =");
    scanf("%d",&r);
    x=0;
    y=r;
    d=1-r;
    do
    {
        putpixel(x_mid+x,y_mid+y,5);
        putpixel(x_mid+y,y_mid+x,5);
        putpixel(x_mid-y,y_mid+x,5);
        putpixel(x_mid-x,y_mid+y,5);
        putpixel(x_mid-x,y_mid-y,5);
        putpixel(x_mid-y,y_mid-x,5);
        putpixel(x_mid+y,y_mid-x,5);
        putpixel(x_mid+x,y_mid-y,5);
        if(d<0)
        {
            d+=(2*x)+1;
        }
        else
        {
            y=y-1;
            d+=(2*x)-(2*y)+1;
        }
        x = x+1;
    }
    while(y>x);
    getch();
}
