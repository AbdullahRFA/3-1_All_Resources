#include<iostream>
#include<math.h>
#include<graphics.h>

using namespace std;
void drawLine(int x1,int y1,int x2,int y2)
{
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

    putpixel(x,y,WHITE);

    for(k=0; k<steps; k++)
    {
        x=x+x_inc;
        y=y+y_inc;
        putpixel(floor(x),floor(y),WHITE);
    }
    getch();
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    drawLine(200, 200, 300, 100);
    drawLine(300, 100, 400, 200);
    drawLine(400, 200, 300, 500);
    drawLine(300,500,200,200);
//    drawLine(300, 300, 250, 350);
//    drawLine(250, 350, 350, 350);
//    drawLine(300, 300, 350, 350);
//    drawLine(200,200,400,200);
//    drawLine(300,100,300,300);
    delay(5000);
}
