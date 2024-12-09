
#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

int main()
{
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"");
    int x1=0,y1=0,x2=100,y2=50;
    line(x1,y1,x2,y2);
    float angle = 30* 3.14158/180;
    int x1_rotated = (x1)*cos(angle)-(y1)*sin(angle);
    int y1_rotated =(x1)*sin(angle)+(y1)*cos(angle);
    int x2_rotated = (x2)*cos(angle)-(y2)*sin(angle);
    int y2_rotated = (x2)*sin(angle)+(y2)*cos(angle);

    setcolor(GREEN);
    line(x1_rotated,y1_rotated,x2_rotated,y2_rotated);

    int x1_scaled = x1 * 0.5;
    int y1_scaled = y1 * 0.5;
    int x2_scaled = x2 * 0.5;
    int y2_scaled = y2 * 0.5;

    setcolor(BLUE);
    line(x1_scaled,y1_scaled,x2_scaled,y2_scaled);

    int x1_translated = x1+75;
    int y1_translated = y1;
    int x2_translated = x2+75;
    int y2_translated = y2;
    setcolor(WHITE);
    line(x1_translated,y1_translated,x2_translated,y2_translated);
    getch();
    closegraph();
}
