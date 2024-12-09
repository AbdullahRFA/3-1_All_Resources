#include <iostream>
#include <graphics.h>
using namespace std;

struct lines {
    int x1, y1, x2, y2;
};

int xmin, xmax, ymin, ymax;

int sign(int x) {
    if (x > 0)
        return 1;
    else
        return 0;
}

void clip(struct lines mylines) {
    // ... (rest of the clip function remains the same)
    // Modify the code to draw using graphics.h
    setcolor(GREEN);
    line(mylines.x1, mylines.y1, mylines.x2, mylines.y2);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");  // Set your BGI path

    xmin = -30 + 50;
    xmax = 10 + 50;
    ymin = 20 + 50;
    ymax = 100 + 50;

    rectangle(xmin, ymin, xmax, ymax);

    struct lines mylines[5];

    mylines[0].x1 = -40 + 50;
    mylines[0].y1 = 70 + 50;
    mylines[0].x2 = -20 + 50;
    mylines[0].y2 = 100 + 50;

    mylines[1].x1 = -40 + 50;
    mylines[1].y1 = 20 + 50;
    mylines[1].x2 = -10 + 50;
    mylines[1].y2 = 70 + 50;

    mylines[2].x1 = -10 + 50;
    mylines[2].y1 = 50 + 50;
    mylines[2].x2 = 30 + 50;
    mylines[2].y2 = 80 + 50;

    mylines[3].x1 = -20 + 50;
    mylines[3].y1 = 30 + 50;
    mylines[3].x2 = 10 + 50;
    mylines[3].y2 = 20 + 50;

    mylines[4].x1 = 10 + 50;
    mylines[4].y1 = -20 + 50;
    mylines[4].x2 = 30 + 50;
    mylines[4].y2 = 30 + 50;

    for (int i = 0; i < 5; i++) {
        line(mylines[i].x1, mylines[i].y1, mylines[i].x2, mylines[i].y2);
        delay(1000);
    }

    for (int i = 0; i < 5; i++) {
        clip(mylines[i]);
        delay(1000);
    }

    delay(400000);
    closegraph();
    return 0;
}

