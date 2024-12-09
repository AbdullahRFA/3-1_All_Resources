#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
using namespace std;
void drawline(int x0, int y0, int x1, int y1)
{
    int dx, dy, p, x, y,d,dS,dT;
    dx=x1-x0;
    dy=y1-y0;
    x=x0;
    y=y0;
    dS=2*dy;
    dT=2*dy-2*dx;
    p=2*dy-dx;
    while(x<x1)
    {
        if(p>=0)
        {
            putpixel(x,y,RED);
            y++;
            p+=dT;
        }
        else
        {
            putpixel(x,y,RED);
            p+=dS;
        }
            x++;
    }
}
int main()
{
int x0,y0,x1,y1,i,x,y;
cout<<"Enter first coordinate"<<endl;
cin>>x0>>y0;
cout<<"Enter the second coordinate"<<endl;
cin>>x1>>y1;
int gr=DETECT,gm;
initgraph(&gr,&gm,"C:\\TURBOC3\\BGI");
drawline(x0,y0,x1,y1);
getch();
closegraph();
return 0;
}
