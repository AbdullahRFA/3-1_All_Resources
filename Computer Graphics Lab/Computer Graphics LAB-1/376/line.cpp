#include <bits/stdc++.h>
using namespace std;
#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int x1 = 100; // x-coordinate of the starting point
    int y1 = 100; // y-coordinate of the starting point
    int x2 = 300; // x-coordinate of the ending point
    int y2 = 200; // y-coordinate of the ending point

    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps =abs(dy);

    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(x, y, WHITE);
        x += xIncrement;
        y += yIncrement;
    }

//    delay(5000); // Pause for 5 seconds
    getch();
    closegraph();
    return 0;
}
