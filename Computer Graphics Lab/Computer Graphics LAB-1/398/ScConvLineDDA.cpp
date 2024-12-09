#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main()
{
    float x1,y1,x2,y2;
    cout<<"Enter starting point (x,y) = ";
    cin>>x1>>y1;
    cout<<"Enter Ending point (x,y) = ";
    cin>>x2>>y2;

    int dx = x2-x1;
    int dy = y2-y1;

    int steps, k;
    float x_inc, y_inc;
    float x = x1;
    float y = y1;

    if(abs(dx)>abs(dy))
        steps=abs(dx);
    else
        steps=abs(dy);

    x_inc = dx/ (float)steps;
    y_inc = dy/ (float)steps;

    int gd = DETECT, gm;

    initgraph(&gd, &gm,"");

    putpixel(x,y,WHITE);

    for(k=0;k<steps;k++)
    {
        x=x+x_inc;
        y=y+y_inc;
        putpixel(floor(x),floor(y),WHITE);
    }
    getch();
    closegraph();


}
