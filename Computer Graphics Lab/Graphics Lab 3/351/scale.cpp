#include <iostream>
#include <conio.h>
#include <graphics.h>
using namespace std;
int main()
{
    int gd=DETECT,gm;
    float x1,y1,x2,y2,sx,sy,s;
    initgraph(&gd,&gm,"C:\\Tc\\BGI");
    cout<<"SCALING OF A LINE\n";
    cout<<"Enter the first coordinate of a line:";
    cin>>x1>>y1;
    cout<<"Enter the second coordinate of a line:";
    cin>>x2>>y2;
    line(x1,y1,x2,y2);
    cout<<"Enter the scaling factor:";
    cin>>s;
    sx=s/100,sy=s/100;
    setcolor(RED);
    x1=x1*sx;
    y1=y1*sy;
    x2=x2*sx;
    y2=y2*sy;
    line(x1,y1,x2,y2);
    getch();
    closegraph();
}

