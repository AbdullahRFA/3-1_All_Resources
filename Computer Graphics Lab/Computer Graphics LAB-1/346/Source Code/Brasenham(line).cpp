#include<bits/stdc++.h>
#include<graphics.h>
#include<dos.h>
using namespace std;
int main()
{
    int gd=DETECT;
    int gm,p;
    int x1,y1,x2,y2,dx,dy,steps;
    initgraph(&gd,&gm,"");
    cout<< "Enter starting co-ordinates: ";
    cin>>x1>>y1;
    cout<< "Enter ending  co-ordinates: ";
    cin>>x2>>y2;
    dx=x2-x1;
    dy=y2-y1;
    p=2*dy-dx;
    putpixel(x1,y1,3);
    for(int i=0;i<dx;i++)
    {
        if(p<0)
        {
            x1++;
            p=p+2*dy;
        }
        else
        {
            x1++;
            y1++;
            p=p+2*dy-2*dx;
        }
        putpixel(x1,y1,3);
          delay(50);
    }


    getch();
    closegraph();
}
