#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

void drawCircle(int xcen, int ycen, int r)
{
    int x=0;
    int y= r;
    int d= 3- 2*r;

    while(x<=y)
    {
        putpixel(xcen+x, ycen+y, WHITE);
        putpixel(xcen-x, ycen+y, WHITE);
        putpixel(xcen+x, ycen-y, WHITE);
        putpixel(xcen-x, ycen-y, WHITE);
        putpixel(xcen+y, ycen+x, WHITE);
        putpixel(xcen-y, ycen+x, WHITE);
        putpixel(xcen+y, ycen-x, WHITE);
        putpixel(xcen-y, ycen-x, WHITE);
        if(d<0) d+=4 *x+6;
        else
        {
            d+=4*(x-y)+10;
            y--;
        }
        x++;
    }
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");
    int xcen,ycen,r;
    cout<<"center(x,y) : ";
    cin>>xcen>>ycen;
    cout<<"radius : ";
    cin>>r;
    //cout<<"line coordinates: "<<endl;
    //drawLine(x0,y0,x1,y1);
    drawCircle(xcen,ycen,r);
    delay(50000000);
    closegraph();
    return 0;
}
