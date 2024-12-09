#include<bits/stdc++.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
using namespace std;
//void display();
float x,y;
int xc,yc;
void display()
{
    putpixel(xc+x,yc+y,8);
    putpixel(xc-x,yc+y,8);
    putpixel(xc+x,yc-y,8);
    putpixel(xc+x,yc-y,8);
}
int main()
{
    int gd=DETECT,gm,a,b;
    float p1,p2;

    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    printf(" Ellipse Generating Algorithm \n\n");
    printf("Enter the value of Xc\t");
    scanf("%d",&xc);
    printf("Enter the value of Yc\t");
    scanf("%d",&yc);
    printf("Enter X axis length\t");
    scanf("%d",&a);
    printf("Enter Y axis length\t");
    scanf("%d",&b);
    x=0;
    y=b;
    display();
    p1=(b*b)-(a*a*b)+(a*a)/4;
    while((2.0*b*b*x)<=(2.0*a*a*y))
    {
        x++;
        if(p1<=0)
            p1=p1+(2.0*b*b*x)+(b*b);
        else
        {
            y--;
            p1=p1+(2.0*b*b*x)+(b*b)-(2.0*a*a*y);
        }
        display();
        x=-x;
        display();
        x=-x;
        delay(50);
    }
    x=a;
    y=0;
    display();
    p2=(a*a)+2.0*(b*b*a)+(b*b)/4;
    while((2.0*b*b*x)>(2.0*a*a*y))
    {
        y++;
        if(p2>0)
            p2=p2+(a*a)-(2.0*a*a*y);
        else
        {
            x--;
            p2=p2+(2.0*b*b*x)-(2.0*a*a*y)+(a*a);
        }
        display();
        y=-y;
        display();
        y=-y;
        delay(50);
    }
    getch();
    closegraph();
}

