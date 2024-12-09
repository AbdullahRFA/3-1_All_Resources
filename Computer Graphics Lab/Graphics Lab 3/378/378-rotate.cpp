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


    float angle = 30.0;
    float radians = (angle * PI) / 180.0;


    int x1_rotated = round(x1 * cos(radians) - y1 * sin(radians));

    int y1_rotated = round(x1 * sin(radians) + y1 * cos(radians));

    int x2_rotated = round(x2 * cos(radians) - y2 * sin(radians));

    int y2_rotated = round(x2 * sin(radians) + y2 * cos(radians));


    setcolor(WHITE);
    line(x1_rotated, y1_rotated, x2_rotated, y2_rotated);

    getch();
    closegraph();
    return 0;
}

