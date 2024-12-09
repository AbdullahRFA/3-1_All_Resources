#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int xmin, xmax, ymin, ymax;

// Function for Liang-Barsky line clipping
void liangBarskyClipping(int x1, int y1, int x2, int y2)
{
    //setcolor(RED);
    int dx = x2 - x1;
    int dy = y2 - y1;

    float p[4] = {-dx, dx, -dy, dy};
    float q[4] = {x1 - xmin, xmax - x1, y1 - ymin, ymax - y1};

    float t1 = 0, t2 = 1;

    for (int i = 0; i < 4; i++) {
        float temp = q[i] / p[i];

        if (p[i] < 0) {
            if (t1 <= temp)
                t1 = temp;
        } else {
            if (t2 > temp)
                t2 = temp;
        }
    }

    if (t1 < t2) {
        int xx1 = x1 + t1 * p[1];
        int xx2 = x1 + t2 * p[1];
        int yy1 = y1 + t1 * p[3];
        int yy2 = y1 + t2 * p[3];
        //setcolor(RED);
        line(xx1, yy1, xx2, yy2);
        //setcolor(RED);
    }
    //setcolor(RED);
}

int main() {
    int i, gd = DETECT, gm;

    int lines[5][4] = {
        {100, 120, 300, 300},
        {50, 200, 400, 200},
        {150, 50, 150, 400},
        {50, 50, 350, 350},
        {200, 150, 200, 400}
        /*{+4*60, 2*60, +1*60, 7*60},
        {+1*60, 5*60, 3*60, 8*60},
        {+2*60, 3*60, 1*60, 2*60},
        {1*60, +2*60, 3*60, 3*60},
        {+4*60, 7*60, +2*60, 10*60}*/
    };

    xmin = 100;
    ymin = 100;
    xmax = 250;
    ymax = 250;

    initgraph(&gd, &gm, NULL);
    rectangle(xmin, ymin, xmax, ymax);

    for (i = 0; i < 5; i++) {
        line(lines[i][0], lines[i][1], lines[i][2], lines[i][3]);
        delay(1000);
        //cleardevice();
        //rectangle(xmin, ymin, xmax, ymax);
        liangBarskyClipping(lines[i][0], lines[i][1], lines[i][2], lines[i][3]);
        //delay(1000);
        //cleardevice();
        //rectangle(xmin, ymin, xmax, ymax);
    }

    delay(2000000000000);
    getch();
    closegraph();
    return 0;
}
