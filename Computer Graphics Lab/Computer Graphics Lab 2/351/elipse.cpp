#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>
using namespace std;
void put4pixel(int x,int y,int h,int k)
{
    putpixel(x+h,y+k,8);
    putpixel(x+h,-y+k,8);
    putpixel(-x+h,y+k,8);
    putpixel(-x+h,-y+k,8);
}
int main()
{
    int x,y,x1,y1,a,b,h,k,theta;
    float p=3.14159/180;
    cout<<"\nenter the x and y coordinates: ";
    cin>>h>>k;
    cout<<"\nenter the major radius: ";
    cin>>a;
    cout<<"\nenter the minor radius: ";
    cin>>b;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    setbkcolor(WHITE);
    for(theta=0; theta<=90; theta++)
    {
        x1=a*cos(theta*p);
        y1=b*sin(theta*p);
        x=int(x1+0.5);
        y=int(y1+0.5);
        put4pixel(x,y,h,k);
    }
    setcolor(8);
    getch();
    closegraph();
}

