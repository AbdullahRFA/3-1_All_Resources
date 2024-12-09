#include <graphics.h>
#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

void kite()
{
    line(200, 200, 300, 100);
    line(300, 100, 400, 200);
    line(400, 200, 300, 300);
    line(300, 100, 300, 300);
    line(300,300,200,200);
    arc(300, 300, 45, 135, 140);



    line(300, 300, 250, 350);
    line(250, 350, 350, 350);
    line(300, 300, 350, 350);

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
