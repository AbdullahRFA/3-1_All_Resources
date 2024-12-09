

#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;
void line_bressenham(int x1,int y1,int x2,int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x, y;

    if (x1 < x2) {
        x = x1;
        y = y1;
    } else {
        x = x2;
        y = y2;
        x2 = x1;
        y2 = y1;
    }

    int p = 2 * dy - dx;
    putpixel(x, y, WHITE);

    while (x < x2) {
        x++;
        if (p < 0) {
            p += 2 * dy;
        } else {
            y++;
            p += 2 * (dy - dx);
        }
        putpixel(x, y, BLACK);
    }
}
void kite()
{
    line(200, 200, 300, 100);
    line(300, 100, 400, 200);
    line(400, 200, 300, 300);
    line(300, 100, 300, 300);
    line(300,300,200,200);

    //arc(300, 300, 45, 135, 140);
    setfillstyle(SOLID_FILL, 12);

    floodfill(301, 105, WHITE);
    setfillstyle(SOLID_FILL, 12);

    floodfill(299, 105, WHITE);
    setfillstyle(SOLID_FILL, WHITE);

    floodfill(299, 275, WHITE);
    setfillstyle(SOLID_FILL, WHITE);

    floodfill(301, 275, WHITE);
    line(300, 300, 250, 350);
    line(250, 350, 350, 350);
    line(300, 300, 350, 350);
//    line_bressenham(300,300,250,350);
//    line_bressenham(250,350,350,350);
//    line_bressenham(300,300,350,350);
    setfillstyle(SOLID_FILL, WHITE);

    floodfill(300, 310, WHITE);
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    kite();

    getch();
    closegraph();

    return 0;
}
