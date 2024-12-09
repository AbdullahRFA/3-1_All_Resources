#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

int main()
{
    int h,k,r;
    cout<<"INPUT Coordinate of the center = ";
    cin>>h>>k;
    cout<<"INPUT Radius of the circle = ";
    cin>>r;

    int gd = DETECT,gm;
    initgraph(&gd,&gm,"");
    int x =0,y=r;
    int P = 3-2*r;

    while(x<=y)
    {
        putpixel(h+x,k+y,WHITE);
        putpixel(h-x,k+y,WHITE);
        putpixel(h+x,k-y,WHITE);
        putpixel(h-x,k-y,WHITE);

        putpixel(h+y,k+x,WHITE);
        putpixel(h-y,k+x,WHITE);
        putpixel(h+y,k-x,WHITE);
        putpixel(h-y,k-x,WHITE);

        if(P<0)
        {
            x++;
            P=P+4*x+6;
        }
        else
        {
            x++;
            y--;
            P=P+4*(x-y)+10;
        }
    }
    getch();
    closegraph();
}
