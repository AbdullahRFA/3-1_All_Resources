#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd, &gm, "c:\\TC\\BGI");

    float x=30,y=50;

    putpixel(x,y,GREEN);
    getch();

    closegraph();

    return 0;
}
