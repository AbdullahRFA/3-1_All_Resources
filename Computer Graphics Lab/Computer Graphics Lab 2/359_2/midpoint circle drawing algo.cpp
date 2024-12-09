#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    float x,y,xc,yc,r;
    int gd=DETECT;
    int gm;
    initgraph(&gd,&gm,"");
    cout<<"Enter center of circle : ";
    cin>>xc>>yc;
    cout<< "Enter radius of circle : ";
    cin>>r;
    x=0;
    y=r;
    int d=1-r;
    do {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);

        if (d < 0)
            d += 2 * x + 3;
        else {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    } while (x <= y);

    delay(5000);
    getch();
    closegraph();




}
