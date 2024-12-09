#include<bits/stdc++.h>
#include<graphics.h>
#include<dos.h>
using namespace std;
int main()
{
    int gd=DETECT;
    int gm;
    int x1,y1,x2,y2,dx,dy,steps,x_inc,y_inc;
    initgraph(&gd,&gm," ");
    cout<< "Enter starting co-ordinates: ";
    cin>>x1>>y1;
    cout<< "Enter ending  co-ordinates: ";
    cin>>x2>>y2;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>abs(dy))
    {
      steps=abs(dx);
    }
    else
        steps=abs(dy);
    x_inc=dx/steps;
    y_inc=dy/steps;
    for(int i=0;i<steps;i++)
    {
        putpixel(x1,y1,2.5);
        x1=x1+x_inc;
        y1=y1+y_inc;
    }
    getch();
    closegraph();
}

