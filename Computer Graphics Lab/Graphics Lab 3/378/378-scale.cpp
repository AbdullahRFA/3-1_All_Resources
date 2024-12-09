#include<bits/stdc++.h>
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
using namespace std;

int main() {
    int gd, gm;
    gd = DETECT;
    initgraph(&gd, &gm, "");

    int x1 = 0, y1 = 0;
    int x2 = 100, y2 = 50;

    //setcolor(YELLOW);
    //line(x1, y1, x2, y2);

    int dx = x2 - x1;
    int dy = y2 - y1;
    int originalLength = sqrt(dx * dx + dy * dy);


    float scale = 0.5;
    int scaledLength = originalLength * scale;


    int x1_scaled = x1;
    int y1_scaled = y1;
    int x2_scaled = x1 + dx * scaledLength / originalLength;
    int y2_scaled = y1 + dy * scaledLength / originalLength;

    setcolor(WHITE);
    line(x1_scaled, y1_scaled, x2_scaled, y2_scaled);

    getch();
    closegraph();
    return 0;
}

