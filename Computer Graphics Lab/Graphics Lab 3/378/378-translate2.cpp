#include<bits/stdc++.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
using namespace std;
#define PI 3.14159265

int main() {
    int gd, gm;
    gd = DETECT;
    initgraph(&gd, &gm, "");

    int x1 = 0, y1 = 0;
    int x2 = 100, y2 = 50;


    setcolor(YELLOW);
    line(x1, y1, x2, y2);


    int x1_new = x1+75;
    int y1_new = y1+0;
    int x2_new = x2+75;
    int y2_new = y2+0;


    setcolor(WHITE);
    line(x1_new, y1_new, x2_new, y2_new);

    getch();
    closegraph();
    return 0;
}


