#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;

int main()
{
    int x,y,r,p,x1,y1;
    cout<<"Enter Radius of the circle = ";
    cin>>r;
    cout<<"Enter the Center of the circle (x,y) = ";
    cin>>x>>y;

    x1=0,y1=r;
    p=1-r;
    int gd = DETECT, gm;
    initgraph(&gd,&gm,"");
    while(x1<=y1)
    {
        putpixel(x+x1,y+y1,WHITE);
        putpixel(x-x1,y+y1,WHITE);
        putpixel(x+x1,y-y1,WHITE);
        putpixel(x-x1,y-y1,WHITE);

        putpixel(x+y1,y+x1,WHITE);
        putpixel(x-y1,y+x1,WHITE);
        putpixel(x+y1,y-x1,WHITE);
        putpixel(x-y1,y-x1,WHITE);

        if(p<0)
        {
            p=p+2*x1+3;
        }
        else
        {
            p=p+2*(x1-y1)+5;
            y1--;
        }
        x1++;
    }
    getch();
    return 0;
}
