#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

void drawkite(int x, int y, int width, int height)
{
    int x1 = x - width/2;
    int y1 = y;
    int x2 = x;
    int y2 = y- height/2;
    int x3 = x+ width/2;
    int y3 = y;
    int x4 = x;
    int y4 = y+ height/2;

    line(x1,y1,x2,y2);
    line(x2,y2,x3,y3);
    line(x3,y3,x4,y4);
    line(x4,y4,x1,y1);
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd,&gm,"");
    int width = 800;
    int height = 600;
    int x = width/2;
    int y = height/2;
    int kitewidth = 200;
    int kiteheight = 300;

    drawkite(x,y,kitewidth,kiteheight);

    getch();
    closegraph();
}
